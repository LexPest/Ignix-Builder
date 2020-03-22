//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBWXAPPGLOBALS_H
#define NERP_BUILDER_NBWXAPPGLOBALS_H

#include <wx/sharedptr.h>
#include "nbWxProjectOpenedInForm.h"
#include "nbFormMainExt.h"

class nbWxAppGlobals {
public:
    static std::shared_ptr<nbWxProjectOpenedInForm> MProjectWorker;
    static wxWeakRef<nbFormMainExt> MMainForm;
};


#endif //NERP_BUILDER_NBWXAPPGLOBALS_H
