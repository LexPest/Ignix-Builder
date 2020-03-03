cmake_minimum_required(VERSION 3.12)
project(Nerp-Builder)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_FIND_LIBRARY_PREFIXES "")
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")

include_directories(${WinSDK})

set (wxWidgets_CONFIGURATION mswu)
# Request the required wxWidgets libs
find_package(wxWidgets COMPONENTS scintilla richtext media webview core base net qa propgrid ribbon gl adv html xml xrc aui stc jpeg png REQUIRED)

set (wxUSE_UNICODE 1)
set (UNICODE 1)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_definitions(-DUNICODE -D_UNICODE)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Define a variable containing a list of source files for the project
set(SRC_FILES
        # propgrid_minimal.cpp
       # propgrid.cpp
       # propgrid.h
       # sampleprops.cpp
       # sampleprops.h
       # tests.cpp
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
    #list(APPEND SRC_FILES ../../src/osx/carbon/wxmac.icns)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            #RESOURCE "../../src/osx/carbon/wxmac.icns"
            #MACOSX_BUNDLE_ICON_FILE wxmac.icns
            #MACOSX_BUNDLE_COPYRIGHT "Copyright wxWidgets"
            MACOSX_BUNDLE_GUI_IDENTIFIER "com.nerpengine.builder"
            )
else()
    #set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
endif()