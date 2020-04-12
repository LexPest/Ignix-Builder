//
// Created by Alexey Mihailov
//

#include "nbStartupAnimExt.h"
#include "nbWxAppGlobals.h"


nbStartupAnimExt::nbStartupAnimExt(wxWindow *parent) : nbStartupAnim(parent) {
    wxBoxSizer* webContentSizer;
    webContentSizer = new wxBoxSizer( wxVERTICAL );

    m_animWebView = wxWebView::New(this, wxID_ANY, "http://127.0.0.1:8080",wxDefaultPosition, wxDefaultSize);
    webContentSizer->Add(m_animWebView, 1, wxEXPAND | wxALL, 0);



    this->SetSizer( webContentSizer );
    this->Layout();
}

void nbStartupAnimExt::evt_onTimerShowMainForm(wxTimerEvent &event) {
    nbStartupAnim::evt_onTimerShowMainForm(event);
    nbWxAppGlobals::MMainForm->Show();
    this->Close();
}

