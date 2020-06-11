//
// Created by Alexey Mihailov on 06/06/2020.
//

#ifndef NERP_BUILDER_WX_NBPROPERTY_BOOLFLAG_H
#define NERP_BUILDER_WX_NBPROPERTY_BOOLFLAG_H

#include <nb/data/props/nbProperty.h>

namespace nerp {
    class nbProperty_BoolFlag : public nbProperty {
    public:
        bool BoolValue;

        nbEPropertyType getPropertyType() override;

        nbProperty_BoolFlag(const std::string &name, const std::string &eMacroName, bool boolValue);
    };
}

#endif //NERP_BUILDER_WX_NBPROPERTY_BOOLFLAG_H
