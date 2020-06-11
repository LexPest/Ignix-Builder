//
// Created by Alexey Mihailov on 06/06/2020.
//

#ifndef NERP_BUILDER_WX_NBPROPERTY_NUMDOUBLE_H
#define NERP_BUILDER_WX_NBPROPERTY_NUMDOUBLE_H

#include <nb/data/props/nbProperty.h>

namespace nerp {
    class nbProperty_NumDouble : public nbProperty {
    public:
        double DoubleValue;

        nbEPropertyType getPropertyType() override;

        nbProperty_NumDouble(const std::string &name, const std::string &eMacroName, double doubleValue);
    };
}

#endif //NERP_BUILDER_WX_NBPROPERTY_NUMDOUBLE_H
