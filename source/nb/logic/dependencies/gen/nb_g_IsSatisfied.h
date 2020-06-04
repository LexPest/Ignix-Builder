//
// Created by Alexey Mihailov on 30/05/2020.
//

#ifndef NERP_BUILDER_WX_NB_G_ISSATISFIED_H
#define NERP_BUILDER_WX_NB_G_ISSATISFIED_H

#include <boost/any.hpp>
#include <nb/data/dependencies/nbEDepGroupKind_ByDepParam.h>
#include <nb/data/interface/nbHasMemberIntefaces.h>
namespace nerp {


#include "../nbTypeAliasesInclude.h"

    struct g_IsSatisfied {
        virtual bool isSatisfied(std::shared_ptr<boost::any> parTarget) const = 0;
        virtual void addBindingFunctionOnPropChange_NoArg(std::shared_ptr<boost::any> parTarget, std::function<void(void)> parFunc) const = 0;
    };

    template<nbEDepGroupKind_ByDepParam tByDepParamVal>
    struct g_impl_IsSatisfied : g_IsSatisfied {
        bool isSatisfied(std::shared_ptr<boost::any> parTarget) const override {
            static_assert(sizeof(decltype(tByDepParamVal)) == 0, "This template shouldn't be instantiated");
        }

        void addBindingFunctionOnPropChange_NoArg(std::shared_ptr<boost::any> parTarget, std::function<void(void)> parFunc) const override {
            static_assert(sizeof(decltype(tByDepParamVal)) == 0, "This template shouldn't be instantiated");
        }
    };

    template<>
    struct g_impl_IsSatisfied<nbEDepGroupKind_ByDepParam::Availability> : g_IsSatisfied {
        bool isSatisfied(std::shared_ptr<boost::any> parTarget) const override {
            auto availabilityContainedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(IsAvailable,
                                                                                                          parTarget);
            return availabilityContainedElem->get_IsAvailable();
        }

        void addBindingFunctionOnPropChange_NoArg(std::shared_ptr<boost::any> parTarget, std::function<void(void)> parFunc) const override {
            auto availabilityContainedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(IsAvailable,
                                                                                                          parTarget);
            availabilityContainedElem->add_function_to_invoke_on_prop_change_no_arg_IsAvailable(parFunc);
        }
    };

    template<>
    struct g_impl_IsSatisfied<nbEDepGroupKind_ByDepParam::IsBoolActive> : g_IsSatisfied {
        bool isSatisfied(std::shared_ptr<boost::any> parTarget) const override {
            auto boolActiveContainedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(IsBoolActive,
                                                                                                        parTarget);
            return boolActiveContainedElem->get_IsBoolActive();
        }

        void addBindingFunctionOnPropChange_NoArg(std::shared_ptr<boost::any> parTarget, std::function<void(void)> parFunc) const override {
            auto availabilityContainedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(IsBoolActive,
                                                                                                          parTarget);
            availabilityContainedElem->add_function_to_invoke_on_prop_change_no_arg_IsBoolActive(parFunc);
        }
    };

    namespace {
#define __NERP_LOCAL_PLACE_ELEM(type) {type, new g_impl_IsSatisfied<type>()}
        static const std::map<nbEDepGroupKind_ByDepParam, const g_IsSatisfied *const> isSatisfied_impls =
                {__NERP_LOCAL_PLACE_ELEM(nbEDepGroupKind_ByDepParam::Availability),
                 __NERP_LOCAL_PLACE_ELEM(nbEDepGroupKind_ByDepParam::IsBoolActive)
                };
#undef __NERP_LOCAL_PLACE_ELEM
    }
    namespace deps {
        static const g_IsSatisfied& get_gen_IsSatisfied(const nbEDepGroupKind_ByDepParam parParam) {
            return *isSatisfied_impls.at(parParam);
        }
    }
}

#endif //NERP_BUILDER_WX_NB_G_ISSATISFIED_H
