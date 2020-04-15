//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECT_H
#define NERP_BUILDER_NBPROJECT_H

#include "nbRecipe.h"
#include <string>
#include <list>
#include "../logic/nbProjectWorker.h"
#include "../logic/nbOpenedProjectHandler.h"
#include <ness/data/Version.h>
#include <ness/data/IterVersion.h>

struct nbRecipe;

class nbOpenedProjectHandler;


struct nbProject {

    friend class nbOpenedProjectHandler;

    Version CVersion;
    IterVersion SupportedRecipesIterActualVersion;
    std::string ProjectName;



    nbProject(const Version &cVersion, const IterVersion &supportedRecipesIterActualVersion,
              const std::string &projectName);

protected:
    std::list<std::shared_ptr<nbRecipe>> UserRecipes;
    std::list<std::shared_ptr<nbRecipe>> TemplateRecipes;
};


#endif //NERP_BUILDER_NBPROJECT_H
