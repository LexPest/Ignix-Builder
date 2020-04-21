//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBFEATUREDEPENDENCY_H
#define NERP_BUILDER_WX_NBFEATUREDEPENDENCY_H

#include <nb/data/nbDependency.h>
#include <memory>
namespace nerp {
    class nbFeatureDependency : public nbDependency {
    public:
        nbFeatureDependency(const std::shared_ptr<nbProject> &targetProjectContext,
                            const std::shared_ptr<nbFeature> &targetFeature);

    protected:
        std::shared_ptr<nbFeature> targetFeature;
    };
}


#endif //NERP_BUILDER_WX_NBFEATUREDEPENDENCY_H
