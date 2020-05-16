//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBFEATUREDEPENDENCY_H
#define NERP_BUILDER_WX_NBFEATUREDEPENDENCY_H

#include <nb/data/dependencies/nbDependency.h>
#include <memory>
#include <nb/data/features/nbFeature.h>
#include "nbDependency_InRecipe.h"

namespace nerp {
    class nbFeatureDependency : public nbDependency_InRecipe {
    public:
        //std::shared_ptr<nbFeature> targetFeature;

        //nbFeatureDependency(const std::shared_ptr<nbFeature> &targetFeature);
        nbFeatureDependency();
    };
}


#endif //NERP_BUILDER_WX_NBFEATUREDEPENDENCY_H
