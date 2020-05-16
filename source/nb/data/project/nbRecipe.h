//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBRECIPE_H
#define NERP_BUILDER_NBRECIPE_H

#include "nb/data/props/nbPropertyGroup.h"
#include "nbERecipeKind.h"
#include "nb/data/features/nbFeature.h"
#include <ness/data/Version.h>
#include <ness/data/IterVersion.h>

#include <string>
#include <list>

namespace nerp {
    struct nbFeature;

    struct nbRecipe {
        Version FormatVersion;
        IterVersion IterationVersion;
        std::string Name;
        std::list<std::shared_ptr<nbFeature>> FeaturesRoot;

        nbERecipeKind CKind;

        nbRecipe(const Version &formatVersion, const IterVersion &iterationVersion, const std::string &name,
                 nbERecipeKind cKind);
    };
}

#endif //NERP_BUILDER_NBRECIPE_H
