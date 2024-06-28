find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

add_library(Interfaces STATIC "")
# Add headers to private sources f
target_sources(Interfaces
    PRIVATE
    "gpuinfo.h"
)


include(GNUInstallDirs)
target_include_directories(Interfaces PUBLIC "include")
