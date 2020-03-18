//
// Created by Alexey Mihailov on 2020-03-18.
//

#ifndef NERP_BUILDER_NBIOBSERVERPROJECTWORKER_H
#define NERP_BUILDER_NBIOBSERVERPROJECTWORKER_H


#include <string>

class nbIObserverProjectWorker {
    virtual void n_projectLoadDone(bool parSuccess, std::string message = "OK") = 0;

};


#endif //NERP_BUILDER_NBIOBSERVERPROJECTWORKER_H
