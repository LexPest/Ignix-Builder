//
// Created by Alexey Mihailov
//

#include "nbProjectEntitiesLoader.h"
#include <nb/consts/nbProjectStructConsts.h>
#include <boost/algorithm/string.hpp>
#include <nb/data/props/concrete_types/nbProperty_BoolFlag.h>
#include <nb/data/props/concrete_types/nbProperty_UnicodeString.h>
#include <nb/data/props/concrete_types/nbProperty_NumInteger.h>
#include <nb/data/props/concrete_types/nbProperty_NumUInteger.h>
#include <nb/data/props/concrete_types/nbProperty_NumDouble.h>

using namespace nerp;
std::shared_ptr<nbProject> nbProjectEntitiesLoader::getProjectFromYAML(const YAML::Node &parProjectSupportNodeFile) {
    Version minSupportedVer = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_NBVERSION].as<std::string>();
    IterVersion curRecipesIterVersion = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_SUPPORTED_RECIPES_ITERATION_ACTUAL_VERSION].as<std::string>();
    std::string projectName = parProjectSupportNodeFile[nb_consts::support::YAML_FIELD_PROJECT_NAME].as<std::string>();

    return std::make_shared<nbProject>(minSupportedVer, curRecipesIterVersion, std::move(projectName));
}

std::shared_ptr<nbRecipe>
nbProjectEntitiesLoader::getProjectRecipe(nbOpenedProjectHandler& parProjHandler, nbERecipeKind parRecipeKind, const YAML::Node &parRecipeNodeFile) {
    Version recipeFormatVer = parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_RECIPE_NAME].as<std::string>();
    IterVersion recipeIterVer = parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_ITERACTION_VERSION].as<std::string>();
    std::string recipeName = parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_RECIPE_NAME].as<std::string>();

    std::shared_ptr<nbRecipe> recipe = std::make_shared<nbRecipe>(recipeFormatVer, recipeIterVer, std::move(recipeName), parRecipeKind);

    parseAndFillFeatures(parProjHandler, recipe->FeaturesRoot, parRecipeNodeFile[nb_consts::recipe::YAML_FIELD_FEATURES_ARR]);

    return std::move(recipe);
}

void nbProjectEntitiesLoader::parseAndFillFeatures(nbOpenedProjectHandler& parProjHandler, std::list<std::shared_ptr<nbFeature>> &parFeaturesList,
                                                   const YAML::Node &parParentFeaturesArrNode) {
    for (const auto & currentNode : parParentFeaturesArrNode){
        std::string name = currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_NAME].as<std::string>();
        std::string emacro = currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_EMACRO].as<std::string>();

        std::shared_ptr<nbFeature> feature = std::make_shared<nbFeature>(name, emacro);
        feature->RichDescription = currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_RICHDESCR].as<std::string>();
        feature->IsAvailable.set(true);
        parseAndFillPropGroups(parProjHandler, feature->PropertyGroups, currentNode[nb_consts::recipe::feature::YAML_FIELD_PROP_GROUPS_ARR]);

        //TODO: deps loading


        //recursion here
        parseAndFillFeatures(parProjHandler, feature->ChildFeatures, currentNode[nb_consts::recipe::feature::YAML_FIELD_FEATURE_CHILD_FEATURES]);

        parFeaturesList.push_back(feature);
    }
}

void nbProjectEntitiesLoader::parseAndFillPropGroups(nbOpenedProjectHandler& parProjHandler, std::list<std::shared_ptr<nbPropertyGroup>> &parPropGroupsList,
                                                     const YAML::Node &parParentPropGroupsArrNode) {
    for (const auto & currentNode : parParentPropGroupsArrNode){
        std::string name = currentNode[nb_consts::recipe::feature::YAML_PROPS_FIELD_GROUP_NAME].as<std::string>();
        std::shared_ptr<nbPropertyGroup> propGroup = std::make_shared<nbPropertyGroup>(name);
        parseAndFillPropsInGroup(parProjHandler, propGroup->Props, currentNode[nb_consts::recipe::feature::YAML_PROPS_FIELD_ARR]);
        parPropGroupsList.push_back(propGroup);
    }
}

void nbProjectEntitiesLoader::parseAndFillPropsInGroup(nbOpenedProjectHandler& parProjHandler, std::list<std::shared_ptr<nbProperty>> &parPropsList,
                                                       const YAML::Node &parPropsArrNode) {
    for (const auto & currentNode : parPropsArrNode){
        std::string propTypeInString = currentNode[nb_consts::recipe::feature::propelem::YAML_PROPELEM_TYPE].as<std::string>();
        boost::algorithm::to_lower(propTypeInString);

        std::string propName = currentNode[nb_consts::recipe::feature::propelem::YAML_PROPELEM_NAME].as<std::string>();
        std::string propEMacro = currentNode[nb_consts::recipe::feature::propelem::YAML_PROPELEM_EMACRO].as<std::string>();
        std::string dataInString = currentNode[nb_consts::recipe::feature::propelem::YAML_PROPELEM_EMACRO].as<std::string>();
        //TODO: deps loading

        //TODO: conversion exception handling
        nbEPropertyType parsedPropType = getPropertyTypeFromString(propTypeInString);

        std::shared_ptr<nbProperty> createdProp;

        switch (parsedPropType){
            case nbEPropertyType::BoolFlag: {
                boost::algorithm::to_lower(dataInString);
                bool dataVal = getChkboxBoolValueFromString(dataInString);
                createdProp = std::make_shared<nbProperty_BoolFlag>(propName, propEMacro, dataVal);
                break;
            }
            case nbEPropertyType::UnicodeString: {
                createdProp = std::make_shared<nbProperty_UnicodeString>(propName, propEMacro, dataInString);
                break;
            }
            case nbEPropertyType::NumInteger: {
                int64_t dataVal;
                std::istringstream iss(dataInString);
                iss >> dataVal;
                createdProp = std::make_shared<nbProperty_NumInteger>(propName, propEMacro, dataVal);
                break;
            }
            case nbEPropertyType::NumUInteger: {
                uint64_t dataVal;
                std::istringstream iss(dataInString);
                iss >> dataVal;
                createdProp = std::make_shared<nbProperty_NumUInteger>(propName, propEMacro, dataVal);
                break;
            }
            case nbEPropertyType::NumDouble: {
                double dataVal;
                std::istringstream iss(dataInString);
                iss >> dataVal;
                createdProp = std::make_shared<nbProperty_NumDouble>(propName, propEMacro, dataVal);
                break;
            }
        }

        if (createdProp != nullptr){
            parPropsList.push_back(createdProp);
        }
    }
}








