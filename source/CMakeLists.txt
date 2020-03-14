cmake_minimum_required(VERSION 3.12)
project(Nerp-Builder)

set(CMAKE_CXX_STANDARD 14)

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

# Define a variable containing a list of source files for the project
set(SRC_FILES
        nbApp.cpp
        nbApp.h
        nbForms.cpp
        nbForms.h
        )

if(WIN32)
    # Include a RC file for windows
    #list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES wxmac.icns)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/../platform/macosx//Info.plist)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RESOURCE "wxmac.icns"
            MACOSX_BUNDLE_ICON_FILE wxmac.icns
            MACOSX_BUNDLE_COPYRIGHT "Copyright Nerp"
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.nerpengine.builder"
            )
else()
    #set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
endif()