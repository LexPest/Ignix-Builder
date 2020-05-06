//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#include "nbPDep_AvailableOnEMacro_s.h"
#include <nb/data/recipe_dependencies/common_funcs/nbDep_AvailableOn_Funcs.h>

nerp::nbPDep_AvailableOnEMacro_s::nbPDep_AvailableOnEMacro_s(
        const std::shared_ptr<nerp::nbProject> &targetProjectContext,
        const std::shared_ptr<nerp::nbProperty> &targetProperty, const YAML::Node &parTargetsNode)
        : nbPropertyDependency(targetProjectContext, targetProperty), nbTargetsContainedDependency(parTargetsNode) {}

std::string nerp::nbPDep_AvailableOnEMacro_s::getDependsOnMessage() {
    return std::move(hGetDependsOnMessage<nbProperty>(depTargets, "By emacro_s names: "));
}

bool nerp::nbPDep_AvailableOnEMacro_s::tryResolve() {
    return hTryResolve<nbProperty>(depTargets,
            [targetProperty = targetProperty]  (const std::string& parName) {
        return targetProperty->PlacedInGroup->getPropByEMacro(parName);
    });
}

bool nerp::nbPDep_AvailableOnEMacro_s::isResolved() {
   return hIsResolved<nbProperty>(depTargets);

}
bool nerp::nbPDep_AvailableOnEMacro_s::checkSatisfiedAndSetValueAndAvailable() {
    auto isSatisfiedFunc = [](const std::shared_ptr<nbProperty> parTarget) {
        return parTarget->IsAvailable && parTarget->getDataBoolFlag();
    };
    auto setValueAndAvailableFunc = [targetProperty = targetProperty](bool isSatisfied){
        targetProperty->IsAvailable = isSatisfied;
    };

    return hCheckSatisfiedAndSetValueAndAvailable<nbProperty>(depTargets, isSatisfiedFunc, setValueAndAvailableFunc);
}

nerp::nbPDep_AvailableOnEMacro_s::~nbPDep_AvailableOnEMacro_s() {

}
