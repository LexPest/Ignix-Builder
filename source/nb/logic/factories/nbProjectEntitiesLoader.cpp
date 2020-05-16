//
// Created by Alexey Mihailov
//

#include "nbProjectEntitiesLoader.h"
#include <nb/consts/nbProjectStructConsts.h>
using namespace nerp;
std::shared_ptr<nbProject> nbProjectEntitiesLoader::getProjectFromYAML(const YAML::Node &parProjectSupportNodeFile) {
    Version minSupportedVer = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_NBVERSION].as<std::string>();
    IterVersion curRecipesIterVersion = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_SUPPORTED_RECIPES_ITERATION_ACTUAL_VERSION].as<std::string>();
    std::string projectName = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_PROJECT_NAME].as<std::string>();

    return std::make_shared<nbProject>(minSupportedVer, curRecipesIterVersion, std::move(projectName));
}

std::shared_ptr<nbRecipe>
nbProjectEntitiesLoader::getProjectRecipe(nbERecipeKind parRecipeKind, const YAML::Node &parRecipeNodeFile) {
    Version recipeFormatVer = parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_RECIPE_NAME].as<std::string>();
    IterVersion recipeIterVer = parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_ITERACTION_VERSION].as<std::string>();
    std::string recipeName = parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_RECIPE_NAME].as<std::string>();

    //TODO: Recipe prop elems parsing

    return std::make_shared<nbRecipe>(recipeFormatVer, recipeIterVer, std::move(recipeName), parRecipeKind);
}
