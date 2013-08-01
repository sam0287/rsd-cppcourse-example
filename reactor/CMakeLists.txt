cmake_minimum_required (VERSION 2.6)
project (Reactor)
include_directories(src)
add_executable(reactor src/main.cpp)

# Boilerplate to enable the Google testing framework
INCLUDE(ExternalProject)
set(EXTERNAL_ROOT ${CMAKE_BINARY_DIR}/external)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
find_package(GTest)
enable_testing()
add_subdirectory(test)