//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_EVNBWXFORMCUSTOMACTION_H
#define NERP_BUILDER_EVNBWXFORMCUSTOMACTION_H


#include <wx/event.h>
#include <functional>

class EvNbWxFormCustomAction : public wxEvent {
public:
    EvNbWxFormCustomAction(int winid, wxEventType commandType, const std::function<void()> &formActionsPerform);

    wxEvent *Clone() const override;

    std::function<void(void)> formActionsPerform;
};


#endif //NERP_BUILDER_EVNBWXFORMCUSTOMACTION_H
