//
// Created by Alexey Mihailov
//

#include <thread>
#include "nbProjectWorker.h"


void nbProjectWorker::loadProject(std::function<void(nbReqProjectLoadingResult)> parEndCallback,
                                  const std::string &parAbsoluteProjectPath) {
    std::this_thread::sleep_for(std::chrono::seconds(5));

    parEndCallback(nbReqProjectLoadingResult(nullptr, "NONE"));
}
