//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECT_H
#define NERP_BUILDER_NBPROJECT_H

#include "../common/data/Version.h"
#include "../common/data/IterVersion.h"
#include "nbRecipe.h"
#include <string>
#include <list>

struct nbRecipe;

struct nbProject {
    Version CVersion;
    IterVersion SupportedRecipesIterActualVersion;
    std::string ProjectName;

    std::list<std::shared_ptr<nbRecipe>> UserRecipes;
    std::list<std::shared_ptr<nbRecipe>> TemplateRecipes;

    nbProject(const Version &cVersion, const IterVersion &supportedRecipesIterActualVersion,
              const std::string &projectName);
};


#endif //NERP_BUILDER_NBPROJECT_H
