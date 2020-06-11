//
// Created by Alexey Mihailov on 06/06/2020.
//

#include "nbProperty_BoolFlag.h"

using namespace nerp;

nbEPropertyType nbProperty_BoolFlag::getPropertyType() {
    return nbEPropertyType::BoolFlag;
}

nbProperty_BoolFlag::nbProperty_BoolFlag(const std::string &name, const std::string &eMacroName, bool boolValue)
        : nbProperty(name, eMacroName), BoolValue(boolValue) {}

