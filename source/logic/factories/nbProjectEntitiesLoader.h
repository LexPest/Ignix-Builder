//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTENTITIESLOADER_H
#define NERP_BUILDER_NBPROJECTENTITIESLOADER_H

#include <memory>
#include <yaml-cpp/yaml.h>
#include "../../data/nbProject.h"

class nbProjectEntitiesLoader {
public:
    static std::shared_ptr<nbProject> getProjectFromYAML(const YAML::Node& parProjectSupportNodeFile);
    static std::shared_ptr<nbRecipe> getProjectRecipe(nbERecipeKind parRecipeKind, const YAML::Node& parRecipeNodeFile);
};


#endif //NERP_BUILDER_NBPROJECTENTITIESLOADER_H
