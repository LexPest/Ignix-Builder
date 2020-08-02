//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBREQPROJECTLOADINGRESULT_H
#define NERP_BUILDER_NBREQPROJECTLOADINGRESULT_H

#include <string>
#include "nb/logic/opened_handlers/nbOpenedProjectHandler.h"
namespace nerp {
    class nbOpenedProjectHandler;

    struct nbReqProjectLoadingResult {
    public:
        std::shared_ptr<nbOpenedProjectHandler> LoadedProjectHandler;
        std::string Message;

        explicit nbReqProjectLoadingResult(const std::shared_ptr<nbOpenedProjectHandler> &loadedProjectHandler,
                                  const std::string &message);
        bool isSuccess();
    };
}

#endif //NERP_BUILDER_NBREQPROJECTLOADINGRESULT_H
