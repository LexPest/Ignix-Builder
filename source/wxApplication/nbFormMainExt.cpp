//
// Created by Alexey Mihailov
//

#include "nbFormMainExt.h"

wxDEFINE_EVENT(EV_PROJECT_LOAD_DONE, EvProjectLoadDone);
wxDEFINE_EVENT(EV_NB_WX_CUSTOM_ACTION, EvNbWxFormCustomAction);

/*
wxBEGIN_EVENT_TABLE(nbFormMainExt, nbFormMain)
                EV_PROJECT_LOAD_DONE(ID_MY_WINDOW, nbFormMainExt::OnEvLoadProjectDone)
wxEND_EVENT_TABLE()
*/
nbFormMainExt::nbFormMainExt(wxWindow *parent) : nbFormMain(parent) {
    Bind(EV_PROJECT_LOAD_DONE,&nbFormMainExt::OnEvLoadProjectDone,this);
    Bind(EV_NB_WX_CUSTOM_ACTION,&nbFormMainExt::OnEvNbWxCustomAction,this);
   // std::cout<<"Binding completed!"<<std::endl;
}

void nbFormMainExt::OnEvLoadProjectDone(EvProjectLoadDone &event) {
    std::cout<<"Loading Done!"<<std::endl;
  //  m_staticText4->SetLabelText("Loading Done!");
}

void nbFormMainExt::OnEvNbWxCustomAction(EvNbWxFormCustomAction &event) {
    event.formActionsPerform();
}

void nbFormMainExt::SendCustomActionsEvent(std::function<void(void)> actions) {
    EvNbWxFormCustomAction* customEv = new EvNbWxFormCustomAction(GetId(), EV_NB_WX_CUSTOM_ACTION, actions);
    GetEventHandler()->QueueEvent(customEv);
}

void nbFormMainExt::LinkOpenedInFormHandler(std::shared_ptr<nbWxProjectOpenedInForm> parLinkedOpenedInFormHandler) {
    linkedOpenedInFormHandler = parLinkedOpenedInFormHandler;
}

void nbFormMainExt::sourceDirChanged(wxFileDirPickerEvent &event) {
    nbFormMain::sourceDirChanged(event);
    if (linkedOpenedInFormHandler != nullptr){
        linkedOpenedInFormHandler->loadProject(event.GetPath().ToStdString());
    }
}






