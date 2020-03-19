//
// Created by Alexey Mihailov on 2020-03-19.
//

#ifndef NERP_BUILDER_NBWXOBSERVERPROJECTWORKER_H
#define NERP_BUILDER_NBWXOBSERVERPROJECTWORKER_H


#include "../interface/nbIObserverProjectWorker.h"
#include "nbWxForms.h"
#include <wx/sharedptr.h>

class nbWxObserverProjectWorker : public nbIObserverProjectWorker, public ILinkedObserver<nbProjectWorker, nbIObserverProjectWorker> {
public:

    nbWxObserverProjectWorker(const std::shared_ptr<nbProjectWorker> &linkedObservable,
                              const wxWeakRef<nbFormMain> &linkedForm);

    void n_projectLoadDone(bool parSuccess, std::string message) override;
private:
    wxWeakRef<nbFormMain> linkedForm;

};


#endif //NERP_BUILDER_NBWXOBSERVERPROJECTWORKER_H
