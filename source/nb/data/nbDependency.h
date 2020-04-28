//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBDEPENDENCY_H
#define NERP_BUILDER_NBDEPENDENCY_H

#include <string>
#include "nbProject.h"
#include <memory>

namespace nerp {
    struct nbProject;

    struct nbDependency {
        nbDependency(const std::shared_ptr<nbProject> &targetProjectContext);

        virtual std::string getDependsOnMessage() = 0;
        virtual bool tryResolve() = 0;
        virtual bool isResolved() = 0;

        virtual bool checkSatisfiedAndSetValueAndAvailable() = 0;

        virtual ~nbDependency() = 0;

    protected:
        std::shared_ptr<nbProject> targetProjectContext;
    };
}


#endif //NERP_BUILDER_NBDEPENDENCY_H
