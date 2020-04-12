//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBSTARTUPANIMEXT_H
#define NERP_BUILDER_NBSTARTUPANIMEXT_H


#include "nbWxForms.h"
#include <wx/webview.h>

class nbStartupAnimExt : public nbStartupAnim {
public:
    nbStartupAnimExt(wxWindow *parent);
protected:
    wxWebView* m_animWebView;

    void evt_onTimerShowMainForm(wxTimerEvent &event) override;


};


#endif //NERP_BUILDER_NBSTARTUPANIMEXT_H
