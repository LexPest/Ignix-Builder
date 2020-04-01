//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTWORKER_H
#define NERP_BUILDER_NBPROJECTWORKER_H

#include <string>
#include <list>
#include <ios>
#include <filesystem>
#include "../common/interface/IObservable.h"
#include "request_data/nbReqProjectLoadingResult.h"
#include "request_data/nbReqProjectSavingResult.h"

class nbIObserverProjectWorker;

//static
class nbProjectWorker {

public:
    static void loadProject(std::function<void(nbReqProjectLoadingResult)> parEndCallback, const std::string& parAbsoluteProjectPath);

    static void saveProject(std::function<void(nbReqProjectSavingResult)> parEndCallback, const std::shared_ptr<nbOpenedProjectHandler> parTargetProject);

};


#endif //NERP_BUILDER_NBPROJECTWORKER_H
