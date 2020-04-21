//
// Created by Alexey Mihailov
//

#include "nbDependency.h"
using namespace nerp;

nbDependency::nbDependency(const std::shared_ptr<nbProject> &targetProjectContext) : targetProjectContext(
        targetProjectContext) {}
