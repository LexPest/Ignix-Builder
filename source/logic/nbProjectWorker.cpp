//
// Created by Alexey Mihailov
//

#include <thread>
#include "nbProjectWorker.h"
#include <yaml-cpp/yaml.h>
#include "factories/nbProjectEntitiesLoader.h"

#include "../data/consts/nbProjectStructConsts.h"


void nbProjectWorker::loadProject(std::function<void(nbReqProjectLoadingResult)> parEndCallback,
                                  const std::string &parAbsoluteProjectPath) {
    //std::this_thread::sleep_for(std::chrono::seconds(5));

    std::string outMessage = "NONE";
    std::shared_ptr<nbOpenedProjectHandler> outOpenedProjectHandler = nullptr;

    try {
        if (std::filesystem::exists(parAbsoluteProjectPath)) {
            std::filesystem::path projectSupportFilePath = parAbsoluteProjectPath + "/" + nb::FNAME_NBUILDER_SUPPORT;
            if (std::filesystem::exists(projectSupportFilePath)) {
                YAML::Node projectSupportFile = YAML::LoadFile(projectSupportFilePath);
                std::shared_ptr<nbProject> openedProject = nbProjectEntitiesLoader::getProjectFromYAML(projectSupportFile);

                //...

            } else {
                outMessage = "Project file descriptor not exists";
            }
        } else {
            outMessage = "Path not exists";
        }
    } catch (std::runtime_error& err) {
        outMessage = err.what();
    }


    parEndCallback(nbReqProjectLoadingResult(outOpenedProjectHandler, outMessage));
}
