//
// Created by Alexey Mihailov on 2020-03-18.
//

#include "nbProperty.h"

nbProperty::nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName) : CType(cType),
                                                                                                        Name(name),
                                                                                                        EMacroName(
                                                                                                                eMacroName) {}
