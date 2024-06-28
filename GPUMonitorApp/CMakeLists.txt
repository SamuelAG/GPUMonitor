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



target_include_directories(GPUMonitorApp PRIVATE ../GPULib/)
target_include_directories(GPUMonitorApp PRIVATE ../AmdGPULib/)

target_link_libraries(GPUMonitorApp
    PRIVATE Qt6::Quick
    GPUMonitor-lib
    AmdGPULib
)

set_target_properties(GPUMonitorApp
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${CMAKE_HOST_SYSTEM_PROCESSOR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${CMAKE_HOST_SYSTEM_PROCESSOR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${CMAKE_HOST_SYSTEM_PROCESSOR}"
)

include(GNUInstallDirs)
install(TARGETS GPUMonitorApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
