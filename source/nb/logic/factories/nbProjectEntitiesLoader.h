//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTENTITIESLOADER_H
#define NERP_BUILDER_NBPROJECTENTITIESLOADER_H

#include <memory>
#include <yaml-cpp/yaml.h>
#include "nb/data/project/nbProject.h"
#include <nb/data/props/nbEPropertyType.h>
#include <map>

namespace {
    using namespace nerp;
    const static std::map<std::string, nbEPropertyType> Mapped_StringToEPropertyType = {
            {"string", nbEPropertyType::UnicodeString},
            {"chkbox", nbEPropertyType::BoolFlag},
            {"numeric_double", nbEPropertyType::NumDouble},
            {"numeric_signed_integer", nbEPropertyType::NumInteger},
            {"numeric_unsigned_integer", nbEPropertyType::NumUInteger}
    };

    const static std::map<std::string, bool> Mapped_StringToChkboxBoolData = {
            {"false", false},
            {"true", true}
    };
}


namespace nerp {
    class nbProjectEntitiesLoader {
    public:
        static std::shared_ptr<nbProject> getProjectFromYAML(const YAML::Node &parProjectSupportNodeFile);

        static std::shared_ptr<nbRecipe>
        getProjectRecipe(nbERecipeKind parRecipeKind, const YAML::Node &parRecipeNodeFile);

        static void parseAndFillFeatures(std::list<std::shared_ptr<nbFeature>>& parFeaturesList, const YAML::Node &parParentFeaturesArrNode);

        static void parseAndFillPropGroups(std::list<std::shared_ptr<nbPropertyGroup>> &parPropGroupsList,
                                           const YAML::Node &parParentPropGroupsArrNode);

        static void parseAndFillPropsInGroup(std::list<std::shared_ptr<nbProperty>> &parPropsList, const YAML::Node &parPropsArrNode);

        //static void getPropBased
    private:
        inline static nbEPropertyType getPropertyTypeFromString(const std::string& parLoweredString) {
            return Mapped_StringToEPropertyType.at(parLoweredString);
        }

        inline static bool getChkboxBoolValueFromString(const std::string& parLoweredString){
            return Mapped_StringToChkboxBoolData.at(parLoweredString);
        }

    };
}

#endif //NERP_BUILDER_NBPROJECTENTITIESLOADER_H
