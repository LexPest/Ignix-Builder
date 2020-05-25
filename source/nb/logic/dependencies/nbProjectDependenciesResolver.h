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

        ResolvedDependency(nbEDepGroupKind_ByDepParam byDepParamValue);

        virtual bool isSatisfied() = 0;
    };

    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            typename DEP_ON_TARGET_T>
    struct gen_isSatisfied_impl{
        static bool _invoke(const std::shared_ptr<DEP_ON_TARGET_T> parTarget){
            static_assert(sizeof(DEP_ON_TARGET_T) == 0, "This template shouldn't be instantiated");
        };
    };

    template<
            typename DEP_ON_TARGET_T>
    struct gen_isSatisfied_impl<nbEDepGroupKind_ByDepParam::Availability, DEP_ON_TARGET_T>{
        static bool _invoke(const std::shared_ptr<DEP_ON_TARGET_T> parTarget){
            return parTarget->IsAvailable.get();
        };
    };

    template<
            typename DEP_ON_TARGET_T>
    struct gen_isSatisfied_impl<nbEDepGroupKind_ByDepParam::IsBoolActive, DEP_ON_TARGET_T>{
        static bool _invoke(const std::shared_ptr<DEP_ON_TARGET_T> parTarget){
            return parTarget->getBoolValue();
        };
    };


    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            typename DEP_ON_TARGET_T>
    class ResolvedDependency_T : public ResolvedDependency {
    public:
        std::shared_ptr<DEP_ON_TARGET_T> depOnTargetElemPtr;

        explicit ResolvedDependency_T(const std::shared_ptr<DEP_ON_TARGET_T> &depOnTargetElemPtr) : ResolvedDependency(
                tByDepParamVal), depOnTargetElemPtr(depOnTargetElemPtr) {}

        bool isSatisfied() override {
            return gen_isSatisfied_impl<tByDepParamVal, DEP_ON_TARGET_T>::_invoke(depOnTargetElemPtr);
        }
    };

    // = = = = = = = = = = = = = =
    // Unresolved Dependencies

   class UnresolvedDependency {
   public:
       const nbEDepGroupKind_ByDepParam byDepParamValue;
       const nbEDepGroupKind_DepParam depParamValue;
       const nbEDepGroupKind_SearchCriteriaForDepResolve searchCriteriaValue;

       virtual std::shared_ptr<ResolvedDependency> callResolve() = 0;

       UnresolvedDependency(nbEDepGroupKind_ByDepParam byDepParamValue, nbEDepGroupKind_DepParam depParamValue,
                            nbEDepGroupKind_SearchCriteriaForDepResolve searchCriteriaValue);
   };

    template<
            nbEDepGroupKind_ByDepParam tByDepParamVal,
            nbEDepGroupKind_DepParam tDepParamVal,
            nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue,
            typename RESOLVING_INPUT_PARAMs_T,
            typename DEP_ON_TARGET_T>
    class UnresolvedDependency_T;


   template<nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue,
           nbEDepGroupKind_ByDepParam tByDepParamVal,
           typename RESOLVING_INPUT_PARAMs_T,
           typename DEP_ON_TARGET_T>
   struct gen_resolveDependency_impl{
        static std::shared_ptr<ResolvedDependency_T<tByDepParamVal, DEP_ON_TARGET_T>>
                _invoke(const RESOLVING_INPUT_PARAMs_T& parResolveParams){
            static_assert(sizeof(RESOLVING_INPUT_PARAMs_T) == 0, "This template shouldn't be instantiated");
        };
   };

    template<nbEDepGroupKind_ByDepParam tByDepParamVal,
            typename RESOLVING_INPUT_PARAMs_T,
            typename DEP_ON_TARGET_T>
   struct gen_resolveDependency_impl<nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s, tByDepParamVal,
           RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>{
       using RESOLVED_DEP_ALIAS = ResolvedDependency_T<tByDepParamVal, DEP_ON_TARGET_T>;
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
            typename RESOLVING_INPUT_PARAMs_T,
            typename DEP_ON_TARGET_T>
    struct gen_resolveDependency_impl<nbEDepGroupKind_SearchCriteriaForDepResolve::ByName_s, tByDepParamVal,
            RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>{
        using RESOLVED_DEP_ALIAS = ResolvedDependency_T<tByDepParamVal,  DEP_ON_TARGET_T>;
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
           typename RESOLVING_INPUT_PARAMs_T,
           typename DEP_ON_TARGET_T>
   class UnresolvedDependency_T : public UnresolvedDependency{
   public:
       typedef DEP_ON_TARGET_T DEP_ON_TARGET_T_value_type;
       RESOLVING_INPUT_PARAMs_T inputParams; // std::tuple<std::shared_ptr<std::list<TARGETs>>, std::string FindStr>

       using resolveDependency_impl_alias = gen_resolveDependency_impl<tSearchCriteriaValue, tByDepParamVal,  RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>;
       
       explicit UnresolvedDependency_T(RESOLVING_INPUT_PARAMs_T& parResolvingInputParams) : UnresolvedDependency(tByDepParamVal,
                                                       tDepParamVal,
                                                       tSearchCriteriaValue), inputParams(parResolvingInputParams) {}

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
               typename RESOLVING_INPUT_PARAMs_T,
               typename DEP_ON_TARGET_T>
       void addDependency(RESOLVING_INPUT_PARAMs_T tParResolvingInputParams){
           using UNRESOLVED_DEP_ALIAS = UnresolvedDependency_T<tByDepParamVal, tDepParamVal, tSearchCriteriaValue, RESOLVING_INPUT_PARAMs_T, DEP_ON_TARGET_T>;
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

       void calculateInitialElementValues(){

       }

       void injectAutoDependencyCalcFunctionsIntoProperties(){

       }

   private:
       bool is_operation_locked = false;
   };


   class DependencyRelatedElementData{
   public:
       bool FirstTimeEvaluated = false;
       std::list<std::shared_ptr<InvokeFunctionHandlerMeta>> OnChangePropertyInvokeFuncsHandlers;
       std::shared_ptr<DependenciesForConcreteElement> DependenciesForElement;

       explicit DependencyRelatedElementData(const std::shared_ptr<DependenciesForConcreteElement> &parDependenciesForElement){
           if (parDependenciesForElement == nullptr){
               DependenciesForElement = std::make_shared<DependenciesForConcreteElement>();
           } else {
               DependenciesForElement = parDependenciesForElement;
           }
       }
   };

   class nbProjectDependenciesResolver{
   private:
       std::map<std::shared_ptr<boost::any>, std::shared_ptr<DependencyRelatedElementData>> RegisteredDependencyRelatedElements;

       void addDependency(const std::shared_ptr<boost::any>& parTargetElement, const YAML::Node& parDependencyNode){
           auto foundEntity = RegisteredDependencyRelatedElements.find(parTargetElement);
           if (foundEntity == RegisteredDependencyRelatedElements.end()){
               std::shared_ptr<DependencyRelatedElementData> depRelatedElemData = std::make_shared<DependencyRelatedElementData>(nullptr);
               RegisteredDependencyRelatedElements.insert(std::make_pair(parTargetElement, std::move(depRelatedElemData)));
               foundEntity = RegisteredDependencyRelatedElements.find(parTargetElement);
           }

           auto depsForElement = foundEntity->second->DependenciesForElement;
           std::string depKindString = parDependencyNode[nb_consts::depends::YAML_DEPENDENCY_KIND_KEY_NAME].as<std::string>();

           if (depKindString == nb_consts::depends::YAML_FEATURE_DEPENDS_TYPE_FEATURE_AVAIL_ON_EMACRO){
        //     depsForElement->addDependency<nbEDepGroupKind_ByDepParam::>()
           }

       }
   };


    // = = = = = = = = = = = = = =
    // Test templates usage


    class nbProjectDependenciesResolver_Example {

        void Example(){
           // ResolvedElementDependency<nbFeature> r = ResolvedElementDependency<nbFeature>(nullptr);
           // isSatisfied_impl<nbFeature, nbEDepGroupKind_ByDepParam, nbEDepGroupKind_ByDepParam::Availability>::_invoke(r);
           DependenciesForConcreteElement e = DependenciesForConcreteElement();
           const std::tuple<std::list<std::shared_ptr<nbFeature>>, std::string> tuple;
           e.addDependency<
           nbEDepGroupKind_ByDepParam::Availability,
                    nbEDepGroupKind_DepParam::SetBoolActive,
                    nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s,
                   std::tuple<std::list<std::shared_ptr<nbFeature>>, std::string>, nbFeature>(tuple);

           std::shared_ptr<UnresolvedDependency> unresDep = e.UnresolvedDependencies.front();
           e.resolveAllDependencies();
        }
    };


    struct g_ResolveDependency{
        virtual boost::any resolve(std::tuple<std::list<boost::any>, boost::any>) = 0;
    };

    template<nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue>
    struct g_impl_ResolveDependency : g_ResolveDependency{
        boost::any resolve(std::tuple<std::list<boost::any>, boost::any> tuple) override {
            static_assert(sizeof(decltype(tSearchCriteriaValue)) == 0, "This template shouldn't be instantiated");
        }
    };

    template<>
    struct g_impl_ResolveDependency<nbEDepGroupKind_SearchCriteriaForDepResolve::ByName_s> : g_ResolveDependency{
        boost::any resolve(std::tuple<std::list<boost::any>, boost::any> tuple) override {

        }
    };
}




#endif //NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
