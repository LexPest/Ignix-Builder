//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBFEATURE_H
#define NERP_BUILDER_NBFEATURE_H

#include <string>
#include <list>
#include <vector>
#include "nb/data/props/nbPropertyGroup.h"
#include <nb/data/dependencies/nbDependency.h>
#include <ness/data/Property.h>

namespace nerp {
class nbDependency;

    struct nbFeature {
        std::string CName;
        std::string CEMacroName;
        std::string RichDescription;
        std::vector<nbDependency> RequiredDependencies;

        std::list<nbFeature> ChildFeatures;
        std::list<nbPropertyGroup> PropertyGroups;

        Property<bool> IsAvailable;
        bool IsEnabled;

        bool getBoolValue() {return IsEnabled;}

        nbFeature(const std::string &cName, const std::string &eMacroName);
    };
}

#endif //NERP_BUILDER_NBFEATURE_H
