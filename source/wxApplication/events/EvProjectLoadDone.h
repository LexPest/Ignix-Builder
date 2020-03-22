//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_EVPROJECTLOADDONE_H
#define NERP_BUILDER_EVPROJECTLOADDONE_H


#include <wx/event.h>

class EvProjectLoadDone : public wxEvent {
public:
    EvProjectLoadDone(int winid, wxEventType commandType, const bool isSuccess, const std::string &message);

    virtual wxEvent *Clone() const override;

public:
    const bool isSuccess;
    const std::string message;
};


#endif //NERP_BUILDER_EVPROJECTLOADDONE_H
