//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
#define NERP_BUILDER_NBOPENEDPROJECTHANDLER_H

#include <string>
#include "nb/data/project/nbProject.h"
#include "nb/logic/nbProjectHandlerIObserver.h"
#include "nb/data/project/nbRecipe.h"
#include <ness/interface/IObservable.h>
#include <nb/logic/dependencies/nbRecipeDependenciesResolver.h>
namespace nerp {
    struct nbProject;

    class nbProjectHandlerIObserver;

    struct nbRecipe;

    class nbRecipeDependenciesResolver;

    class nbOpenedProjectHandler : IObservable<nbProjectHandlerIObserver> {
    public:
        std::string PathRootFolder;
        std::string PathNBuilderSupport;
        std::string PathNBuilderBuildMacro;
        std::string PathRootTemplateRecipes;
        std::string PathRootUserRecipes;

        std::shared_ptr<nbProject> CProject;
        std::list<std::shared_ptr<nbOpenedRecipeHandler>> OpenedRecipeHandlers;
       // nbRecipeDependenciesResolver CDepResolver;

      //  std::shared_ptr<std::list<std::shared_ptr<nbFeature>>>

        nbOpenedProjectHandler(std::string pathRootFolder, std::string pathNBuilderSupport,
                               std::string pathNBuilderBuildMacro, std::string pathRootTemplateRecipes,
                               std::string pathRootUserRecipes, std::shared_ptr<nbProject> cProject);

        void addRecipeToProject(std::shared_ptr<nbRecipe> parRecipe);
    };
}

#endif //NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
