//
// Created by Alexey Mihailov
//

#include "nbProperty.h"

nbProperty::nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName) : CType(cType),
                                                                                                        Name(name),
                                                                                                        EMacroName(
                                                                                                                eMacroName) {}
