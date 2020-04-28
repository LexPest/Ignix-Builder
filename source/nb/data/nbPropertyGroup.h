//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROPERTYGROUP_H
#define NERP_BUILDER_NBPROPERTYGROUP_H

#include <list>
#include <string>
#include "nbProperty.h"

namespace nerp {
    struct nbProperty;

    struct nbPropertyGroup {
        std::string CName;
        std::list<std::shared_ptr<nbProperty>> Props;

        nbPropertyGroup(const std::string &name);

        std::shared_ptr<nbProperty> getPropByName(const std::string& parName);
    };
}

#endif //NERP_BUILDER_NBPROPERTYGROUP_H
