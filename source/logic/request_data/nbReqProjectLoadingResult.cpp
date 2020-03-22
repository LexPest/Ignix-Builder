//
// Created by Alexey Mihailov
//

#include "nbReqProjectLoadingResult.h"

nbReqProjectLoadingResult::nbReqProjectLoadingResult(
        const std::shared_ptr<nbOpenedProjectHandler> &loadedProjectHandler, const std::string &message)
        : LoadedProjectHandler(loadedProjectHandler), Message(message) {}

bool nbReqProjectLoadingResult::isSuccess() {
    return LoadedProjectHandler != nullptr;
}
