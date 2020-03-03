//
// Created by LexPest on 03.03.2020.
//

#include "nbApp.h"
#include "nbForms.h"

bool nbApp::OnInit() {
    wxInitAllImageHandlers();
    nbFormMain* mainForm = new nbFormMain(NULL);
    mainForm->Show();
    return true;
}
