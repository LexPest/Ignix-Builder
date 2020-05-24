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
#include <nb/data/dependencies/nbEDepGroupKind_DepTarget_Type.h>
#include <nb/data/dependencies/nbEDepGroupKind_DepParam.h>
#include <nb/data/dependencies/nbEDepGroupKind_SearchCriteriaForDepResolve.h>
#include <nb/data/features/nbFeature.h>

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
   // Resolved Dependencies

    class ResolvedDependency {
    public:
        nbEDepGroupKind_ByDepParam byDepParamValue;
        nbEDepGroupKind_DepTarget_Type depTarget;

        ResolvedDependency(nbEDepGroupKind_ByDepParam byDepParamValue, nbEDepGroupKind_DepTarget_Type depTarget);

        virtual bool isSatisfied() = 0;
    };

    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename DEP_ON_TARGET_T>
    struct gen_isSatisfied_impl{
        static bool _invoke(const std::shared_ptr<DEP_ON_TARGET_T> parTarget){
            static_assert(sizeof(DEP_ON_TARGET_T) == 0, "This template shouldn't be instantiated");
        };
    };

    template<nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename DEP_ON_TARGET_T>
    struct gen_isSatisfied_impl<nbEDepGroupKind_ByDepParam::Availability, tDepOnTargetKind, DEP_ON_TARGET_T>{
        static bool _invoke(const std::shared_ptr<DEP_ON_TARGET_T> parTarget){
            return parTarget->IsAvailable.get();
        };
    };

    template<nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename DEP_ON_TARGET_T>
    struct gen_isSatisfied_impl<nbEDepGroupKind_ByDepParam::IsBoolActive, tDepOnTargetKind, DEP_ON_TARGET_T>{
        static bool _invoke(const std::shared_ptr<DEP_ON_TARGET_T> parTarget){
            return parTarget->getBoolValue();
        };
    };


    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename DEP_ON_TARGET_T>
    class ResolvedDependency_T : public ResolvedDependency {
    public:
        std::shared_ptr<DEP_ON_TARGET_T> depOnTargetElemPtr;

        explicit ResolvedDependency_T(const std::shared_ptr<DEP_ON_TARGET_T> &depOnTargetElemPtr) : ResolvedDependency(
                tByDepParamVal, tDepOnTargetKind), depOnTargetElemPtr(depOnTargetElemPtr) {}

        bool isSatisfied() override {
            return gen_isSatisfied_impl<tByDepParamVal, tDepOnTargetKind, DEP_ON_TARGET_T>::_invoke(depOnTargetElemPtr);
        }
    };

    // = = = = = = = = = = = = = =
    // Unresolved Dependencies

   class UnresolvedDependency {
   public:
       const nbEDepGroupKind_ByDepParam byDepParamValue;
       const nbEDepGroupKind_DepParam depParamValue;
       const nbEDepGroupKind_SearchCriteriaForDepResolve searchCriteriaValue;
       const nbEDepGroupKind_DepTarget_Type depOnTarget;

       virtual std::shared_ptr<ResolvedDependency> callResolve() = 0;

       UnresolvedDependency(nbEDepGroupKind_ByDepParam byDepParamValue, nbEDepGroupKind_DepParam depParamValue,
                            nbEDepGroupKind_SearchCriteriaForDepResolve searchCriteriaValue,
                            nbEDepGroupKind_DepTarget_Type depOnTarget);
   };

    template<
            nbEDepGroupKind_ByDepParam tByDepParamVal,
            nbEDepGroupKind_DepParam tDepParamVal,
            nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue,
            nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename RESOLVING_INPUT_PARAMs_T,
            typename DEP_ON_TARGET_T>
    class UnresolvedDependency_T;


   template<nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue,
           nbEDepGroupKind_ByDepParam tByDepParamVal,
           nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
           typename RESOLVING_INPUT_PARAMs_T,
           typename DEP_ON_TARGET_T>
   struct gen_resolveDependency_impl{
        static std::shared_ptr<ResolvedDependency_T<tByDepParamVal, tDepOnTargetKind, DEP_ON_TARGET_T>>
                _invoke(const RESOLVING_INPUT_PARAMs_T& parResolveParams){
            static_assert(sizeof(RESOLVING_INPUT_PARAMs_T) == 0, "This template shouldn't be instantiated");
        };
   };

    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename RESOLVING_INPUT_PARAMs_T,
            typename DEP_ON_TARGET_T>
   struct gen_resolveDependency_impl<nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s, tByDepParamVal, tDepOnTargetKind,
           RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>{
       using RESOLVED_DEP_ALIAS = ResolvedDependency_T<tByDepParamVal, tDepOnTargetKind, DEP_ON_TARGET_T>;
       static std::shared_ptr<RESOLVED_DEP_ALIAS>
              _invoke(const RESOLVING_INPUT_PARAMs_T& parResolveParams){
           for (std::shared_ptr<DEP_ON_TARGET_T> targetElem : std::get<0>(parResolveParams)){
               if (targetElem->CEMacroName == std::get<1>(parResolveParams)){
                   return std::make_shared<RESOLVED_DEP_ALIAS>(targetElem);
               }
           }
           return nullptr;
       };
   };

    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
            typename RESOLVING_INPUT_PARAMs_T,
            typename DEP_ON_TARGET_T>
    struct gen_resolveDependency_impl<nbEDepGroupKind_SearchCriteriaForDepResolve::ByName_s, tByDepParamVal, tDepOnTargetKind,
            RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>{
        using RESOLVED_DEP_ALIAS = ResolvedDependency_T<tByDepParamVal, tDepOnTargetKind, DEP_ON_TARGET_T>;
        static std::shared_ptr<RESOLVED_DEP_ALIAS>
        _invoke(const RESOLVING_INPUT_PARAMs_T& parResolveParams){
            for (std::shared_ptr<DEP_ON_TARGET_T> targetElem : std::get<0>(parResolveParams)){
                if (targetElem->CName == std::get<1>(parResolveParams)){
                    return std::make_shared<RESOLVED_DEP_ALIAS>(targetElem);
                }
            }
            return nullptr;
        };
    };

   template<
           nbEDepGroupKind_ByDepParam tByDepParamVal,
           nbEDepGroupKind_DepParam tDepParamVal,
           nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue,
           nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
           typename RESOLVING_INPUT_PARAMs_T,
           typename DEP_ON_TARGET_T>
   class UnresolvedDependency_T : public UnresolvedDependency{
   public:
       typedef DEP_ON_TARGET_T DEP_ON_TARGET_T_value_type;
       RESOLVING_INPUT_PARAMs_T inputParams; // std::tuple<std::shared_ptr<std::list<TARGETs>>, std::string FindStr>

       using resolveDependency_impl_alias = gen_resolveDependency_impl<tSearchCriteriaValue, tByDepParamVal, tDepOnTargetKind, RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>;
       
       explicit UnresolvedDependency_T(RESOLVING_INPUT_PARAMs_T& parResolvingInputParams) : UnresolvedDependency(tByDepParamVal,
                                                       tDepParamVal,
                                                       tSearchCriteriaValue,
                                                       tDepOnTargetKind), inputParams(parResolvingInputParams) {}

       std::shared_ptr<ResolvedDependency> callResolve() override {
           return resolveDependency_impl_alias::_invoke(inputParams);
       }
   };




   // = = = = = = = = = = = = = =
   // Dependencies for Concrete Element


   class DependenciesForConcreteElement {
   public:
       std::list<std::shared_ptr<UnresolvedDependency>> UnresolvedDependencies;
       std::map<nbEDepGroupKind_DepParam, std::list<std::shared_ptr<ResolvedDependency>>> ResolvedDependenciesByTargetDepParamsMap;

       DependenciesForConcreteElement();

       template<
               nbEDepGroupKind_ByDepParam tByDepParamVal,
               nbEDepGroupKind_DepParam tDepParamVal,
               nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue,
               nbEDepGroupKind_DepTarget_Type tDepOnTargetKind,
               typename RESOLVING_INPUT_PARAMs_T,
               typename DEP_ON_TARGET_T>
       void addDependency(RESOLVING_INPUT_PARAMs_T tParResolvingInputParams){
           using UNRESOLVED_DEP_ALIAS = UnresolvedDependency_T<tByDepParamVal, tDepParamVal, tSearchCriteriaValue, tDepOnTargetKind, RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>;
           std::shared_ptr<UNRESOLVED_DEP_ALIAS>
                unresolvedDep = std::make_shared<UNRESOLVED_DEP_ALIAS>(tParResolvingInputParams);
           std::shared_ptr<UnresolvedDependency> convPtr = std::static_pointer_cast<UnresolvedDependency>(unresolvedDep);
           UnresolvedDependencies.push_back(convPtr);
       };

       void resolveAllDependencies(){
            for (const auto& unresolvedDep : UnresolvedDependencies){
                auto resolvedDep = unresolvedDep->callResolve();

                auto possibleResolvedLists = ResolvedDependenciesByTargetDepParamsMap.find(unresolvedDep->depParamValue);
                if (possibleResolvedLists == ResolvedDependenciesByTargetDepParamsMap.end()){
                    std::list<std::shared_ptr<ResolvedDependency>> newList;
                    ResolvedDependenciesByTargetDepParamsMap.insert(std::make_pair(unresolvedDep->depParamValue, std::move(newList)));
                    possibleResolvedLists = ResolvedDependenciesByTargetDepParamsMap.find(unresolvedDep->depParamValue);
                }

                possibleResolvedLists->second.push_back(std::move(resolvedDep));
            }
       }
   };


    // = = = = = = = = = = = = = =
    // Test templates usage


    class nbProjectDependenciesResolver {

        void Example(){
           // ResolvedElementDependency<nbFeature> r = ResolvedElementDependency<nbFeature>(nullptr);
           // isSatisfied_impl<nbFeature, nbEDepGroupKind_ByDepParam, nbEDepGroupKind_ByDepParam::Availability>::_invoke(r);
           DependenciesForConcreteElement e = DependenciesForConcreteElement();
           const std::tuple<std::list<std::shared_ptr<nbFeature>>, std::string> tuple;
           e.addDependency<
           nbEDepGroupKind_ByDepParam::Availability,
                    nbEDepGroupKind_DepParam::SetBoolActive,
                    nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s,
                    nbEDepGroupKind_DepTarget_Type::SingleEntity,
                   std::tuple<std::list<std::shared_ptr<nbFeature>>, std::string>, nbFeature>(tuple);

           std::shared_ptr<UnresolvedDependency> unresDep = e.UnresolvedDependencies.front();
           e.resolveAllDependencies();
        }
    };
}

#endif //NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
