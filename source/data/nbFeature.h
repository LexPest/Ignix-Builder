//
// Created by Alexey Mihailov on 2020-03-19.
//

#ifndef NERP_BUILDER_NBFEATURE_H
#define NERP_BUILDER_NBFEATURE_H

#include <string>
#include <list>
#include <vector>
#include "nbPropertyGroup.h"
#include "nbDependency.h"

struct nbDependency;

struct nbFeature {
    std::string CName;
    std::string EMacroName;
    std::string RichDescription;
    std::list<nbFeature> ChildFeatures;
    std::list<nbPropertyGroup> PropertyGroups;
    std::vector<nbDependency> RequiredDependencies;

    nbFeature(const std::string &cName, const std::string &eMacroName);
};


#endif //NERP_BUILDER_NBFEATURE_H
