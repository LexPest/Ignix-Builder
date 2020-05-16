//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBPDEP_AVAILABLEONEMACRO_S_H
#define NERP_BUILDER_WX_NBPDEP_AVAILABLEONEMACRO_S_H

#include <nb/data/props/nbProperty.h>
#include <nb/data/dependencies/in_recipes/nbPropertyDependency.h>
#include <nb/data/dependencies/in_recipes/nbTargetsContainedDependency.h>

namespace nerp {
    class nbPDep_AvailableOnEMacro_s : public nbPropertyDependency, public nbTargetsContainedDependency<nbProperty>{
    public:
        const std::function<bool()> &getIsSatisfiedFunction() override;

        const nbEDependencyGroupKind_InRecipe getDepGroupKind() override;
    };
}


#endif //NERP_BUILDER_WX_NBPDEP_AVAILABLEONEMACRO_S_H
