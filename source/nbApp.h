//
// Created by LexPest on 03.03.2020.
//

#ifndef NERP_BUILDER_NBAPP_H
#define NERP_BUILDER_NBAPP_H

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class nbApp : public wxApp {
public:
    virtual bool OnInit();

};

wxIMPLEMENT_APP(nbApp);
#endif //NERP_BUILDER_NBAPP_H
