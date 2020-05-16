//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#include "nbPDep_AvailableOnNames.h"
#include <nb/data/props/nbIBoolValProperty.h>
#include <nb/data/dependencies/in_recipes/common_funcs/nbDep_AvailableOn_Funcs.h>

using namespace nerp;

//nbPDep_AvailableOnNames::nbPDep_AvailableOnNames(const std::shared_ptr<nbProject> &targetProjectContext,
//                                                 const std::shared_ptr<nbProperty> &targetProperty,
//                                                 const YAML::Node &parTargetsNode) : nbPropertyDependency(
//        targetProjectContext, targetProperty), nbTargetsContainedDependency(parTargetsNode) {}
//
//std::string nbPDep_AvailableOnNames::getDependsOnMessage() {
//    std::string retString = "By properties names: ";
//    for (auto it : depTargets){
//        retString += it.first + ' ';
//    }
//    return std::move(retString);
//}
//
//bool nbPDep_AvailableOnNames::tryResolve() {
//    bool retResult = true;
//    for (auto it : depTargets){
//        if (it.second == nullptr){
//            it.second = targetProperty->PlacedInGroup->getPropByName(it.first);
//            if (it.second == nullptr) {
//                retResult = false;
//            }
//        }
//    }
//    return retResult;
//}
//
//bool nbPDep_AvailableOnNames::isResolved() {
//    for (auto it : depTargets){
//        if (it.second == nullptr){
//            return false;
//        }
//    }
//    return true;
//}
//
//bool nbPDep_AvailableOnNames::checkSatisfiedAndSetValueAndAvailable() {
//    bool retResult = true;
//
//    for (auto it : depTargets){
//        if (it.second == nullptr){
//            retResult = false;
//            break;
//        } else {
//            if (!(it.second->IsAvailable && it.second->getDataBoolFlag())){
//                retResult = false;
//                break;
//            }
//        }
//    }
//
//    if (retResult){
//        targetProperty->IsAvailable = true;
//    } else {
//        targetProperty->IsAvailable = false;
//    }
//
//    return retResult;
//}

//nbPDep_AvailableOnNames::~nbPDep_AvailableOnNames() {
//
//}



const std::function<bool()> &nbPDep_AvailableOnNames::getIsSatisfiedFunction() {
    static const std::function<bool()> resolveFunc = [depTargets = depTargets](){
       return hIsSatisfied<nbProperty, nbIBoolValProperty>(depTargets);
    };
    return resolveFunc;
}

const nbEDependencyGroupKind_InRecipe nbPDep_AvailableOnNames::getDepGroupKind() {
    return nbEDependencyGroupKind_InRecipe::Availability;
}
