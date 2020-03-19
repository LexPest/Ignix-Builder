//
// Created by Alexey Mihailov on 2020-03-19.
//

#include "nbWxObserverProjectWorker.h"

void nbWxObserverProjectWorker::n_projectLoadDone(bool parSuccess, std::string message) {
}

nbWxObserverProjectWorker::nbWxObserverProjectWorker(const std::shared_ptr<nbProjectWorker> &linkedObservable,
                                                     const wxWeakRef<nbFormMain> &linkedForm) : ILinkedObserver(
        linkedObservable), linkedForm(linkedForm) {}


