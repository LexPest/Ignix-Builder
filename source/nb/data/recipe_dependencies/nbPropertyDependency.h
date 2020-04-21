//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBPROPERTYDEPENDENCY_H
#define NERP_BUILDER_WX_NBPROPERTYDEPENDENCY_H

#include <nb/data/nbDependency.h>
#include <memory>
#include <nb/data/nbProperty.h>

namespace nerp {
    class nbPropertyDependency : public nbDependency {
    public:
        nbPropertyDependency(const std::shared_ptr<nbProject> &targetProjectContext,
                             const std::shared_ptr<nbProperty> &targetProperty);

    protected:
        std::shared_ptr<nbProperty> targetProperty;
    };
}


#endif //NERP_BUILDER_WX_NBPROPERTYDEPENDENCY_H
