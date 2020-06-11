//
// Created by Alexey Mihailov on 06/06/2020.
//

#include "nbProperty_NumInteger.h"

using namespace nerp;

nbEPropertyType nbProperty_NumInteger::getPropertyType() {
    return nbEPropertyType::NumInteger;
}

nbProperty_NumInteger::nbProperty_NumInteger(const std::string &name, const std::string &eMacroName, int64_t intValue)
        : nbProperty(name, eMacroName), IntValue(intValue) {}

