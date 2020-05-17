cmake_minimum_required(VERSION 3.12)
project(Nerp-Builder)

set(CMAKE_CXX_STANDARD 14)

function(CHECK_GIT_SUBMODULE_AND_BUILD argPath)
    if (NOT EXISTS ${argPath}/CMakeLists.txt)
        message("Initiating git submodule, reason: ${argPath}")
        execute_process(
                COMMAND git submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    endif ()

    message("Adding subdirectory: ${argPath}")
    add_subdirectory(${argPath})
endfunction()

# Set version
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 1)
SET(VERSION_PATCH 1)


SET(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Add include folders
include_directories(source)


# Define a variable containing a list of source files for the project
set(SRC_FILES
        source/nb/data/project/nbProject.cpp source/nb/data/project/nbProject.h source/nb/data/project/nbRecipe.cpp source/nb/data/project/nbRecipe.h source/nb/data/props/nbPropertyGroup.cpp source/nb/data/props/nbPropertyGroup.h
        source/nb/data/props/nbProperty.cpp source/nb/data/props/nbProperty.h source/nb/data/props/nbEPropertyType.h source/nb/data/project/nbERecipeKind.h source/nb/logic/nbProjectWorker.cpp source/nb/logic/nbProjectWorker.h source/nb/data/features/nbFeature.cpp source/nb/data/features/nbFeature.h
        source/nb/data/dependencies/nbDependency.cpp source/nb/data/dependencies/nbDependency.h
        source/nb/logic/nbOpenedProjectHandler.cpp source/nb/logic/nbOpenedProjectHandler.h source/nb/logic/request_data/nbReqProjectLoadingResult.cpp source/nb/logic/request_data/nbReqProjectLoadingResult.h
        source/nb/logic/request_data/nbReqProjectSavingResult.cpp source/nb/logic/request_data/nbReqProjectSavingResult.h
        source/nb/consts/nbProjectStructConsts.h
        source/nb/logic/factories/nbProjectEntitiesLoader.cpp source/nb/logic/factories/nbProjectEntitiesLoader.h source/nb/logic/nbProjectHandlerIObserver.cpp source/nb/logic/nbProjectHandlerIObserver.h source/nb/data/dependencies/in_recipes/feature/nbFDep_AvailableOnNames.cpp source/nb/data/dependencies/in_recipes/feature/nbFDep_AvailableOnNames.h source/nb/data/dependencies/in_recipes/property/nbPDep_AvailableOnNames.cpp source/nb/data/dependencies/in_recipes/property/nbPDep_AvailableOnNames.h source/nb/data/dependencies/in_recipes/property/nbPDep_AvailableOnEMacro_s.cpp source/nb/data/dependencies/in_recipes/property/nbPDep_AvailableOnEMacro_s.h source/nb/data/dependencies/in_recipes/nbTargetsContainedDependency.cpp source/nb/data/dependencies/in_recipes/nbTargetsContainedDependency.h source/nb/data/dependencies/in_recipes/common_funcs/nbDep_AvailableOn_Funcs.cpp source/nb/data/dependencies/in_recipes/common_funcs/nbDep_AvailableOn_Funcs.h source/nb/data/dependencies/in_recipes/nbEDepGroupKind_InRecipe_ByDepParam.h source/nb/logic/dependencies/factories/nbDependencies_Logic_Funcs.cpp source/nb/logic/dependencies/factories/nbDependencies_Logic_Funcs.h source/nb/data/props/nbIBoolValProperty.cpp source/nb/data/props/nbIBoolValProperty.h source/nb/logic/dependencies/nbProjectDependenciesResolver.cpp source/nb/logic/dependencies/nbProjectDependenciesResolver.h source/nb/data/dependencies/in_recipes/nbDependency_InRecipe.h source/nb/data/dependencies/nbGroupKindRelatedDep.cpp source/nb/data/dependencies/nbGroupKindRelatedDep.h source/nb/data/dependencies/in_recipes/nbEDepGroupKind_InRecipe_DepTarget.h source/nb/data/dependencies/in_recipes/nbEDepGroupKind_InRecipe_DepParam.h source/nb/data/dependencies/in_recipes/nbEDepGroupKind_InRecipe_SearchCriteriaForDepResolve.h)


add_library(Nerp-Builder STATIC ${SRC_FILES})


# INCLUDE DEPENDENCIES

# Including Boost
add_definitions(-DBOOST_LOG_DYN_LINK=1)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED COMPONENTS log filesystem system exception REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS})


# Including yaml-cpp
set(YAML_CPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/yaml-cpp)
CHECK_GIT_SUBMODULE_AND_BUILD(${YAML_CPP_DIR})
include_directories(${YAML_CPP_DIR}/include)
add_dependencies(${PROJECT_NAME} yaml-cpp)
target_link_libraries(${PROJECT_NAME} yaml-cpp)


# Including Nerp-Essentials
set(NESS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/nerp-essentials)
CHECK_GIT_SUBMODULE_AND_BUILD(${NESS_DIR})
include_directories(${NESS_DIR}/source)
add_dependencies(${PROJECT_NAME} Nerp-Essentials)
target_link_libraries(${PROJECT_NAME} Nerp-Essentials)

