//
// Created by Alexey Mihailov on 06/06/2020.
//

#ifndef NERP_BUILDER_WX_NBPROPERTY_UNICODESTRING_H
#define NERP_BUILDER_WX_NBPROPERTY_UNICODESTRING_H

#include <nb/data/props/nbProperty.h>

namespace nerp {
    class nbProperty_UnicodeString : public nbProperty {
    public:
        std::string StringValue;

        nbEPropertyType getPropertyType() override;

        nbProperty_UnicodeString(const std::string &name, const std::string &eMacroName,
                                 const std::string &stringValue);
    };
}

#endif //NERP_BUILDER_WX_NBPROPERTY_UNICODESTRING_H
