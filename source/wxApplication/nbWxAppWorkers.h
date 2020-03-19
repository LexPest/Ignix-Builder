//
// Created by Alexey Mihailov on 2020-03-19.
//

#ifndef NERP_BUILDER_NBWXAPPWORKERS_H
#define NERP_BUILDER_NBWXAPPWORKERS_H

#include <wx/sharedptr.h>
#include "nbWxObserverProjectWorker.h"

class nbWxAppWorkers {
public:
    static std::shared_ptr<nbWxObserverProjectWorker> MProjectWorker;
    static wxWeakRef<nbFormMain> MMainForm;
};


#endif //NERP_BUILDER_NBWXAPPWORKERS_H
