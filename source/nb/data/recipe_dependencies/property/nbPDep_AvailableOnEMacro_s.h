//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBPDEP_AVAILABLEONEMACRO_S_H
#define NERP_BUILDER_WX_NBPDEP_AVAILABLEONEMACRO_S_H

#include <nb/data/recipe_dependencies/nbPropertyDependency.h>
#include <nb/data/recipe_dependencies/nbTargetsContainedDependency.h>

namespace nerp {
    class nbPDep_AvailableOnEMacro_s : public nbPropertyDependency, public nbTargetsContainedDependency<nbProperty>{
    public:
        std::string getDependsOnMessage() override;

        bool tryResolve() override;

        bool isResolved() override;

        bool checkSatisfiedAndSetValueAndAvailable() override;

        ~nbPDep_AvailableOnEMacro_s() override;

        nbPDep_AvailableOnEMacro_s(const std::shared_ptr<nbProject> &targetProjectContext,
                                   const std::shared_ptr<nbProperty> &targetProperty, const YAML::Node &parTargetsNode);
    };
}


#endif //NERP_BUILDER_WX_NBPDEP_AVAILABLEONEMACRO_S_H
