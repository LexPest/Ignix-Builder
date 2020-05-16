//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTHANDLERIOBSERVER_H
#define NERP_BUILDER_NBPROJECTHANDLERIOBSERVER_H


#include "nb/data/project/nbERecipeKind.h"
#include "nb/data/project/nbRecipe.h"
namespace nerp {
    struct nbRecipe;

    class nbProjectHandlerIObserver {
    public:
        virtual void Notify_RecipeAdded(const nbRecipe &parAddedRecipe) = 0;
    };
}

#endif //NERP_BUILDER_NBPROJECTHANDLERIOBSERVER_H
