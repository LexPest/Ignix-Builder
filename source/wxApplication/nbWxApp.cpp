//
// Created by LexPest on 03.03.2020.
//

#include "nbWxApp.h"
#include "nbWxForms.h"

bool nbWxApp::OnInit() {
    wxInitAllImageHandlers();
    nbFormMain* mainForm = new nbFormMain(NULL);
    mainForm->Show();
    return true;
}
