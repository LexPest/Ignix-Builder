//
// Created by Alexey Mihailov on 2020-03-18.
//

#include "nbRecipe.h"

nbRecipe::nbRecipe(const Version &formatVersion, const IterVersion &iterationVersion, const std::string &name,
                   nbERecipeKind cKind) : FormatVersion(formatVersion), IterationVersion(iterationVersion), Name(name),
                                          CKind(cKind) {}
