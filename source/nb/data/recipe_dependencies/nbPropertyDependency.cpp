//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#include "nbPropertyDependency.h"

nerp::nbPropertyDependency::nbPropertyDependency(const std::shared_ptr<nerp::nbProject> &targetProjectContext,
                                                 const std::shared_ptr<nerp::nbProperty> &targetProperty)
        : nbDependency(targetProjectContext), targetProperty(targetProperty) {}
