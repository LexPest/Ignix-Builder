//
// Created by Alexey Mihailov on 17/05/2020.
//

#include "nbProjectDependenciesResolver.h"

nerp::UnresolvedDependency::UnresolvedDependency(nerp::nbEDepGroupKind_ByDepParam byDepParamValue,
                                                 nerp::nbEDepGroupKind_DepParam depParamValue,
                                                 nerp::nbEDepGroupKind_SearchCriteriaForDepResolve searchCriteriaValue) : byDepParamValue(
        byDepParamValue), depParamValue(depParamValue), searchCriteriaValue(searchCriteriaValue) {}

nerp::ResolvedDependency::ResolvedDependency(nerp::nbEDepGroupKind_ByDepParam byDepParamValue) : byDepParamValue(
        byDepParamValue){}


nerp::DependenciesForConcreteElement::DependenciesForConcreteElement() {}

