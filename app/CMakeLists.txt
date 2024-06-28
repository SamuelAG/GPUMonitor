cmake_minimum_required(VERSION 3.16)

project(GPUMonitor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

set(CMAKE_AUTORCC ON)

qt_add_executable(GPUMonitorApp
    main.cpp
    qmlSources.qrc
)



target_include_directories(GPUMonitorApp PRIVATE ../lib/)
target_include_directories(GPUMonitorApp PRIVATE ../AmdGPULib/)

target_link_libraries(GPUMonitorApp
    PRIVATE Qt6::Quick
    GPUMonitor-lib
    AmdGPULib
)

set_target_properties(GPUMonitorApp
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
)

include(GNUInstallDirs)
install(TARGETS GPUMonitorApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
