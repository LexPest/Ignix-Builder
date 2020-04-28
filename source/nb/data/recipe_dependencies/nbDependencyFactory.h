//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBDEPENDENCYFACTORY_H
#define NERP_BUILDER_WX_NBDEPENDENCYFACTORY_H

#include "nbFeatureDependency.h"
#include "nbPropertyDependency.h"
#include <string>
#include <memory>
#include <yaml-cpp/node/node.h>

namespace nerp {
    class nbDependencyFactory {
    public:
        nbDependencyFactory(const std::shared_ptr<nbProject> &targetProjectContext);

        nbFeatureDependency getFeatureDependency(const YAML::Node &parNode);
        nbPropertyDependency getPropertyDependency(const YAML::Node &parNode);

    private:
        std::shared_ptr<nbProject> targetProjectContext;
    };
}


#endif //NERP_BUILDER_WX_NBDEPENDENCYFACTORY_H
