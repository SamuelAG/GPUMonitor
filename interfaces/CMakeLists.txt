find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

add_library(Interfaces STATIC "")
# Add headers to private sources f
target_sources(Interfaces
    PRIVATE
    "gpuinfo.h"
)

set_target_properties(Interfaces
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
)

include(GNUInstallDirs)
target_include_directories(Interfaces PUBLIC "include")
