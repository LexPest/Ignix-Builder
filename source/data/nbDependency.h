//
// Created by Alexey Mihailov on 2020-03-19.
//

#ifndef NERP_BUILDER_NBDEPENDENCY_H
#define NERP_BUILDER_NBDEPENDENCY_H

#include <string>
#include "nbProject.h"

struct nbProject;

struct nbDependency {
    virtual std::string getDependsOnMessage() = 0;
    virtual bool isDependencySatisfied(std::shared_ptr<nbProject> parProjectContext) = 0;

    virtual ~nbDependency() = 0;
};


#endif //NERP_BUILDER_NBDEPENDENCY_H
