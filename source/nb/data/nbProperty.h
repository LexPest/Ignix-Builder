//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROPERTY_H
#define NERP_BUILDER_NBPROPERTY_H

#include <string>
#include "nbEPropertyType.h"
namespace nerp {
    struct nbProperty {
        nbEPropertyType CType;
        std::string Name;
        std::string EMacroName;
        std::string RichDescription;


        nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName);
    };
}

#endif //NERP_BUILDER_NBPROPERTY_H
