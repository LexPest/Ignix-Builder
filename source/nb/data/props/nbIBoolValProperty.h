//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBIBOOLVALPROPERTY_H
#define NERP_BUILDER_WX_NBIBOOLVALPROPERTY_H

#include "nbProperty.h"

namespace nerp {
    class nbIBoolValProperty : public nbProperty {
    public:
        virtual bool getBoolValue() = 0;
    };
}

#endif //NERP_BUILDER_WX_NBIBOOLVALPROPERTY_H
