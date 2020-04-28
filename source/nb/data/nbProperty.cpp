//
// Created by Alexey Mihailov
//

#include "nbProperty.h"
using namespace nerp;

nbProperty::nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName,
                       const std::shared_ptr<nbPropertyGroup> &placedInGroup) : CType(cType), Name(name),
                                                                                EMacroName(eMacroName),
                                                                                PlacedInGroup(placedInGroup) {}
