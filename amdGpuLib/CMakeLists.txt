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

include(GNUInstallDirs)
target_include_directories(AmdGPULib PUBLIC "include")
