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

    std::shared_ptr<nbRecipe> recipe = std::make_shared<nbRecipe>(recipeFormatVer, recipeIterVer, std::move(recipeName), parRecipeKind);

    parseAndFillFeatures(recipe->FeaturesRoot, parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_FEATURES_ARR]);

    return std::move(recipe);
}

void nbProjectEntitiesLoader::parseAndFillFeatures(std::list<std::shared_ptr<nbFeature>> &parFeaturesList,
                                                   const YAML::Node &parParentFeaturesArrNode) {
    for (const auto & currentNode : parParentFeaturesArrNode){
        std::string name = currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_NAME].as<std::string>();
        std::string emacro = currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_EMACRO].as<std::string>();

        std::shared_ptr<nbFeature> feature = std::make_shared<nbFeature>(name, emacro);
        feature->RichDescription = currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_RICHDESCR].as<std::string>();
        feature->IsAvailable.set(true);
        parseAndFillPropGroups(feature->PropertyGroups, currentNode[nb_consts::recipe::feature::YAML_FIELD_PROP_GROUPS_ARR]);

        //recursion here
        parseAndFillFeatures(feature->ChildFeatures, currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_CHILD_FEATURES]);

        parFeaturesList.push_back(feature);
    }
}

void nbProjectEntitiesLoader::parseAndFillPropGroups(std::list<std::shared_ptr<nbPropertyGroup>> &parPropGroupsList,
                                                     const YAML::Node &parParentPropGroupsArrNode) {
    for (const auto & currentNode : parParentPropGroupsArrNode){
        std::string name = currentNode[nb_consts::recipe::feature::YAML_PROPS_FIELD_GROUP_NAME].as<std::string>();
        std::shared_ptr<nbPropertyGroup> propGroup = std::make_shared<nbPropertyGroup>(name);
        parseAndFillPropsInGroup(propGroup->Props, currentNode[nb_consts::recipe::feature::YAML_PROPS_FIELD_ARR]);
        parPropGroupsList.push_back(propGroup);
    }
}

void nbProjectEntitiesLoader::parseAndFillPropsInGroup(std::list<std::shared_ptr<nbProperty>> &parPropsList,
                                                       const YAML::Node &parPropsArrNode) {
    
}







