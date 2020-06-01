//
// Created by Alexey Mihailov on 29/05/2020.
//

#ifndef NERP_BUILDER_WX_NB_G_RESOLVEDEPENDENCY_H
#define NERP_BUILDER_WX_NB_G_RESOLVEDEPENDENCY_H

#include <nb/logic/dependencies/nbProjectDependenciesResolver.h>

namespace nerp {

#include "../nbTypeAliasesInclude.h"

    struct g_ResolveDependency {
        virtual std::shared_ptr<boost::any>
        resolve(ResolveParamsTuple_T parTuple) const = 0;
    };

    template<nbEDepGroupKind_SearchCriteriaForDepResolve tSearchCriteriaValue>
    struct g_impl_ResolveDependency : g_ResolveDependency {
        std::shared_ptr<boost::any>
        resolve(ResolveParamsTuple_T parTuple) const override {
            static_assert(sizeof(decltype(tSearchCriteriaValue)) == 0, "This template shouldn't be instantiated");
        }
    };

    template<>
    struct g_impl_ResolveDependency<nbEDepGroupKind_SearchCriteriaForDepResolve::ByName_s> : g_ResolveDependency {
        std::shared_ptr<boost::any>
        resolve(ResolveParamsTuple_T parTuple) const override {
            auto targetElemsList = std::get<0>(parTuple);
            std::shared_ptr<std::string> nameParam = boost::reinterpret_pointer_cast<std::string>(
                    std::get<1>(parTuple));
            for (auto searchElem : *targetElemsList) {
                auto nameContainedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_MEMBER(Name, searchElem);
                if (nameContainedElem->get_Name() == *nameParam) {
                    return searchElem;
                }
            }
            return nullptr;
        }
    };

    template<>
    struct g_impl_ResolveDependency<nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s> : g_ResolveDependency {
        std::shared_ptr<boost::any>
        resolve(ResolveParamsTuple_T parTuple) const override {
            auto targetElemsList = std::get<0>(parTuple);
            std::shared_ptr<std::string> nameParam = boost::reinterpret_pointer_cast<std::string>(
                    std::get<1>(parTuple));
            for (auto searchElem : *targetElemsList) {
                auto emacroNameContainedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_MEMBER(EMacroName,
                                                                                                   searchElem);
                if (emacroNameContainedElem->get_EMacroName() == *nameParam) {
                    return searchElem;
                }
            }
            return nullptr;
        }
    };

    namespace {
#define __NERP_LOCAL_PLACE_ELEM(type) {type, new g_impl_ResolveDependency<type>()}
        static const std::map<nbEDepGroupKind_SearchCriteriaForDepResolve, const g_ResolveDependency *const> resolveDep_impls =
                {__NERP_LOCAL_PLACE_ELEM(nbEDepGroupKind_SearchCriteriaForDepResolve::ByName_s),
                 __NERP_LOCAL_PLACE_ELEM(nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro_s)
                };
#undef __NERP_LOCAL_PLACE_ELEM
    }
    namespace deps {
        static const g_ResolveDependency& get_gen_DependencyResolver(const nbEDepGroupKind_SearchCriteriaForDepResolve parParam) {
            return *resolveDep_impls.at(parParam);
        }
    }


}

#endif //NERP_BUILDER_WX_NB_G_RESOLVEDEPENDENCY_H
