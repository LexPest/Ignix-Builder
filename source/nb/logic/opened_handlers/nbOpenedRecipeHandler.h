//
// Created by LexPest on 26.07.2020.
//

#ifndef NERP_BUILDER_WX_NBOPENEDRECIPEHANDLER_H
#define NERP_BUILDER_WX_NBOPENEDRECIPEHANDLER_H

#include <memory>
#include <nb/data/project/nbRecipe.h>
#include <nb/logic/dependencies/nbRecipeDependenciesResolver.h>

namespace nerp {

    class nbOpenedRecipeHandler {
        std::shared_ptr<nbRecipe> CRecipe;


    private:
        std::shared_ptr<nbRecipeDependenciesResolver> _CDepResolver;
        std::shared_ptr<std::list<std::shared_ptr<nbProperty>>> _CRecipeGlobalProps;
        std::shared_ptr<std::list<std::shared_ptr<nbFeature>>> _CRecipeGlobalFeatures;
    };

}

#endif //NERP_BUILDER_WX_NBOPENEDRECIPEHANDLER_H
