//
// Created by Alexey Mihailov on 06/06/2020.
//

#include "nbProperty_NumDouble.h"

using namespace nerp;

nbEPropertyType nbProperty_NumDouble::getPropertyType() {
    return nbEPropertyType::NumDouble;
}

nbProperty_NumDouble::nbProperty_NumDouble(const std::string &name, const std::string &eMacroName, double doubleValue)
        : nbProperty(name, eMacroName), DoubleValue(doubleValue) {}

