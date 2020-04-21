//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBFEATURE_H
#define NERP_BUILDER_NBFEATURE_H

#include <string>
#include <list>
#include <vector>
#include "nbPropertyGroup.h"
#include "nbDependency.h"
namespace nerp {
    struct nbDependency;

    struct nbFeature {
        std::string CName;
        std::string EMacroName;
        std::string RichDescription;
        std::vector<nbDependency> RequiredDependencies;

        std::list<nbFeature> ChildFeatures;
        std::list<nbPropertyGroup> PropertyGroups;


        nbFeature(const std::string &cName, const std::string &eMacroName);
    };
}

#endif //NERP_BUILDER_NBFEATURE_H
