//
// Created by Alexey Mihailov on 2020-03-20.
//

#ifndef NERP_BUILDER_NBFORMMAINEXT_H
#define NERP_BUILDER_NBFORMMAINEXT_H


#include "nbWxForms.h"
#include "events/EvProjectLoadDone.h"

class nbFormMainExt : public nbFormMain {
public:
    nbFormMainExt(wxWindow *parent);

    void OnEvLoadProjectDone(EvProjectLoadDone& event);

};

wxDECLARE_EVENT(EV_PROJECT_LOAD_DONE, EvProjectLoadDone);

#endif

