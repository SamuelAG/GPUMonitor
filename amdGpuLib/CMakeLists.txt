# Sources are added with target_source(). When doing that, no sources are

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

# required here.
add_library(AmdGPULib STATIC "")

# Add headers to private sources f
target_sources(AmdGPULib
    PRIVATE
    "amdgpusource.cpp"
    "amdgpusource.h"
)
target_include_directories(AmdGPULib PRIVATE 3rdParty)

target_link_libraries(AmdGPULib
    PRIVATE Qt6::Quick
)

set_target_properties(AmdGPULib
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
)

include(GNUInstallDirs)
target_include_directories(AmdGPULib PUBLIC "include")
