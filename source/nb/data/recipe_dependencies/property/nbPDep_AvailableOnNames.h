//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBPDEP_AVAILABLEONNAMES_H
#define NERP_BUILDER_WX_NBPDEP_AVAILABLEONNAMES_H

#include <nb/data/recipe_dependencies/nbPropertyDependency.h>
#include <memory>
#include <nb/data/nbProperty.h>
#include <list>
#include <utility>
#include <yaml-cpp/node/node.h>
#include <nb/data/recipe_dependencies/nbTargetsContainedDependency.h>

namespace nerp {
    class nbPDep_AvailableOnNames : public nbPropertyDependency, public nbTargetsContainedDependency<nbProperty> {
    public:
        nbPDep_AvailableOnNames(const std::shared_ptr<nbProject> &targetProjectContext,
                                const std::shared_ptr<nbProperty> &targetProperty, const YAML::Node &parTargetsNode);

        std::string getDependsOnMessage() override;

        bool tryResolve() override;

        bool isResolved() override;

        bool checkSatisfiedAndSetValueAndAvailable() override;

        ~nbPDep_AvailableOnNames() override;
    };
}


#endif //NERP_BUILDER_WX_NBPDEP_AVAILABLEONNAMES_H
