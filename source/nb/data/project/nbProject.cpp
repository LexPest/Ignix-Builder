//
// Created by Alexey Mihailov
//

#include "nbProject.h"
using namespace nerp;
nbProject::nbProject(const Version &cVersion, const IterVersion &supportedRecipesIterActualVersion,
                     const std::string &projectName) : CVersion(cVersion), SupportedRecipesIterActualVersion(
        supportedRecipesIterActualVersion), ProjectName(projectName) {}
