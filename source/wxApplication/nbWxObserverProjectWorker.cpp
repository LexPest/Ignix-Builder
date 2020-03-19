//
// Created by Alexey Mihailov on 2020-03-19.
//

#include "nbWxObserverProjectWorker.h"
#include <future>


nbWxObserverProjectWorker::nbWxObserverProjectWorker(const std::shared_ptr<nbProjectWorker> &linkedObservable,
                                                     const wxWeakRef<nbFormMainExt> &linkedForm) : ILinkedObserver(
        linkedObservable), linkedForm(linkedForm) {}


void nbWxObserverProjectWorker::formChangeVal(){
    //linkedForm->m_staticText4->SetLabelText("Async Working!");
}

void nbWxObserverProjectWorker::n_callback_projectLoadDone(bool parIsSuccess,
                                                           std::shared_ptr<nbOpenedProjectHandler> parProjectHandler,
                                                           std::string message) {
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Callback called!" << std::endl;

    EvProjectLoadDone* loadDoneEv = new EvProjectLoadDone(linkedForm->GetId(), EV_PROJECT_LOAD_DONE, parIsSuccess, message);

    linkedForm->GetEventHandler()->QueueEvent(loadDoneEv);
}


void nbWxObserverProjectWorker::start_loadProject() {
    F_ProjectLoading = std::async(std::launch::async,&nbWxObserverProjectWorker::n_callback_projectLoadDone, this, true, nullptr, "OK");
}


