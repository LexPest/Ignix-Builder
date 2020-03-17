//
// Created by Alexey Mihailov on 2020-03-18.
//

#ifndef NERP_BUILDER_NBRECIPE_H
#define NERP_BUILDER_NBRECIPE_H

#include "../common/Version.h"
#include "../common/IterVersion.h"
#include "nbPropertyGroup.h"
#include "nbERecipeKind.h"

#include <string>
#include <list>

struct nbRecipe {
    Version FormatVersion;
    IterVersion IterationVersion;
    std::string Name;
    std::list<std::shared_ptr<nbPropertyGroup>> PropGroups;

    nbERecipeKind CKind;

    nbRecipe(const Version &formatVersion, const IterVersion &iterationVersion, const std::string &name,
             nbERecipeKind cKind);
};


#endif //NERP_BUILDER_NBRECIPE_H
