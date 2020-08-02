//
// Created by Alexey Mihailov on 17/05/2020.
//

#ifndef NERP_BUILDER_WX_NBGROUPKINDRELATEDDEP_H
#define NERP_BUILDER_WX_NBGROUPKINDRELATEDDEP_H

namespace nerp {
    template<typename GROUP_KIND_T, GROUP_KIND_T val>
    struct nbGroupKindRelatedDep {
        const constexpr GROUP_KIND_T getGroupKind() {return val;}
    };
}

#endif //NERP_BUILDER_WX_NBGROUPKINDRELATEDDEP_H
