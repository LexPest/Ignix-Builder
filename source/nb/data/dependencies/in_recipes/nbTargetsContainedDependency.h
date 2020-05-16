//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBTARGETSCONTAINEDDEPENDENCY_H
#define NERP_BUILDER_WX_NBTARGETSCONTAINEDDEPENDENCY_H

#include <list>
#include <utility>
#include <string>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/detail/iterator.h>

namespace nerp {
    template<typename TARGET_T>
    class nbTargetsContainedDependency {
    public:
        std::list<std::pair<std::string, std::shared_ptr<TARGET_T>>> depTargets;
    };
}


#endif //NERP_BUILDER_WX_NBTARGETSCONTAINEDDEPENDENCY_H
