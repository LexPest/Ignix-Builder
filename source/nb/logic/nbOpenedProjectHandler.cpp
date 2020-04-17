#include <utility>

#include <utility>

//
// Created by Alexey Mihailov
//

#include "nbOpenedProjectHandler.h"
using namespace nerp;
nbOpenedProjectHandler::nbOpenedProjectHandler(std::string pathRootFolder,
                                               std::string pathNBuilderSupport,
                                               std::string pathNBuilderBuildMacro,
                                               std::string pathRootTemplateRecipes,
                                               std::string pathRootUserRecipes,
                                               std::shared_ptr<nbProject> cProject) : PathRootFolder(std::move(
        pathRootFolder)), PathNBuilderSupport(std::move(pathNBuilderSupport)), PathNBuilderBuildMacro(std::move(pathNBuilderBuildMacro)),
                                                                                             PathRootTemplateRecipes(std::move(
                                                                                                     pathRootTemplateRecipes)),
                                                                                             PathRootUserRecipes(std::move(
                                                                                                     pathRootUserRecipes)),
                                                                                             CProject(std::move(cProject)) {}

void nbOpenedProjectHandler::addRecipeToProject(std::shared_ptr<nbRecipe> parRecipe) {
    std::list<std::shared_ptr<nbRecipe>>* targetRecipeSetPtr = nullptr;
    switch (parRecipe->CKind) {
        case nbERecipeKind::TemplateRecipe:
            targetRecipeSetPtr = &CProject->TemplateRecipes;
            break;
        case nbERecipeKind::UserRecipe:
            targetRecipeSetPtr = &CProject->UserRecipes;
            break;
    }
    targetRecipeSetPtr->emplace_back(parRecipe);

    NotifyAll([parRecipe = parRecipe](nbProjectHandlerIObserver& observer) {observer.Notify_RecipeAdded(*parRecipe);});
}
