//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBDEPENDENCY_INRECIPE_H
#define NERP_BUILDER_WX_NBDEPENDENCY_INRECIPE_H

#include <nb/data/dependencies/nbDependency.h>
#include "nbEDependencyGroupKind_InRecipe.h"

namespace nerp {
    class nbDependency_InRecipe : public nbDependency {
    public:
        virtual const nbEDependencyGroupKind_InRecipe getDepGroupKind() = 0;
    };
}

#endif //NERP_BUILDER_WX_NBDEPENDENCY_INRECIPE_H
