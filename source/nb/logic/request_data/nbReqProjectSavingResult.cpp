//
// Created by Alexey Mihailov
//

#include "nbReqProjectSavingResult.h"
using namespace nerp;
nbReqProjectSavingResult::nbReqProjectSavingResult(bool isSuccess, const std::string &message) : IsSuccess(isSuccess),
                                                                                                 Message(message) {}
