//
// Created by LexPest on 03.03.2020.
//

#include "nbWxApp.h"
#include "nbWxForms.h"
#include "nbWxAppWorkers.h"
#include <wx/sharedptr.h>

std::shared_ptr<nbWxObserverProjectWorker> nbWxAppWorkers::MProjectWorker;
wxWeakRef<nbFormMainExt> nbWxAppWorkers::MMainForm;

bool nbWxApp::OnInit() {
    wxInitAllImageHandlers();
    //nbFormMain* mainForm = new nbFormMain(NULL);
    //std::shared_ptr<nbFormMain> mainForm = std::make_shared<nbFormMain>(NULL);
    nbWxAppWorkers::MMainForm = new nbFormMainExt(NULL);
    std::shared_ptr<nbProjectWorker> projectWorkerMain = std::make_shared<nbProjectWorker>();
    nbWxAppWorkers::MProjectWorker = std::make_shared<nbWxObserverProjectWorker>(projectWorkerMain, nbWxAppWorkers::MMainForm);
    nbWxAppWorkers::MProjectWorker->InitObserver(nbWxAppWorkers::MProjectWorker);

    nbWxAppWorkers::MMainForm->Show();

    nbWxAppWorkers::MProjectWorker->start_loadProject();
    return true;
}
