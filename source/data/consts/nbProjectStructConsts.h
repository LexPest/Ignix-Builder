//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTSTRUCTCONSTS_H
#define NERP_BUILDER_NBPROJECTSTRUCTCONSTS_H

#include <string>

namespace nb {
    const std::string FNAME_NBUILDER_SUPPORT = ".nbuilder_support";
    const std::string FMASK_EXTENSION_RECIPE = ".nb_recipe";
    const std::string FNAME_GEN_MACROS_DEFINITIONS = ".nbuilder_build_macro";
    const std::string DIRNAME_TEMPLATE_RECIPES = ".nbuilder_trecipes";
    const std::string DIRNAME_USER_RECIPES = ".nbuilder_urecipes";

    namespace support {
        const std::string YAML_FIELD_NBVERSION = "version";
        const std::string YAML_FIELD_SUPPORTED_RECIPES_ITERATION_ACTUAL_VERSION = "supported-recipes-iter-act-ver";
        const std::string YAML_FIELD_PROJECT_NAME = "project-name";
        //...
    }

}

#endif //NERP_BUILDER_NBPROJECTSTRUCTCONSTS_H
