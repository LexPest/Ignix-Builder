//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBRECIPEDEPENDENCIESRESOLVER_H
#define NERP_BUILDER_WX_NBRECIPEDEPENDENCIESRESOLVER_H

#include <list>
#include <memory>
#include <map>
#include <unordered_map>
#include <utility>
#include <nb/data/props/nbIBoolValProperty.h>
#include <tuple>
#include <boost/any.hpp>
#include <nb/data/dependencies/nbEDepGroupKind_ByDepParam.h>
#include <nb/data/dependencies/nbEDepGroupKind_DepParam.h>
#include <nb/data/dependencies/nbEDepGroupKind_SearchCriteriaForDepResolve.h>
#include <nb/data/features/nbFeature.h>
#include <nb/consts/nbProjectStructConsts.h>
#include <boost/pointer_cast.hpp>
#include <nb/logic/dependencies/gen/nb_g_ResolveDependency.h>
#include <nb/logic/dependencies/gen/nb_g_IsSatisfied.h>
#include <nb/logic/dependencies/gen/nb_g_SetDepParam.h>
#include <set>
#include <exception>
#include <iterator>
#include <algorithm>

namespace nerp {

    // Group based, grouped by dependency parameters influence
    // template<typename BASE_DEP_FOR_ELEM_T, typename GROUP_KIND_DEP_TARGET_PARAM_ENUM_T>
    // using MConcreteTargetParamChangingGroupsForElement_t = std::unordered_map<GROUP_KIND_DEP_TARGET_PARAM_ENUM_T, std::list<BASE_DEP_FOR_ELEM_T>>;


    // first of all, what types do we need and what types do we have
    // ByDepParam - dependency by dependent param
    // DepParam - target param to change depending on dependency
    // SearchCriteriaForDepResolve - what criteria should we use to find the dependency
    // DepTarget - target object type, on which dependency is based


#include "nbTypeAliasesInclude.h"


    class nbRecipeDependenciesResolver;

    namespace {

        struct DependencyAddingParams {
            const std::shared_ptr<boost::any> &targetElem;
            const nbEDepGroupKind_SearchCriteriaForDepResolve eSearchCriteria;
            const nbEDepGroupKind_ByDepParam eByDepParam;
            const nbEDepGroupKind_DepParam eDepParam;
            const ResolveParamsTuple_T &resolveParamsTuple;

            DependencyAddingParams(const std::shared_ptr<boost::any> &targetElem,
                                   const nbEDepGroupKind_SearchCriteriaForDepResolve eSearchCriteria,
                                   const nbEDepGroupKind_ByDepParam eByDepParam,
                                   const nbEDepGroupKind_DepParam eDepParam,
                                   const ResolveParamsTuple_T &resolveParamsTuple);
        };

        class ElementDependencyHolderGroup;

        class DepElement {
        private:
            inline ElementDependencyHolderGroup &getHolderGroup(nbEDepGroupKind_DepParam parDepParam);

        public:
            template<typename CAST_T>
            inline std::shared_ptr<CAST_T> get_targetElem() {
                return boost::reinterpret_pointer_cast<CAST_T>(targetElem);
            }

            inline std::shared_ptr<boost::any> get_targetElem() {
                return targetElem;
            }

            void addDependency(const DependencyAddingParams &parAddParams);

            void resolveAllDependencies(nbRecipeDependenciesResolver &parProjectDepResolver);

            void firstValEvaluate();

            void bindToDependencyPropertiesChangeEvents();


            bool isFirstTimeValueEvaluated() const;

            DepElement(const std::shared_ptr<boost::any> &targetElem,
                       nbRecipeDependenciesResolver &refProjectDepResolver) : targetElem(targetElem),
                                                                              refProjectDepResolver(
                                                                                       refProjectDepResolver) {}

        private:
            std::shared_ptr<boost::any> targetElem;
            std::map<nbEDepGroupKind_DepParam, ElementDependencyHolderGroup> containedDependencies_By_DepParamGroups;
            nbRecipeDependenciesResolver &refProjectDepResolver;

            bool FirstTimeValueEvaluated = false;
            bool BindedToDependencyPropertiesChangeEvents = false;

            std::list<std::weak_ptr<InvokeFunctionHandlerMeta_NoArg>> RegisteredInvokeFunctionHanldersForBinding;
        };


        class ElementDependencyHolder {
        public:
            bool get_isResolved() { return isResolved; }

            bool resolveDependency(nbRecipeDependenciesResolver &parProjectDepManager);

            void checkFirstTimeEvaluatedForResolvedDepTarget() {
                if (ResolvedDepTarget == nullptr) {
                    throw std::runtime_error(
                            "Check First Time Evaluated cannot be performed for unresolved dep target");
                }

                if (!ResolvedDepTarget->isFirstTimeValueEvaluated()) {
                    ResolvedDepTarget->firstValEvaluate();
                }
            }

            bool isSatisfied() const {
                return gen_IsSatisfied.isSatisfied(ResolvedDepTarget->get_targetElem());
            }

            std::shared_ptr<InvokeFunctionHandlerMeta_NoArg>
            addBindingCheckFuncForResolvedDepTarget(const std::function<void(void)> &parEvalFunction) {
                return gen_IsSatisfied.addBindingFunctionOnPropChange_NoArg(ResolvedDepTarget->get_targetElem(),
                                                                            parEvalFunction);
            }

            ElementDependencyHolder(const g_ResolveDependency &genResolveDependency,
                                    const g_IsSatisfied &genIsSatisfied, ResolveParamsTuple_T parResolveParamsTuple) :
                    gen_ResolveDependency(genResolveDependency),
                    gen_IsSatisfied(genIsSatisfied), ResolveParamsTuple(std::move(parResolveParamsTuple)) {}


        private:
            bool isResolved = false;
            const g_ResolveDependency &gen_ResolveDependency;
            const g_IsSatisfied &gen_IsSatisfied;

            std::shared_ptr<DepElement> ResolvedDepTarget;

            ResolveParamsTuple_T ResolveParamsTuple;

        };


        class ElementDependencyHolderGroup {
        public:
            ElementDependencyHolderGroup(const g_SetDepParam &parSetDepParamGen)
                    : gen_SetDepParam(parSetDepParamGen) {}

            bool get_isResolved() { return isResolved; }

            void addDependency(const DependencyAddingParams &parAddParams) {
                std::shared_ptr<ElementDependencyHolder> elemDepHolder =
                        std::make_shared<ElementDependencyHolder>(
                                deps::get_gen_DependencyResolver(parAddParams.eSearchCriteria),
                                deps::get_gen_IsSatisfied(parAddParams.eByDepParam),
                                parAddParams.resolveParamsTuple);
                Dependencies.push_back(std::move(elemDepHolder));
            }

            //todo: return errcode if not resolved
            void resolveAll(nbRecipeDependenciesResolver &refProjectDepResolver) {
                bool isResolvedTmp = true;
                for (const auto &dep : Dependencies) {
                    if (!dep->resolveDependency(refProjectDepResolver)) {
                        isResolvedTmp = false;
                    }
                }
                isResolved = isResolvedTmp;
            }

            void evaluateFirstTime(std::shared_ptr<boost::any> parTargetElemForSettingValue) {
                if (!isResolved) {
                    throw std::runtime_error("EvaluateFirstTime cannot be performed if deps are not resolved!");
                }

                for (auto &dep : Dependencies) {
                    dep->checkFirstTimeEvaluatedForResolvedDepTarget();
                }

                setDepParamBasedOnDepSatisfaction(parTargetElemForSettingValue);
            }

            std::unique_ptr<std::list<std::weak_ptr<InvokeFunctionHandlerMeta_NoArg>>>
            bindGroupToDependencyPropertiesChangeEvents(std::shared_ptr<boost::any> parTargetElemForSettingValue) {

                const auto setDepParamInvokationLambda = [this, parTargetElemForSettingValue = parTargetElemForSettingValue]() -> void {
                    setDepParamBasedOnDepSatisfaction(parTargetElemForSettingValue);
                };

                std::unique_ptr<std::list<std::weak_ptr<InvokeFunctionHandlerMeta_NoArg>>> retList = std::make_unique<std::list<std::weak_ptr<InvokeFunctionHandlerMeta_NoArg>>>();

                for (auto &dep : Dependencies) {
                    auto retHandler = dep->addBindingCheckFuncForResolvedDepTarget(setDepParamInvokationLambda);
                    retList->push_back(std::move(retHandler));
                }

                return std::move(retList);
            }


        private:
            std::list<std::shared_ptr<ElementDependencyHolder>> Dependencies;
            const g_SetDepParam &gen_SetDepParam;
            bool isResolved = false;


            void setDepParamBasedOnDepSatisfaction(std::shared_ptr<boost::any> parTargetElemForSettingValue) {
                bool _isSatisfied = true;
                for (auto &dep : Dependencies) {
                    if (!dep->isSatisfied()) {
                        _isSatisfied = false;
                        break;
                    }
                }

                gen_SetDepParam.setDepParam(parTargetElemForSettingValue, _isSatisfied);
            }
        };


    }


    class nbRecipeDependenciesResolver {
    private:
        std::map<std::shared_ptr<boost::any>, std::shared_ptr<DepElement>> ProjectDepElementsContainer;

    public:
        std::shared_ptr<DepElement> getManagedDepElement_AddIfNotFound(std::shared_ptr<boost::any> parTargetElem) {
            auto foundExisting = ProjectDepElementsContainer.find(parTargetElem);
            if (foundExisting == ProjectDepElementsContainer.end()) {
                std::shared_ptr<DepElement> newDepElem = std::make_shared<DepElement>(parTargetElem, *this);
                return newDepElem;
            }
            return foundExisting->second;
        }

        void addElementDependency(const DependencyAddingParams &parAddParams);


        void commitAndSetupProjectDependencies() {
            if (ProjectDepsCommited) {
                throw std::runtime_error("Project dependencies can be committed only once!");
            }

            ProjectDepsCommited = true;

            resolveDependencies();
            evalFirstTimeInitialValues();
            bindToPropertyEventsValChangers();
        }


    private:
        inline void resolveDependencies() {
            for (auto &depElem : ProjectDepElementsContainer) {
                depElem.second->resolveAllDependencies(*this);
            }
        }

        inline void evalFirstTimeInitialValues() {
            for (auto &depElem : ProjectDepElementsContainer) {
                depElem.second->firstValEvaluate();
            }
        }

        inline void bindToPropertyEventsValChangers() {
            for (auto &depElem : ProjectDepElementsContainer) {
                depElem.second->bindToDependencyPropertiesChangeEvents();
            }
        }

        bool ProjectDepsCommited = false;
    };
}


#endif //NERP_BUILDER_WX_NBRECIPEDEPENDENCIESRESOLVER_H
