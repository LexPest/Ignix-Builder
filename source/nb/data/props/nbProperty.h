//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROPERTY_H
#define NERP_BUILDER_NBPROPERTY_H

#include <string>
#include <nb/data/interface/nbHasMemberIntefaces.h>
#include "nbEPropertyType.h"
#include "nbPropertyGroup.h"
#include <ness/data/Property.h>

namespace nerp {
    struct nbPropertyGroup;

    struct nbProperty : __NERP_DEF_INHERIT_I_HAS_MEMBER(Name), __NERP_DEF_INHERIT_I_HAS_PROPERTY_MEMBER(IsAvailable) {
        nbEPropertyType CType;
        std::string Name;
        std::string EMacroName;
        std::shared_ptr<nbPropertyGroup> PlacedInGroup;

        std::string RichDescription;
        Property<bool> IsAvailable;

        __NERP_DEF_GENERATE_IMPLEMENT_I_HAS_MEMBER(std::string, Name, Name)
        __NERP_DEF_GENERATE_IMPLEMENT_I_HAS_PROPERTY_MEMBER(bool, IsAvailable, IsAvailable)

        nbProperty(nbEPropertyType cType, const std::string &name, const std::string &eMacroName,
                   const std::shared_ptr<nbPropertyGroup> &placedInGroup);

    };
}

#endif //NERP_BUILDER_NBPROPERTY_H
