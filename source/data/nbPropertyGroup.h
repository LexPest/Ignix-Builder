//
// Created by Alexey Mihailov on 2020-03-18.
//

#ifndef NERP_BUILDER_NBPROPERTYGROUP_H
#define NERP_BUILDER_NBPROPERTYGROUP_H

#include <list>
#include <string>
#include "nbProperty.h"


struct nbPropertyGroup {
    std::string CName;
    std::list<std::shared_ptr<nbProperty>> Props;

    nbPropertyGroup(const std::string &name);
};


#endif //NERP_BUILDER_NBPROPERTYGROUP_H
