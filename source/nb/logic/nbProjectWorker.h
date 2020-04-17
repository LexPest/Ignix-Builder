//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTWORKER_H
#define NERP_BUILDER_NBPROJECTWORKER_H

#include <string>
#include <list>
#include <ios>
//#include <filesystem>
#include <boost/filesystem.hpp>
#include "nb/logic/request_data/nbReqProjectLoadingResult.h"
#include "nb/logic/request_data/nbReqProjectSavingResult.h"
#include "../data/nbRecipe.h"
#include "nbProjectHandlerIObserver.h"
namespace nerp {
    class nbIObserverProjectWorker;

    struct nbRecipe;
    struct nbOpenedProjectHandler;
    struct nbReqProjectLoadingResult;
    struct nbReqProjectSavingResult;

//static
    class nbProjectWorker {

    public:
        static void discoverProjectRecipes(nbOpenedProjectHandler &parPrjHandler);

        static void loadProject(std::function<void(nbReqProjectLoadingResult)> parEndCallback,
                                const std::string &parAbsoluteProjectPath);

        static void saveProject(std::function<void(nbReqProjectSavingResult)> parEndCallback,
                                const std::shared_ptr<nbOpenedProjectHandler> parTargetProject);

        static void addRecipeToProject(nbOpenedProjectHandler &parPrjHandler, std::shared_ptr<nbRecipe> parRecipe);

    private:
        static boost::filesystem::directory_iterator getTemplateRecipesIterator(nbOpenedProjectHandler &parPrjHandler);

        static boost::filesystem::directory_iterator getUserRecipesIterator(nbOpenedProjectHandler &parPrjHandler);
    };
}

#endif //NERP_BUILDER_NBPROJECTWORKER_H
