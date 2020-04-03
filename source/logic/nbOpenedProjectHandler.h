//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
#define NERP_BUILDER_NBOPENEDPROJECTHANDLER_H

#include <string>
#include "../data/nbProject.h"
#include "nbProjectHandlerIObserver.h"
#include "../data/nbRecipe.h"

struct nbProject;
class nbProjectHandlerIObserver;
struct nbRecipe;

class nbOpenedProjectHandler : IObservable<nbProjectHandlerIObserver> {
public:
    std::string PathRootFolder;
    std::string PathNBuilderSupport;
    std::string PathNBuilderBuildMacro;
    std::string PathRootTemplateRecipes;
    std::string PathRootUserRecipes;

    std::shared_ptr<nbProject> CProject;

    nbOpenedProjectHandler(std::string pathRootFolder, std::string pathNBuilderSupport,
                           std::string pathNBuilderBuildMacro, std::string pathRootTemplateRecipes,
                           std::string pathRootUserRecipes, std::shared_ptr<nbProject> cProject);

    void addRecipeToProject(std::shared_ptr<nbRecipe> parRecipe);
};


#endif //NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
