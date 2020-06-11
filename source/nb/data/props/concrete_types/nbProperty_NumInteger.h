//
// Created by Alexey Mihailov on 06/06/2020.
//

#ifndef NERP_BUILDER_WX_NBPROPERTY_NUMINTEGER_H
#define NERP_BUILDER_WX_NBPROPERTY_NUMINTEGER_H

#include <nb/data/props/nbProperty.h>

namespace nerp {
    class nbProperty_NumInteger : public nbProperty {
    public:
        int64_t IntValue;

        nbEPropertyType getPropertyType() override;

        nbProperty_NumInteger(const std::string &name, const std::string &eMacroName, int64_t intValue);
    };
}

#endif //NERP_BUILDER_WX_NBPROPERTY_NUMINTEGER_H
