//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBPDEP_AVAILABLEONNAMES_H
#define NERP_BUILDER_WX_NBPDEP_AVAILABLEONNAMES_H

#include <memory>
#include <nb/data/props/nbProperty.h>
#include <list>
#include <utility>
#include <yaml-cpp/node/node.h>
#include <nb/data/dependencies/in_recipes/nbPropertyDependency.h>
#include <nb/data/dependencies/in_recipes/nbTargetsContainedDependency.h>
#include <nb/data/project/nbProject.h>

namespace nerp {
    class nbPDep_AvailableOnNames : public nbPropertyDependency, public nbTargetsContainedDependency<nbProperty> {
    public:
        const std::function<bool()> &getIsSatisfiedFunction() override;

        const nbEDependencyGroupKind_InRecipe getDepGroupKind() override;
    };
}


#endif //NERP_BUILDER_WX_NBPDEP_AVAILABLEONNAMES_H
