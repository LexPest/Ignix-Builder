//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#include "nbDependencyFactory.h"

using namespace nerp;

nbDependencyFactory::nbDependencyFactory(const std::shared_ptr<nbProject> &targetProjectContext) : targetProjectContext(
        targetProjectContext) {}

nbFeatureDependency nbDependencyFactory::getFeatureDependency(const YAML::Node &parNode) {

}

