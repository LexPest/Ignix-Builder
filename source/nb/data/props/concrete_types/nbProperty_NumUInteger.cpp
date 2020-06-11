//
// Created by Alexey Mihailov on 06/06/2020.
//

#include "nbProperty_NumUInteger.h"

using namespace nerp;

nbEPropertyType nbProperty_NumUInteger::getPropertyType() {
    return nbEPropertyType::NumUInteger;
}

nbProperty_NumUInteger::nbProperty_NumUInteger(const std::string &name, const std::string &eMacroName,
                                               uint64_t uIntValue) : nbProperty(name, eMacroName),
                                                                     UIntValue(uIntValue) {}

