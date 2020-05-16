//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBDEPENDENCY_H
#define NERP_BUILDER_NBDEPENDENCY_H

#include <memory>
#include <vector>
#include <iostream>
#include <functional>

namespace nerp {

    class nbDependency {
    public:
        virtual const std::function<bool()>& getIsSatisfiedFunction() = 0;
    };
}



#endif //NERP_BUILDER_NBDEPENDENCY_H
