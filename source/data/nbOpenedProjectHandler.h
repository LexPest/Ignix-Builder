//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
#define NERP_BUILDER_NBOPENEDPROJECTHANDLER_H

#include <string>
#include "nbProject.h"

class nbOpenedProjectHandler {
public:
    std::string PathRootFolder;
    std::string PathNBuilderSupport;
    std::string PathNBuilderBuildMacro;
    std::string PathRootTemplateRecipes;
    std::string PathRootUserRecipes;

    std::shared_ptr<nbProject> CProject;
};


#endif //NERP_BUILDER_NBOPENEDPROJECTHANDLER_H
