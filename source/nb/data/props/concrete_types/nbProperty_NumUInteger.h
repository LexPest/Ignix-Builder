//
// Created by Alexey Mihailov on 06/06/2020.
//

#ifndef NERP_BUILDER_WX_NBPROPERTY_NUMUINTEGER_H
#define NERP_BUILDER_WX_NBPROPERTY_NUMUINTEGER_H

#include <nb/data/props/nbProperty.h>

namespace nerp {
    class nbProperty_NumUInteger : public nbProperty {
    public:
        uint64_t UIntValue;

        nbEPropertyType getPropertyType() override;

        nbProperty_NumUInteger(const std::string &name, const std::string &eMacroName, uint64_t uIntValue);
    };
}

#endif //NERP_BUILDER_WX_NBPROPERTY_NUMUINTEGER_H
