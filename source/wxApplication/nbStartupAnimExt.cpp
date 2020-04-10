//
// Created by Alexey Mihailov
//

#include "nbStartupAnimExt.h"


nbStartupAnimExt::nbStartupAnimExt(wxWindow *parent) : nbStartupAnim(parent) {
    wxBoxSizer* webContentSizer;
    webContentSizer = new wxBoxSizer( wxVERTICAL );

    m_animWebView = wxWebView::New(this, wxID_ANY, "https://www.google.com",wxDefaultPosition, wxDefaultSize);
    webContentSizer->Add(m_animWebView, 1, wxEXPAND | wxALL, 0);

    m_animWebView->LoadURL("https://www.google.com");

    this->SetSizer( webContentSizer );
    this->Layout();

}
