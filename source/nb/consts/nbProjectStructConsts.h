//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBPROJECTSTRUCTCONSTS_H
#define NERP_BUILDER_NBPROJECTSTRUCTCONSTS_H

#include <string>
namespace nerp {
    namespace nb_consts {
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

        namespace recipe{
            const std::string YAML_FIELD_FORMAT_VER = "format-version";
            const std::string YAML_FIELD_ITERACTION_VERSION = "iteration-version";
            const std::string YAML_FIELD_RECIPE_NAME = "name";
            const std::string YAML_FIELD_FEATURES_ARR = "features";

            namespace feature {
                const std::string YAML_FIELD_FEATURE_NAME = "name";
                const std::string YAML_FIELD_FEATURE_EMACRO = "emacro";
                const std::string YAML_FIELD_FEATURE_RICHDESCR = "richdescr";
                const std::string YAML_FIELD_FEATURE_DEPS_ARR = "deps";
                const std::string YAML_FIELD_FEATURE_CHILD_FEATURES = "features";

                namespace depends {
                    const std::string YAML_FEATURE_DEPENDS_TYPE_AVAIL_ON_NAME = "available_on_names";
                    const std::string YAML_FEATURE_DEPENDS_TYPE_AVAIL_ON_EMACRO = "available_on_emacro_s";
                    const std::string YAML_FEATURE_DEPENDS_TARGET_ARR = "target";
                }

                const std::string YAML_FIELD_PROP_GROUPS_ARR = "prop_groups";

                const std::string YAML_PROPS_FIELD_GROUP_NAME = "group_name";

                const std::string YAML_PROPS_FIELD_ARR = "props";

                namespace propelem {
                    const std::string YAML_PROPELEM_TYPE = "type";
                    const std::string YAML_PROPELEM_NAME = "name";
                    const std::string YAML_PROPELEM_EMACRO = "emacro";
                    const std::string YAML_PROPELEM_DATA = "data";

                    const std::string YAML_PROPELEM_RICHDESCR = "richdescr";

                    const std::string YAML_PROPELEM_DEPS_ARR = "deps";
                    namespace depends {
                        const std::string YAML_PROPELEM_DEPENDS_TYPE_AVAIL_ON_NAME = "available_on_names";
                        const std::string YAML_PROPELEM_DEPENDS_TYPE_AVAIL_ON_EMACRO = "available_on_emacro_s";
                        const std::string YAML_PROPELEM_DEPENDS_TARGET_ARR = "target";

                    }

                    namespace types {
                        const std::string YAML_PROPELEM_TYPE_STRING = "string";
                        const std::string YAML_PROPELEM_TYPE_CHECKBOX = "chkbox";
                    }
                }

            }
        }

    }
}

#endif //NERP_BUILDER_NBPROJECTSTRUCTCONSTS_H
