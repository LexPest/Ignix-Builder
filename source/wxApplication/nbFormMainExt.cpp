//
// Created by Alexey Mihailov on 2020-03-20.
//

#include "nbFormMainExt.h"

wxDEFINE_EVENT(EV_PROJECT_LOAD_DONE, EvProjectLoadDone);

/*
wxBEGIN_EVENT_TABLE(nbFormMainExt, nbFormMain)
                EV_PROJECT_LOAD_DONE(ID_MY_WINDOW, nbFormMainExt::OnEvLoadProjectDone)
wxEND_EVENT_TABLE()
*/
nbFormMainExt::nbFormMainExt(wxWindow *parent) : nbFormMain(parent) {
    Bind(EV_PROJECT_LOAD_DONE,&nbFormMainExt::OnEvLoadProjectDone,this);
    std::cout<<"Binding completed!"<<std::endl;
}

void nbFormMainExt::OnEvLoadProjectDone(EvProjectLoadDone &event) {
    std::cout<<"Loading Done!"<<std::endl;
    m_staticText4->SetLabelText("Loading Done!");
}




