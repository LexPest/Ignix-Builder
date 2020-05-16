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

namespace nerp {
    template<typename BASE_DEP_FOR_ELEM_T, typename GROUP_KIND_ENUM_T>
    using DepByGroupsForElement = std::unordered_map<GROUP_KIND_ENUM_T, std::list<BASE_DEP_FOR_ELEM_T>>;

    template<typename DEP_RESOLVING_INPUT_PARAMS_T>
    class UnresolvedElementDependency{
    public:
        DEP_RESOLVING_INPUT_PARAMS_T param_s;
    };

    template<typename ELEM_T, typename DEP_RESOLVING_INPUT_PARAMS_T, typename DEP_RESOLVING_DATA_T>
    bool resolveDependency_Func(const UnresolvedElementDependency<DEP_RESOLVING_INPUT_PARAMS_T>& parTargetDependency, const DEP_RESOLVING_DATA_T& parResolvingData);

    template<>
    bool resolveDependency_Func<nbPDep_AvailableOnNames, std::string, std::list<std::shared_ptr<nbProperty>>>(const UnresolvedElementDependency<std::string>& parTargetDependency, const std::list<std::shared_ptr<nbProperty>>& parResolvingData){

    };

    template<typename ELEM_T, typename BASE_DEP_FOR_ELEM_T, typename GROUP_KIND_ENUM_T>
    class ConcreteElementDependenciesHandler{
    public:
        std::shared_ptr<ELEM_T> targetElem;
        DepByGroupsForElement<BASE_DEP_FOR_ELEM_T, GROUP_KIND_ENUM_T> resolvedDependencies;

        ConcreteElementDependenciesHandler(const std::shared_ptr<ELEM_T> &targetElem) : targetElem(targetElem) {}
    };

    class nbProjectDependenciesResolver {

    };
}

#endif //NERP_BUILDER_WX_NBPROJECTDEPENDENCIESRESOLVER_H
