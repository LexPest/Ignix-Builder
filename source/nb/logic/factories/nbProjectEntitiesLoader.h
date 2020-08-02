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

    const static std::map<std::string, nbEDepGroupKind_DepParam> Mapped_StringToDepParam = {
            {"availability", nbEDepGroupKind_DepParam::Availability},
            {"enabled", nbEDepGroupKind_DepParam::SetBoolActive}
    };

    const static std::map<std::string, nbEDepGroupKind_ByDepParam> Mapped_StringToByDepParam = {
            {"on_target_availability", nbEDepGroupKind_ByDepParam::Availability},
            {"on_target_enabled", nbEDepGroupKind_ByDepParam::IsBoolActive}
    };

    const static std::map<std::string, nbEDepGroupKind_SearchCriteriaForDepResolve> Mapped_StringToSearchCriteriaForDepResolve = {
            {"by_name", nbEDepGroupKind_SearchCriteriaForDepResolve::ByName},
            {"by_emacro", nbEDepGroupKind_SearchCriteriaForDepResolve::ByEMacro}
    };

    enum class nbEDepTargetKind {
        Feature,
        Property
    };

    const static std::map<std::string, nbEDepTargetKind> Mapped_StringToDepTargetKind = {
            {"feature", nbEDepTargetKind::Feature},
            {"property", nbEDepTargetKind::Property}
    };
}


namespace nerp {
    class nbProjectEntitiesLoader {
    public:
        static std::shared_ptr<nbProject> getProjectFromYAML(const YAML::Node &parProjectSupportNodeFile);

        static std::shared_ptr<nbRecipe>
        getProjectRecipe(nbOpenedProjectHandler& parProjHandler, nbERecipeKind parRecipeKind, const YAML::Node &parRecipeNodeFile);

        static void parseAndFillFeatures(nbOpenedProjectHandler& parProjHandler, std::list<std::shared_ptr<nbFeature>>& parFeaturesList, const YAML::Node &parParentFeaturesArrNode);

        static void parseAndFillPropGroups(nbOpenedProjectHandler& parProjHandler, std::list<std::shared_ptr<nbPropertyGroup>> &parPropGroupsList,
                                           const YAML::Node &parParentPropGroupsArrNode);

        static void parseAndFillPropsInGroup(nbOpenedProjectHandler& parProjHandler, std::list<std::shared_ptr<nbProperty>> &parPropsList, const YAML::Node &parPropsArrNode);

    private:
        inline static nbEPropertyType getPropertyTypeFromString(const std::string& parLoweredString) {
            return Mapped_StringToEPropertyType.at(parLoweredString);
        }

        inline static bool getChkboxBoolValueFromString(const std::string& parLoweredString){
            return Mapped_StringToChkboxBoolData.at(parLoweredString);
        }

        inline static DependencyAddingParams getDependencyAddingParamsFromDepNode(const YAML::Node &parDepNode) {

        }

    };
}

#endif //NERP_BUILDER_NBPROJECTENTITIESLOADER_H
