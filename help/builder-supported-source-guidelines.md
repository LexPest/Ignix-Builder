### Source supported catalog structure:
| Element | Type | Info |
| --- | --- | --- |
| .nbuilder_support | *FILE* | Contains meta info about N-Builder supported version |
| .nbuilder_build_macro | *FILE* | Stores build macro definitions which was generated by recipe |
| .nbuilder_trecipes | *FOLDER* | Stores template recipes for the builder |
| .nbuilder_urecipes | *FOLDER* | Stores user-created recipes |
| *.nb_recipe | *FILES* | Nerp-Builder recipes |

#### .nbuilder_support

Format: __YAML__

**Fields:**
* Nerp-Builder Supported Min Version
* Supported Recipes Iteration Actual Version
* Last User Recipe Opened
* Default Template Recipe
* Build Command (CMake)


#### *.nb_recipe

Format: __YAML__

**Fields:**
* Recipe Format Version
* Recipe Iteration Version
* Recipe Name
* *[LIST]* Properties (Recipe Data)
  * Prop Type
  * Prop Name
  * Prop Data
  * [...]