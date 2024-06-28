# Sources are added with target_source(). When doing that, no sources are

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

# required here.
add_library(GPUMonitor-lib STATIC "")

# Add headers to private sources f
target_sources(GPUMonitor-lib
    PRIVATE
    "gpumonitorlib.cpp"
    "gpumonitorlib.h"
)

target_link_libraries(GPUMonitor-lib
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
target_include_directories(GPUMonitor-lib PUBLIC "include")
