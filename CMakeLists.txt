cmake_minimum_required(VERSION 3.16)

project(GPUMonitor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

add_subdirectory(lib)

qt_standard_project_setup()

qt_add_executable(GPUMonitorApp
    main.cpp
)

qt_add_qml_module(GPUMonitorApp
    URI GPUMonitor
    VERSION 1.0
    QML_FILES
        Main.qml
)

target_include_directories(GPUMonitorApp PRIVATE lib/)

target_link_libraries(GPUMonitorApp
    PRIVATE Qt6::Quick
    GPUMonitor-lib
)

include(GNUInstallDirs)
install(TARGETS GPUMonitorApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
