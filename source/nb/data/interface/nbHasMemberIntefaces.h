//
// Created by Alexey Mihailov on 25/05/2020.
//

#ifndef NERP_BUILDER_WX_NBHASMEMBERINTEFACES_H
#define NERP_BUILDER_WX_NBHASMEMBERINTEFACES_H

#include <ness/interface/IHasMember.h>
#include <ness/defines/IHasMember_Def.h>
#include <ness/data/Property.h>
#include <string>
namespace nerp {
    __NERP_DEF_GENERATE_I_HAS_MEMBER(std::string, Name)
    __NERP_DEF_GENERATE_I_HAS_PROPERTY_MEMBER(bool, IsAvailable)
}

#endif //NERP_BUILDER_WX_NBHASMEMBERINTEFACES_H
