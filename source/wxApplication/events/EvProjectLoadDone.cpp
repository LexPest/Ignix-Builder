//
// Created by Alexey Mihailov on 2020-03-20.
//

#include "EvProjectLoadDone.h"


EvProjectLoadDone::EvProjectLoadDone(int winid, wxEventType commandType, const bool isSuccess,
                                     const std::string &message) : wxEvent(winid, commandType), isSuccess(isSuccess),
                                                                   message(message) {}

wxEvent *EvProjectLoadDone::Clone() const {
    return new EvProjectLoadDone(*this);
}
