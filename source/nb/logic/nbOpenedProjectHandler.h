//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
#define NERP_BUILDER_NBOPENEDPROJECTHANDLER_H

#include <string>
#include "nb/data/project/nbProject.h"
#include "nbProjectHandlerIObserver.h"
#include "nb/data/project/nbRecipe.h"
#include <ness/interface/IObservable.h>
namespace nerp {
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
}

#endif //NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
