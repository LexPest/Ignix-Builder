cmake_minimum_required(VERSION 3.12)
project(Nerp-Builder)

# AVAILABLE CONFIGS:
# Debug
# Release
# ReleaseDistrib

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

function(SET_EXPORT_RESOURCES_DIR)
    if (APPLE)
        set(EXPORT_RESOURCES_DIR  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources/app_res  PARENT_SCOPE)
    #elseif (WIN32)
    else()
        set(EXPORT_RESOURCES_DIR  ${CMAKE_CURRENT_BINARY_DIR}/app_res  PARENT_SCOPE)
    endif()



endfunction()

set(CMAKE_CXX_STANDARD 14)

# Set version
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 1)
SET(VERSION_PATCH 1)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message(" ")
    message("CMAKE IN DEBUG MODE")
    message(" ")
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    message(" ")
    message("CMAKE IN RELEASE MODE")
    message(" ")
endif ()

SET(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Define a variable containing a list of source files for the project
set(SRC_FILES
        source/wxApplication/nbWxApp.cpp
        source/wxApplication/nbWxApp.h
        source/wxApplication/nbWxForms.cpp
        source/wxApplication/nbWxForms.h
        source/data/nbProject.cpp source/data/nbProject.h source/common/data/Version.cpp source/common/data/Version.h source/common/data/IterVersion.cpp source/common/data/IterVersion.h source/data/nbRecipe.cpp source/data/nbRecipe.h source/data/nbPropertyGroup.cpp source/data/nbPropertyGroup.h
        source/data/nbProperty.cpp source/data/nbProperty.h source/data/nbEPropertyType.h source/data/nbERecipeKind.h source/logic/nbProjectWorker.cpp source/logic/nbProjectWorker.h source/common/interface/IObservable.cpp source/common/interface/IObservable.h source/data/nbFeature.cpp source/data/nbFeature.h
        source/data/nbDependency.cpp source/data/nbDependency.h source/wxApplication/nbWxProjectOpenedInForm.cpp source/wxApplication/nbWxProjectOpenedInForm.h source/common/interface/ILinkedObserver.cpp source/common/interface/ILinkedObserver.h source/wxApplication/nbWxAppGlobals.cpp source/wxApplication/nbWxAppGlobals.h
        source/logic/nbOpenedProjectHandler.cpp source/logic/nbOpenedProjectHandler.h source/wxApplication/nbFormMainExt.cpp source/wxApplication/nbFormMainExt.h source/wxApplication/events/EvProjectLoadDone.cpp source/wxApplication/events/EvProjectLoadDone.h source/wxApplication/nbWxProjectOpenedSimple.cpp
        source/wxApplication/nbWxProjectOpenedSimple.h source/logic/request_data/nbReqProjectLoadingResult.cpp source/logic/request_data/nbReqProjectLoadingResult.h source/logic/request_data/nbReqProjectSavingResult.cpp source/logic/request_data/nbReqProjectSavingResult.h source/wxApplication/nbWxFormElementsBlockingMechanism.cpp
        source/wxApplication/nbWxFormElementsBlockingMechanism.h source/wxApplication/nbWxFormElementBlockObject.cpp source/wxApplication/nbWxFormElementBlockObject.h source/wxApplication/events/EvNbWxFormCustomAction.cpp source/wxApplication/events/EvNbWxFormCustomAction.h source/data/consts/nbProjectStructConsts.h
        source/logic/factories/nbProjectEntitiesLoader.cpp source/logic/factories/nbProjectEntitiesLoader.h source/logic/nbProjectHandlerIObserver.cpp source/logic/nbProjectHandlerIObserver.h source/wxApplication/nbStartupAnimExt.cpp source/wxApplication/nbStartupAnimExt.h)

if (WIN32)
    # Include a RC file for windows
    #list(APPEND SRC_FILES ../sample.rc)
elseif (APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES platform/macosx/NerpaDevIcon.icns)
endif ()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable


if (APPLE)
    #target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/include_lib/libyaml-cpp/libyaml-cpp.a)

    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/platform/macosx//Info.plist)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RESOURCE "platform/macosx/NerpaDevIcon.icns"
            # Other params do not matter as now it uses separate Info.plist
            )
else ()
    #set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
    #target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/include_lib/libyaml-cpp/libyaml-cppd.dll)
endif ()


# INCLUDE DEPENDENCIES

# Including WxWidgets
if (WIN32)
    message("Building on Win32")
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    include_directories(${WinSDK})
    # set (wxWidgets_CONFIGURATION mswu)
    set(wxUSE_UNICODE 1)
    set(UNICODE 1)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    add_definitions(-DUNICODE -D_UNICODE)
    # Request the required wxWidgets libs
    find_package(wxWidgets 3.1 COMPONENTS scintilla richtext media webview core base net qa propgrid ribbon gl adv html xml xrc aui stc jpeg png REQUIRED)
elseif (APPLE)
    message("Building on Apple")
    # Request the required wxWidgets libs
    find_package(wxWidgets 3.1 COMPONENTS all REQUIRED)
endif ()
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


# Including Boost
add_definitions(-DBOOST_LOG_DYN_LINK=1)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED COMPONENTS log filesystem system exception REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS})


# Including yaml-cpp
set(YAML_CPP_DIR ${CMAKE_SOURCE_DIR}/external/yaml-cpp)
CHECK_GIT_SUBMODULE_AND_BUILD(${YAML_CPP_DIR})
include_directories(${YAML_CPP_DIR}/include)
add_dependencies(${PROJECT_NAME} yaml-cpp)
target_link_libraries(${PROJECT_NAME} yaml-cpp)


# Resources folders
set(RESOURCES_EXPORT ${CMAKE_SOURCE_DIR}/app_res)
SET_EXPORT_RESOURCES_DIR()


# MAKE RELEASE DISTRIBUTION

if (CMAKE_BUILD_TYPE MATCHES ReleaseDistrib)
    if (APPLE)
        message("Libraries distribution with release build set on supported Apple platform")

        add_custom_command(
                TARGET ${PROJECT_NAME}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
        )

        SET(APPS "\${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app") # paths to executables
        SET(DIRS "${CMAKE_PREFIX_PATH}/lib") # directories to search for prerequisites
        INSTALL(CODE "
            include(BundleUtilities)
            set(BU_CHMOD_BUNDLE_ITEMS TRUE)
            fixup_bundle(\"${APPS}\" \"\" \"${DIRS}\")
        ")

    else ()
        message("Libraries distribution with release build not set (unsupported platform)!")
    endif ()


    #Copy resources
        message("Will copy the resources folder")
    add_custom_command(TARGET ${PROJECT_NAME}
                        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_EXPORT} ${EXPORT_RESOURCES_DIR})

else()
    if (WIN32)
        message(WARNING "Create resources symlink manually!")
    else()
        message("Symlinking resources")
        # Symlink to app_res
        add_custom_command(TARGET ${PROJECT_NAME}
                POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${RESOURCES_EXPORT} ${EXPORT_RESOURCES_DIR})
    endif()
endif()