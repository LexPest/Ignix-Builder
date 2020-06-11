//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTENTITIESLOADER_H
#define NERP_BUILDER_NBPROJECTENTITIESLOADER_H

#include <memory>
#include <yaml-cpp/yaml.h>
#include "nb/data/project/nbProject.h"
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
    };
}

#endif //NERP_BUILDER_NBPROJECTENTITIESLOADER_H
