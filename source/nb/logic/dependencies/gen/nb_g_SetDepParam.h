//
// Created by Alexey Mihailov on 01/06/2020.
//

#ifndef NERP_BUILDER_WX_NB_G_SETDEPPARAM_H
#define NERP_BUILDER_WX_NB_G_SETDEPPARAM_H

#include <memory>
#include <boost/any.hpp>
#include <nb/data/dependencies/nbEDepGroupKind_DepParam.h>
#include <nb/data/interface/nbHasMemberIntefaces.h>

namespace nerp {

    #include "../nbTypeAliasesInclude.h"

    struct g_SetDepParam {
        virtual void setDepParam(std::shared_ptr<boost::any> parTarget, bool parIsSatisfied) const = 0;
    };

    template<nbEDepGroupKind_DepParam tDepParamVal>
    struct g_impl_SetDepParam : g_SetDepParam {
        void setDepParam(std::shared_ptr<boost::any> parTarget, bool parIsSatisfied) const override {
//            static_assert(sizeof(decltype(tDepParamVal)) == 0, "This template shouldn't be instantiated");
        }
    };

    template<>
    struct g_impl_SetDepParam<nbEDepGroupKind_DepParam::Availability> : g_SetDepParam {
        void setDepParam(std::shared_ptr<boost::any> parTarget, bool parIsSatisfied) const override {
            auto availability_containedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(IsAvailable,
                                                                                                           parTarget);
            availability_containedElem->set_IsAvailable(parIsSatisfied);
        }
    };

    template<>
    struct g_impl_SetDepParam<nbEDepGroupKind_DepParam::SetBoolActive> : g_SetDepParam {
        void setDepParam(std::shared_ptr<boost::any> parTarget, bool parIsSatisfied) const override {
            auto boolActive_containedElem = __NERP_DEF_REINTERPRET_CAST_SHARED_PTR_I_HAS_PROPERTY_MEMBER(IsBoolActive,
                                                                                                         parTarget);
            boolActive_containedElem->set_IsBoolActive(parIsSatisfied);
        }
    };


    namespace {
#define __NERP_LOCAL_PLACE_ELEM(type) {type, new g_impl_SetDepParam<type>()}
        static const std::map<nbEDepGroupKind_DepParam, const g_SetDepParam *const> setDepParam_impls =
                {__NERP_LOCAL_PLACE_ELEM(nbEDepGroupKind_DepParam::Availability),
                 __NERP_LOCAL_PLACE_ELEM(nbEDepGroupKind_DepParam::SetBoolActive)
                };
#undef __NERP_LOCAL_PLACE_ELEM
    }
    namespace deps {
        static const g_SetDepParam& get_gen_SetDepParam(const nbEDepGroupKind_DepParam parParam) {
            return *setDepParam_impls.at(parParam);
        }
    }

}



#endif //NERP_BUILDER_WX_NB_G_SETDEPPARAM_H
