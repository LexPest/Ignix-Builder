//
// Created by Alexey Mihailov
//

#include "EvNbWxFormCustomAction.h"


wxEvent *EvNbWxFormCustomAction::Clone() const {
    return new EvNbWxFormCustomAction(*this);
}

EvNbWxFormCustomAction::EvNbWxFormCustomAction(int winid, wxEventType commandType,
                                               const std::function<void()> &formActionsPerform) : wxEvent(winid,
                                                                                                          commandType),
                                                                                                  formActionsPerform(
                                                                                                          formActionsPerform) {}
