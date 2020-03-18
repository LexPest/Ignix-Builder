//
// Created by Alexey Mihailov on 2020-03-18.
//

#ifndef NERP_BUILDER_NBPROPERTY_H
#define NERP_BUILDER_NBPROPERTY_H

#include <string>
#include "nbEPropertyType.h"

struct nbProperty {
    nbEPropertyType CType;
    std::string Name;
    std::string EMacroName;
    std::string RichDescription;

    nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName);
};


#endif //NERP_BUILDER_NBPROPERTY_H
