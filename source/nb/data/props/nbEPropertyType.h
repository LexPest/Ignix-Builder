//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBEPROPERTYTYPE_H
#define NERP_BUILDER_NBEPROPERTYTYPE_H

namespace nerp {
    enum class nbEPropertyType : int8_t {
        _Undefined,
        BoolFlag,
        UnicodeString,
        NumInteger,
        NumUInteger,
        NumDouble
    };
}

#endif //NERP_BUILDER_NBEPROPERTYTYPE_H
