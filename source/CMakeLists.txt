cmake_minimum_required(VERSION 3.12)
project(Nerp-Builder)

# AVAILABLE CONFIGS:
# Debug
# Release
# ReleaseDistrib


set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message(" ")
    message("CMAKE IN DEBUG MODE")
    message(" ")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message(" ")
    message("CMAKE IN RELEASE MODE")
    message(" ")
endif ()

if (WIN32)
    message("Building on Win32")
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    include_directories(${WinSDK})
    set (wxWidgets_CONFIGURATION mswu)
    set (wxUSE_UNICODE 1)
    set (UNICODE 1)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    add_definitions(-DUNICODE -D_UNICODE)

    # Request the required wxWidgets libs
    find_package(wxWidgets 3.1 COMPONENTS scintilla richtext media webview core base net qa propgrid ribbon gl adv html xml xrc aui stc jpeg png REQUIRED)

elseif(APPLE)
    message("Building on Apple")

    find_package(wxWidgets 3.1 COMPONENTS all REQUIRED)
endif()

# Set version
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 1)
SET(VERSION_PATCH 1)

SET(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Include static libraries
link_directories(../include_lib)

# Include additional headers
include_directories(../include_h)

# Define a variable containing a list of source files for the project
set(SRC_FILES
        wxApplication/nbWxApp.cpp
        wxApplication/nbWxApp.h
        wxApplication/nbWxForms.cpp
        wxApplication/nbWxForms.h
        data/nbProject.cpp data/nbProject.h common/data/Version.cpp common/data/Version.h common/data/IterVersion.cpp common/data/IterVersion.h data/nbRecipe.cpp data/nbRecipe.h data/nbPropertyGroup.cpp data/nbPropertyGroup.h data/nbProperty.cpp data/nbProperty.h data/nbEPropertyType.h data/nbERecipeKind.h logic/nbProjectWorker.cpp logic/nbProjectWorker.h common/interface/IObservable.cpp common/interface/IObservable.h data/nbFeature.cpp data/nbFeature.h data/nbDependency.cpp data/nbDependency.h wxApplication/nbWxProjectOpenedInForm.cpp wxApplication/nbWxProjectOpenedInForm.h common/interface/ILinkedObserver.cpp common/interface/ILinkedObserver.h wxApplication/nbWxAppGlobals.cpp wxApplication/nbWxAppGlobals.h data/nbOpenedProjectHandler.cpp data/nbOpenedProjectHandler.h wxApplication/nbFormMainExt.cpp wxApplication/nbFormMainExt.h wxApplication/events/EvProjectLoadDone.cpp wxApplication/events/EvProjectLoadDone.h wxApplication/nbWxProjectOpenedSimple.cpp wxApplication/nbWxProjectOpenedSimple.h logic/request_data/nbReqProjectLoadingResult.cpp logic/request_data/nbReqProjectLoadingResult.h logic/request_data/nbReqProjectSavingResult.cpp logic/request_data/nbReqProjectSavingResult.h wxApplication/nbWxFormElementsBlockingMechanism.cpp wxApplication/nbWxFormElementsBlockingMechanism.h wxApplication/nbWxFormElementBlockObject.cpp wxApplication/nbWxFormElementBlockObject.h wxApplication/events/EvNbWxFormCustomAction.cpp wxApplication/events/EvNbWxFormCustomAction.h data/consts/nbProjectStructConsts.h logic/factories/nbProjectEntitiesLoader.cpp logic/factories/nbProjectEntitiesLoader.h)

if(WIN32)
    # Include a RC file for windows
    #list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../platform/macosx/NerpaDevIcon.icns)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/../include_lib/libyaml-cpp/libyaml-cpp.a)

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/../platform/macosx//Info.plist)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../platform/macosx/NerpaDevIcon.icns"
            # Other params do not matter as now it uses separate Info.plist
            #MACOSX_BUNDLE_ICON_FILE NerpaDevIcon.icns
            #MACOSX_BUNDLE_COPYRIGHT "Copyright Nerp"
            #MACOSX_BUNDLE_GUI_IDENTIFIER "com.nerpengine.builder"
            )
else()
    #set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
endif()


if (CMAKE_BUILD_TYPE MATCHES ReleaseDistrib)
    if (APPLE)
        message("Libraries distribution with release build set on supported Apple platform")

       add_custom_command(
               TARGET ${PROJECT_NAME}
               POST_BUILD
               COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
       )

       SET( APPS "\${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app" ) # paths to executables
       SET( DIRS "${CMAKE_PREFIX_PATH}/lib" ) # directories to search for prerequisites
       INSTALL( CODE "
            include(BundleUtilities)
            set(BU_CHMOD_BUNDLE_ITEMS TRUE)
            fixup_bundle(\"${APPS}\" \"\" \"${DIRS}\")
        ")

    else()
        message("Libraries distribution with release build not set (unsupported platform)!")
    endif()
endif()