//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBREQPROJECTSAVINGRESULT_H
#define NERP_BUILDER_NBREQPROJECTSAVINGRESULT_H

#include <string>
namespace nerp {
    struct nbReqProjectSavingResult {

        bool IsSuccess;
        std::string Message;

        nbReqProjectSavingResult(bool isSuccess, const std::string &message);
    };
}

#endif //NERP_BUILDER_NBREQPROJECTSAVINGRESULT_H
