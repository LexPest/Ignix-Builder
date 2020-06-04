//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
#define NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H

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
#include <yaml-cpp/node/node.h>
#include <nb/consts/nbProjectStructConsts.h>
#include <boost/pointer_cast.hpp>
#include <nb/logic/dependencies/gen/nb_g_ResolveDependency.h>
#include <nb/logic/dependencies/gen/nb_g_IsSatisfied.h>
#include <nb/logic/dependencies/gen/nb_g_SetDepParam.h>
#include <set>
#include <exception>

namespace nerp {

    // Group based, grouped by dependency parameters influence
    // template<typename BASE_DEP_FOR_ELEM_T, typename GROUP_KIND_DEP_TARGET_PARAM_ENUM_T>
    // using MConcreteTargetParamChangingGroupsForElement_t = std::unordered_map<GROUP_KIND_DEP_TARGET_PARAM_ENUM_T, std::list<BASE_DEP_FOR_ELEM_T>>;


    // first of all, what types do we need and what types do we have
    // ByDepParam - dependency by dependent param
    // DepParam - target param to change depending on dependency
    // SearchCriteriaForDepResolve - what criteria should we use to find the dependency
    // DepTarget - target object type, on which dependency is based

    // = = = = = = = = = = = = = =
    // Test templates usage


    class nbProjectDependenciesResolver_Example {

        void Example() {
            // ResolvedElementDependency<nbFeature> r = ResolvedElementDependency<nbFeature>(nullptr);
            // isSatisfied_impl<nbFeature, nbEDepGroupKind_ByDepParam, nbEDepGroupKind_ByDepParam::Availability>::_invoke(r);
//           DependenciesForConcreteElement e = DependenciesForConcreteElement();
//           const std::tuple<std::list<std::shared_ptr<nbFeature>>, std::string> tuple;
//           e.addDependency<
//           nbEDepGroupKind_ByDepParam::Availability,
//                    nbEDepGroupKind_DepParam::SetBoolActive,
//                    nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s,
//                   std::tuple<std::list<std::shared_ptr<nbFeature>>, std::string>, nbFeature>(tuple);
//
//           std::shared_ptr<UnresolvedDependency> unresDep = e.UnresolvedDependencies.front();
//           e.resolveAllDependencies();
        }
    };

#include "nbTypeAliasesInclude.h"


    class nbProjectDependenciesResolver;

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
            ElementDependencyHolderGroup &getHolderGroup(nbEDepGroupKind_DepParam parDepParam);

        public:
            template<typename CAST_T>
            std::shared_ptr<CAST_T> get_targetElem() {
                return boost::reinterpret_pointer_cast<CAST_T>(targetElem);
            }

            std::shared_ptr<boost::any> get_targetElem() {
                return targetElem;
            }

            void addDependency(const DependencyAddingParams &parAddParams);

            void resolveAllDependencies(nbProjectDependenciesResolver &refProjectDepResolver);
            void firstValEvaluate();
            //void bindToDependencyPropertiesChangeEvents(){}


            bool isFirstTimeValueEvaluated() const;

            DepElement(const std::shared_ptr<boost::any> &targetElem,
                       nbProjectDependenciesResolver &refProjectDepResolver) : targetElem(targetElem),
                                                                               refProjectDepResolver(
                                                                                       refProjectDepResolver) {}

        private:
            std::shared_ptr<boost::any> targetElem;
            std::map<nbEDepGroupKind_DepParam, ElementDependencyHolderGroup> containedDependencies_By_DepParamGroups;
            nbProjectDependenciesResolver &refProjectDepResolver;

            bool FirstTimeValueEvaluated = false;
            bool BindedToDependencyPropertiesChangeEvents = false;
        };

        class ElementDependencyHolder {
        public:
            bool get_isResolved() { return isResolved; }

            bool resolveDependency(nbProjectDependenciesResolver &parProjectDepManager);

            void checkFirstTimeEvaluatedForResolvedDepTarget(){
                if (ResolvedDepTarget == nullptr){
                    throw std::runtime_error("Check First Time Evaluated cannot be performed for unresolved dep target");
                }

                if (!ResolvedDepTarget->isFirstTimeValueEvaluated()){
                    ResolvedDepTarget->firstValEvaluate();
                }
            }

            bool isSatisfied() const {
                return gen_IsSatisfied.isSatisfied(ResolvedDepTarget->get_targetElem());
            }

           // void bindCheckFuncForResolvedDepTarget(std::shared_ptr<boost::any> parTargetElemForSettingValue){
             //
            //}
            boost::any getTargetDependentPropertyForBinding(){

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
            void resolveAll(nbProjectDependenciesResolver &refProjectDepResolver) {
                bool isResolvedTmp = true;
                for (const auto &dep : Dependencies) {
                    if (!dep->resolveDependency(refProjectDepResolver)) {
                        isResolvedTmp = false;
                    }
                }
                isResolved = isResolvedTmp;
            }

            void evaluateFirstTime(std::shared_ptr<boost::any> parTargetElemForSettingValue){
                if (!isResolved){
                    throw std::runtime_error("EvaluateFirstTime cannot be performed if deps are not resolved!");
                }

                for (auto& dep : Dependencies){
                    dep->checkFirstTimeEvaluatedForResolvedDepTarget();
                }

                setDepParamBasedOnDepSatisfaction(parTargetElemForSettingValue);
            }

            void bindGroupToDependencyPropertiesChangeEvents(std::shared_ptr<boost::any> parTargetElemForSettingValue){
                for (auto& dep : Dependencies){

                }
            }



        private:
            std::list<std::shared_ptr<ElementDependencyHolder>> Dependencies;
            const g_SetDepParam &gen_SetDepParam;
            bool isResolved = false;


            void setDepParamBasedOnDepSatisfaction(std::shared_ptr<boost::any> parTargetElemForSettingValue){
                bool _isSatisfied = true;
                for (auto& dep : Dependencies){
                    if (!dep->isSatisfied()){
                        _isSatisfied = false;
                        break;
                    }
                }

                gen_SetDepParam.setDepParam(parTargetElemForSettingValue, _isSatisfied);
            }
        };


    }

    class nbProjectDependenciesResolver {
    private:
        std::map<std::shared_ptr<boost::any>, std::shared_ptr<DepElement>> ProjectDepElementsContainer;


    public:
        //void addElementDependencies()
        //

        std::shared_ptr<DepElement> getManagedDepElement_AddIfNotFound(std::shared_ptr<boost::any> parTargetElem) {
            auto foundExisting = ProjectDepElementsContainer.find(parTargetElem);
            if (foundExisting == ProjectDepElementsContainer.end()) {
                std::shared_ptr<DepElement> newDepElem = std::make_shared<DepElement>(parTargetElem, *this);
                return newDepElem;
            }
            return foundExisting->second;
        }
    };
}


#endif //NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
