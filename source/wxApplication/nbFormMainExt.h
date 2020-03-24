//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBFORMMAINEXT_H
#define NERP_BUILDER_NBFORMMAINEXT_H


#include "nbWxForms.h"
#include "events/EvProjectLoadDone.h"
#include "events/EvNbWxFormCustomAction.h"
#include "nbWxProjectOpenedInForm.h"

class nbWxProjectOpenedInForm;

class nbFormMainExt : public nbFormMain {
public:
    nbFormMainExt(wxWindow *parent);

    void OnEvLoadProjectDone(EvProjectLoadDone& event);
    void OnEvNbWxCustomAction(EvNbWxFormCustomAction& event);

    void LinkOpenedInFormHandler(std::shared_ptr<nbWxProjectOpenedInForm> parLinkedOpenedInFormHandler);


    void SendCustomActionsEvent(std::function<void(void)> actions);

protected:
    void sourceDirChanged(wxFileDirPickerEvent &event) override;

private:
    std::shared_ptr<nbWxProjectOpenedInForm> linkedOpenedInFormHandler;
};

wxDECLARE_EVENT(EV_PROJECT_LOAD_DONE, EvProjectLoadDone);
wxDECLARE_EVENT(EV_NB_WX_CUSTOM_ACTION, EvNbWxFormCustomAction);

#endif

