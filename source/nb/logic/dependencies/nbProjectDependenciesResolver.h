//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
#define NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H

#include <list>
#include <memory>
#include <map>
#include <unordered_map>
#include <nb/data/dependencies/in_recipes/property/nbPDep_AvailableOnNames.h>
#include <nb/data/props/nbIBoolValProperty.h>

namespace nerp {

    // Group based, grouped by dependency parameters influence
    template<typename BASE_DEP_FOR_ELEM_T, typename GROUP_KIND_DEP_TARGET_PARAM_ENUM_T>
    using MConcreteTargetParamChangingGroupsForElement_t = std::unordered_map<GROUP_KIND_DEP_TARGET_PARAM_ENUM_T, std::list<BASE_DEP_FOR_ELEM_T>>;

    // Unresolved dependency, e.g. when we only know the string of the desired dependency
    template<typename DEP_RESOLVING_INPUT_PARAM_S_T>
    class UnresolvedElementDependency{
    public:
        DEP_RESOLVING_INPUT_PARAM_S_T param_s;
        explicit UnresolvedElementDependency(DEP_RESOLVING_INPUT_PARAM_S_T paramS) : param_s(paramS) {}
    };

    template<typename RESOLVED_TARGET_DEP_T>
    class ResolvedElementDependency{
    public:
        std::shared_ptr<RESOLVED_TARGET_DEP_T> target_elem;
        explicit ResolvedElementDependency(const std::shared_ptr<RESOLVED_TARGET_DEP_T> &targetElem) : target_elem(targetElem) {}
    };



    template<typename RESOLVED_TARGET_DEP_T,
            typename DEP_RESOLVING_INPUT_PARAMS_T,
            typename DEP_GROUP_KIND_SEARCH_CRITERIA_T, DEP_GROUP_KIND_SEARCH_CRITERIA_T valSearchCriteria,
            typename DEP_RESOLVING_DATA_T>
    struct resolveDependency_impl {
        static ResolvedElementDependency<RESOLVED_TARGET_DEP_T> _invoke(const UnresolvedElementDependency<DEP_RESOLVING_INPUT_PARAMS_T>& parTargetDependency,
                                                                         DEP_RESOLVING_DATA_T& parResolvingData);
    };

    template<typename RESOLVING_DATA_TARGETS_IN_LIST_T>
    using DEP_RESOLVING_DATA_T_SPEC = std::list<std::shared_ptr<RESOLVING_DATA_TARGETS_IN_LIST_T>>&;

    using DEP_RESOLVING_INPUT_PARAMS_T_SPEC = std::string;
    template<typename RESOLVED_TARGET_DEP_T>
    struct resolveDependency_impl<RESOLVED_TARGET_DEP_T,
            DEP_RESOLVING_INPUT_PARAMS_T_SPEC,
            nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve,
            nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve::ByName_s,
            DEP_RESOLVING_DATA_T_SPEC<RESOLVED_TARGET_DEP_T>>{
        static ResolvedElementDependency<RESOLVED_TARGET_DEP_T> _invoke(const UnresolvedElementDependency<DEP_RESOLVING_INPUT_PARAMS_T_SPEC>& parTargetDependency,
                                                                         DEP_RESOLVING_DATA_T_SPEC<RESOLVED_TARGET_DEP_T> parResolvingData){
            for (size_t i = 0; i < parResolvingData.size(); i++){
                if (parResolvingData[i].CName == parTargetDependency.param_s){
                    return std::move(ResolvedElementDependency<RESOLVED_TARGET_DEP_T>(parResolvingData));
                }
            }

            return nullptr;
        }
    };

    using DEP_RESOLVING_INPUT_PARAMS_T_SPEC = std::string;
    template<typename RESOLVED_TARGET_DEP_T>
    struct resolveDependency_impl<RESOLVED_TARGET_DEP_T,
            DEP_RESOLVING_INPUT_PARAMS_T_SPEC,
            nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve,
            nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve::ByEMacro_s,
            DEP_RESOLVING_DATA_T_SPEC<RESOLVED_TARGET_DEP_T>>{
        static ResolvedElementDependency<RESOLVED_TARGET_DEP_T> _invoke(const UnresolvedElementDependency<DEP_RESOLVING_INPUT_PARAMS_T_SPEC>& parTargetDependency,
                                                                        DEP_RESOLVING_DATA_T_SPEC<RESOLVED_TARGET_DEP_T> parResolvingData){
            for (size_t i = 0; i < parResolvingData.size(); i++){
                if (parResolvingData[i].CEMacroName == parTargetDependency.param_s){
                    return std::move(ResolvedElementDependency<RESOLVED_TARGET_DEP_T>(parResolvingData));
                }
            }

            return nullptr;
        }
    };


    template<typename RESOLVED_TARGET_DEP_T, typename DEP_GROUP_KIND_BY_DEP_PARAM_ENUM_T, DEP_GROUP_KIND_BY_DEP_PARAM_ENUM_T valByDepParam>
    struct isSatisfied_impl{
        static bool _invoke(const ResolvedElementDependency<RESOLVED_TARGET_DEP_T>& parTargetResolvedDep);
    };

    template<typename RESOLVED_TARGET_DEP_T>
    struct isSatisfied_impl<RESOLVED_TARGET_DEP_T, nbEDepGroupKind_InRecipe_ByDepParam, nbEDepGroupKind_InRecipe_ByDepParam::Availability>{
        static bool _invoke(const ResolvedElementDependency<RESOLVED_TARGET_DEP_T>& parTargetResolvedDep){
            return parTargetResolvedDep.target_elem->IsAvailable;
        }
    };

    template<typename RESOLVED_TARGET_DEP_T>
    struct isSatisfied_impl<RESOLVED_TARGET_DEP_T, nbEDepGroupKind_InRecipe_ByDepParam, nbEDepGroupKind_InRecipe_ByDepParam::IsBoolActive>{
        static bool _invoke(const ResolvedElementDependency<RESOLVED_TARGET_DEP_T>& parTargetResolvedDep){
            return std::static_pointer_cast<nbIBoolValProperty>(parTargetResolvedDep.target_elem)->getBoolValue();
        }
    };






    template<typename ELEM_T, typename BASE_DEP_FOR_ELEM_T, typename GROUP_KIND_DEP_TARGET_PARAM_ENUM_T>
    class ConcreteElementDependenciesHandler{
    public:
        std::shared_ptr<ELEM_T> targetElem;
        MConcreteTargetParamChangingGroupsForElement_t<BASE_DEP_FOR_ELEM_T, GROUP_KIND_DEP_TARGET_PARAM_ENUM_T> resolvedDependencies;

        ConcreteElementDependenciesHandler(const std::shared_ptr<ELEM_T> &targetElem) : targetElem(targetElem) {}
    };

    class nbProjectDependenciesResolver {
        void Example(){
            ResolvedElementDependency<nbFeature> r = ResolvedElementDependency<nbFeature>(nullptr);
            isSatisfied_impl<nbFeature, nbEDepGroupKind_InRecipe_ByDepParam, nbEDepGroupKind_InRecipe_ByDepParam::Availability>::_invoke(r);
        }
    };
}

#endif //NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
