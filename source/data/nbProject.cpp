//
// Created by Alexey Mihailov on 2020-03-17.
//

#include "nbProject.h"

nbProject::nbProject(const Version &cVersion, const IterVersion &supportedRecipesIterActualVersion,
                     const std::string &projectName) : CVersion(cVersion), SupportedRecipesIterActualVersion(
        supportedRecipesIterActualVersion), ProjectName(projectName) {}
