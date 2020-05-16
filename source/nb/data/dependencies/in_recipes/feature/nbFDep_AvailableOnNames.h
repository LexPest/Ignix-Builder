//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBFDEP_AVAILABLEONNAMES_H
#define NERP_BUILDER_WX_NBFDEP_AVAILABLEONNAMES_H


#include <nb/data/dependencies/in_recipes/nbFeatureDependency.h>
#include <nb/data/dependencies/in_recipes/nbTargetsContainedDependency.h>
#include <nb/data/features/nbFeature.h>

namespace nerp {
    class nbFDep_AvailableOnNames : public nbFeatureDependency, public nbTargetsContainedDependency<nbFeature> {
    public:
        const std::function<bool()> &getIsSatisfiedFunction() override;

        const nbEDependencyGroupKind_InRecipe getDepGroupKind() override;
    };
}


#endif //NERP_BUILDER_WX_NBFDEP_AVAILABLEONNAMES_H
