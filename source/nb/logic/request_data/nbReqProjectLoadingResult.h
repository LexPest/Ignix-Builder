//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBREQPROJECTLOADINGRESULT_H
#define NERP_BUILDER_NBREQPROJECTLOADINGRESULT_H

#include <string>
#include "nb/logic/nbOpenedProjectHandler.h"
namespace nerp {
    struct nbOpenedProjectHandler;

    struct nbReqProjectLoadingResult {
        std::shared_ptr<nbOpenedProjectHandler> LoadedProjectHandler;
        std::string Message;

        nbReqProjectLoadingResult(const std::shared_ptr<nbOpenedProjectHandler> &loadedProjectHandler,
                                  const std::string &message);

        bool isSuccess();
    };
}

#endif //NERP_BUILDER_NBREQPROJECTLOADINGRESULT_H
