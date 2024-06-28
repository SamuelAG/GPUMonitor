cmake_minimum_required(VERSION 3.24)

project(
    GPUMonitor
    VERSION 1.0
    DESCRIPTION "CMake template project containing a library, an app using it, and tests"
    LANGUAGES CXX
)

add_subdirectory(interfaces)
add_subdirectory(AmdGPULib)
add_subdirectory(app)
add_subdirectory(lib)
