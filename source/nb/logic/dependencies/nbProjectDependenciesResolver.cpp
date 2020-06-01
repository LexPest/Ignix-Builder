//
// Created by Alexey Mihailov on 17/05/2020.
//

#include "nbProjectDependenciesResolver.h"


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

void nerp::DepElement::resolveAllDependencies(nbProjectDependenciesResolver &refProjectDepResolver) {
    for (std::map<nbEDepGroupKind_DepParam, ElementDependencyHolderGroup>::iterator it = containedDependencies_By_DepParamGroups.begin();
         it != containedDependencies_By_DepParamGroups.end(); it++){
        it->second.resolveAll(refProjectDepResolver);
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

bool nerp::ElementDependencyHolder::resolveDependency(nerp::nbProjectDependenciesResolver &parProjectDepManager) {
    auto tmpResolvedDepTarget = gen_ResolveDependency.resolve(ResolveParamsTuple);
    if (tmpResolvedDepTarget != nullptr) {
        isResolved = true;
        ResolvedDepTarget = parProjectDepManager.getManagedDepElement_AddIfNotFound(tmpResolvedDepTarget);
    }
    return isResolved;
}
