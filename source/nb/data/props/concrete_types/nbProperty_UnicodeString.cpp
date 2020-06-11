//
// Created by Alexey Mihailov on 06/06/2020.
//

#include "nbProperty_UnicodeString.h"

using namespace nerp;

nbEPropertyType nbProperty_UnicodeString::getPropertyType() {
    return nbEPropertyType::UnicodeString;
}

nbProperty_UnicodeString::nbProperty_UnicodeString(const std::string &name, const std::string &eMacroName,
                                                   const std::string &stringValue) : nbProperty(name, eMacroName),
                                                                                     StringValue(stringValue) {}

