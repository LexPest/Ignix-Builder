//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROPERTY_H
#define NERP_BUILDER_NBPROPERTY_H

#include <string>
#include "nbEPropertyType.h"
#include "nbPropertyGroup.h"

namespace nerp {
    struct nbPropertyGroup;

    struct nbProperty {
        nbEPropertyType CType;
        std::string Name;
        std::string EMacroName;
        std::shared_ptr<nbPropertyGroup> PlacedInGroup;

        std::string RichDescription;
        bool IsAvailable;


        nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName,
                   const std::shared_ptr<nbPropertyGroup> &placedInGroup);

        virtual bool getDataBoolFlag() = 0;
        virtual bool setDataBoolFlag() = 0;
    };
}

#endif //NERP_BUILDER_NBPROPERTY_H
