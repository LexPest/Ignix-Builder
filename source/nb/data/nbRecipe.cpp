//
// Created by Alexey Mihailov
//

#include "nbRecipe.h"
using namespace nerp;
nbRecipe::nbRecipe(const Version &formatVersion, const IterVersion &iterationVersion, const std::string &name,
                   nbERecipeKind cKind) : FormatVersion(formatVersion), IterationVersion(iterationVersion), Name(name),
                                          CKind(cKind) {}
