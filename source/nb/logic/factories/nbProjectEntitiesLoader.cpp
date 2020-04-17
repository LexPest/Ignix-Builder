//
// Created by Alexey Mihailov
//

#include "nbProjectEntitiesLoader.h"
#include "../../data/consts/nbProjectStructConsts.h"
using namespace nerp;
std::shared_ptr<nbProject> nbProjectEntitiesLoader::getProjectFromYAML(const YAML::Node &parProjectSupportNodeFile) {
    Version minSupportedVer = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_NBVERSION].as<std::string>();
    IterVersion curRecipesIterVersion = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_SUPPORTED_RECIPES_ITERATION_ACTUAL_VERSION].as<std::string>();
    std::string projectName = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_PROJECT_NAME].as<std::string>();

    return std::make_shared<nbProject>(minSupportedVer, curRecipesIterVersion, std::move(projectName));
}

std::shared_ptr<nbRecipe>
nbProjectEntitiesLoader::getProjectRecipe(nbERecipeKind parRecipeKind, const YAML::Node &parRecipeNodeFile) {
    return std::shared_ptr<nbRecipe>();
}
