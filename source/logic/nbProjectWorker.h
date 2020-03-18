//
// Created by Alexey Mihailov on 2020-03-18.
//

#ifndef NERP_BUILDER_NBPROJECTWORKER_H
#define NERP_BUILDER_NBPROJECTWORKER_H

#include <string>
#include <list>
#include <ios>
#include "../common/interface/IObservable.h"
#include "../interface/nbIObserverProjectWorker.h"

class nbProjectWorker : public IObservable<nbIObserverProjectWorker> {

private:
    std::string PathRootFolder;
    std::string PathNBuilderSupport;
    std::string PathNBuilderBuildMacro;
    std::string PathRootTemplateRecipes;
    std::string PathRootUserRecipes;



};


#endif //NERP_BUILDER_NBPROJECTWORKER_H
