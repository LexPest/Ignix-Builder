//
// Created by LexPest
//

#include "nbWxApp.h"
#include "nbWxForms.h"
#include "nbWxAppGlobals.h"
#include <wx/sharedptr.h>

std::shared_ptr<nbWxProjectOpenedInForm> nbWxAppGlobals::MProjectWorker;
wxWeakRef<nbFormMainExt> nbWxAppGlobals::MMainForm;
wxWeakRef<nbStartupAnimExt> nbWxAppGlobals::MPanelStartupAnim;

bool nbWxApp::OnInit() {
    wxInitAllImageHandlers();
    nbWxAppGlobals::MMainForm = new nbFormMainExt(NULL);
    nbWxAppGlobals::MProjectWorker = std::make_shared<nbWxProjectOpenedInForm>(nbWxAppGlobals::MMainForm);
    nbWxAppGlobals::MMainForm->LinkOpenedInFormHandler(nbWxAppGlobals::MProjectWorker);

    nbWxAppGlobals::MMainForm->Show();

    nbWxAppGlobals::MPanelStartupAnim = new nbStartupAnimExt(NULL);
    nbWxAppGlobals::MPanelStartupAnim->Show();

    return true;
}
