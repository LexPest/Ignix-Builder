//
// Created by Alexey Mihailov
//

#include "nbWxProjectOpenedInForm.h"
#include <future>

/*
void nbWxProjectOpenedInForm::n_callback_projectLoadDone(bool parIsSuccess,
                                                           std::shared_ptr<nbOpenedProjectHandler> parProjectHandler,
                                                           std::string message) {
  //  std::this_thread::sleep_for(std::chrono::seconds(5));

  //  std::cout << "Callback called!" << std::endl;


    EvProjectLoadDone* loadDoneEv = new EvProjectLoadDone(linkedForm->GetId(), EV_PROJECT_LOAD_DONE, parIsSuccess, message);
    linkedForm->GetEventHandler()->QueueEvent(loadDoneEv);
}*/

/*
void nbWxProjectOpenedInForm::start_loadProject() {
    //F_ProjectLoading = std::async(std::launch::async, ..., this, true, nullptr, "OK");
}*/


nbWxProjectOpenedInForm::nbWxProjectOpenedInForm(const wxWeakRef<nbFormMainExt> &linkedForm) : linkedForm(linkedForm) {}
