//
// Created by Alexey Mihailov on 17/05/2020.
//

#include "nbProjectDependenciesResolver.h"

nerp::UnresolvedDependency::UnresolvedDependency(nerp::nbEDepGroupKind_ByDepParam byDepParamValue,
                                                 nerp::nbEDepGroupKind_DepParam depParamValue,
                                                 nerp::nbEDepGroupKind_SearchCriteriaForDepResolve searchCriteriaValue,
                                                 nerp::nbEDepGroupKind_DepTarget_Type depOnTarget) : byDepParamValue(
        byDepParamValue), depParamValue(depParamValue), searchCriteriaValue(searchCriteriaValue), depOnTarget(
        depOnTarget) {}

nerp::ResolvedDependency::ResolvedDependency(nerp::nbEDepGroupKind_ByDepParam byDepParamValue,
                                             nerp::nbEDepGroupKind_DepTarget_Type depTarget) : byDepParamValue(
        byDepParamValue), depTarget(depTarget) {}


nerp::DependenciesForConcreteElement::DependenciesForConcreteElement() {}

