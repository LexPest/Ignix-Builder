//
// Created by Alexey Mihailov on 17/05/2020.
//

#include "nbRecipeDependenciesResolver.h"


nerp::ElementDependencyHolderGroup &nerp::DepElement::getHolderGroup(nerp::nbEDepGroupKind_DepParam parDepParam)
    {
        auto foundExisting = containedDependencies_By_DepParamGroups.find(parDepParam);
        if (foundExisting == containedDependencies_By_DepParamGroups.end()){
            containedDependencies_By_DepParamGroups.insert(std::pair<nbEDepGroupKind_DepParam, ElementDependencyHolderGroup>
                    (parDepParam, ElementDependencyHolderGroup(deps::get_gen_SetDepParam(parDepParam)) ));
        }
        auto& foundElem = containedDependencies_By_DepParamGroups.at(parDepParam);
        return foundElem;
    }

void nerp::DepElement::addDependency(const nerp::DependencyAddingParams &parAddParams) {
    if (FirstTimeValueEvaluated) {
        throw std::runtime_error("Dependency can't be added after others' first values were evaluated");
    }
    ElementDependencyHolderGroup& targetGroup = getHolderGroup(parAddParams.eDepParam);
    targetGroup.addDependency(parAddParams);
}

void nerp::DepElement::resolveAllDependencies(nbRecipeDependenciesResolver &parProjectDepResolver) {
    for (auto & containedDependencies_By_DepParamGroup : containedDependencies_By_DepParamGroups){
        containedDependencies_By_DepParamGroup.second.resolveAll(parProjectDepResolver);
    }
}

void nerp::DepElement::firstValEvaluate() {
    if (FirstTimeValueEvaluated){
        throw std::runtime_error("First Val Evaluate can be performed only once! Possible circular dependency.");
    }

    FirstTimeValueEvaluated = true;

    for (auto & containedDependencies_By_DepParamGroup : containedDependencies_By_DepParamGroups){
        auto& targetGroup = containedDependencies_By_DepParamGroup.second;
        //bool isSatisfied = false;
        targetGroup.evaluateFirstTime(targetElem);
    }
}

bool nerp::DepElement::isFirstTimeValueEvaluated() const {
    return FirstTimeValueEvaluated;
}

void nerp::DepElement::bindToDependencyPropertiesChangeEvents() {
    if (BindedToDependencyPropertiesChangeEvents) {
        throw std::runtime_error("Cannot bind to dependencies properties change events second time!");
    }

    BindedToDependencyPropertiesChangeEvents = true;

    for (auto &containedDependencies_By_DepParamGroup : containedDependencies_By_DepParamGroups) {
        std::unique_ptr<std::list<std::weak_ptr<InvokeFunctionHandlerMeta_NoArg>>> bindHandlers =
        containedDependencies_By_DepParamGroup.second.bindGroupToDependencyPropertiesChangeEvents(targetElem);

        std::copy(bindHandlers->begin(), bindHandlers->end(), std::back_inserter(RegisteredInvokeFunctionHanldersForBinding));
    }
}

nerp::DependencyAddingParams::DependencyAddingParams(const std::shared_ptr<boost::any> &targetElem,
                                                     const nerp::nbEDepGroupKind_SearchCriteriaForDepResolve eSearchCriteria,
                                                     const nerp::nbEDepGroupKind_ByDepParam eByDepParam,
                                                     const nerp::nbEDepGroupKind_DepParam eDepParam,
                                                     const nerp::ResolveParamsTuple_T &resolveParamsTuple) : targetElem(
        targetElem), eSearchCriteria(eSearchCriteria), eByDepParam(eByDepParam), eDepParam(eDepParam),
                                                                                                             resolveParamsTuple(
                                                                                                                     resolveParamsTuple) {}

bool nerp::ElementDependencyHolder::resolveDependency(nerp::nbRecipeDependenciesResolver &parProjectDepManager) {
    auto tmpResolvedDepTarget = gen_ResolveDependency.resolve(ResolveParamsTuple);
    if (tmpResolvedDepTarget != nullptr) {
        isResolved = true;
        ResolvedDepTarget = parProjectDepManager.getManagedDepElement_AddIfNotFound(tmpResolvedDepTarget);
    }
    return isResolved;
}

void nerp::nbRecipeDependenciesResolver::addElementDependency(const nerp::DependencyAddingParams &parAddParams) {
    auto managedDepElement = getManagedDepElement_AddIfNotFound(parAddParams.targetElem);
    managedDepElement->addDependency(parAddParams);
}
