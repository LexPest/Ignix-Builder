//
// Created by Alexey Mihailov on 2020-03-19.
//

#ifndef NERP_BUILDER_NBWXOBSERVERPROJECTWORKER_H
#define NERP_BUILDER_NBWXOBSERVERPROJECTWORKER_H


#include "../interface/nbIObserverProjectWorker.h"
#include "nbWxForms.h"
#include "nbFormMainExt.h"
#include <wx/sharedptr.h>
#include <future>

class nbWxObserverProjectWorker : public nbIObserverProjectWorker, public ILinkedObserver<nbProjectWorker, nbIObserverProjectWorker> {
public:

    nbWxObserverProjectWorker(const std::shared_ptr<nbProjectWorker> &linkedObservable,
                              const wxWeakRef<nbFormMainExt> &linkedForm);

    void n_callback_projectLoadDone(bool parIsSuccess, std::shared_ptr<nbOpenedProjectHandler> parProjectHandler,
                                    std::string message) override;

    void start_loadProject();

private:
    wxWeakRef<nbFormMainExt> linkedForm;

    std::future<void> F_ProjectLoading;

    void formChangeVal();
};


#endif //NERP_BUILDER_NBWXOBSERVERPROJECTWORKER_H
