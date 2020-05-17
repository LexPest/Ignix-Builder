//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBDEPENDENCY_INRECIPE_H
#define NERP_BUILDER_WX_NBDEPENDENCY_INRECIPE_H

#include <nb/data/dependencies/nbDependency.h>
#include <nb/data/dependencies/nbGroupKindRelatedDep.h>
#include "nbEDepGroupKind_InRecipe_ByDepParam.h"
#include "nbEDepGroupKind_InRecipe_DepTarget.h"
#include "nbEDepGroupKind_InRecipe_DepParam.h"
#include "nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve.h"

namespace nerp {
    using depTargetType = nbEDepGroupKind_InRecipe_DepTarget;
    using depParamType = nbEDepGroupKind_InRecipe_DepParam;
    using byDepParamType = nbEDepGroupKind_InRecipe_ByDepParam;
    using resolveSearchCriteriaType = nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve;

    template<depTargetType valDepTarget, depParamType valDepParam, byDepParamType valByDepParam, resolveSearchCriteriaType valSearchCriteriaForResolve>
    class nbDependency_InRecipe : public nbDependency,
            nbGroupKindRelatedDep<depTargetType, valDepTarget>,
            nbGroupKindRelatedDep<depParamType, valDepParam>,
            nbGroupKindRelatedDep<byDepParamType, valByDepParam>,
            nbGroupKindRelatedDep<resolveSearchCriteriaType, valSearchCriteriaForResolve>
            {
    };
}

#endif //NERP_BUILDER_WX_NBDEPENDENCY_INRECIPE_H
