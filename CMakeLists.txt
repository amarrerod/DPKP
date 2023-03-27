cmake_minimum_required(VERSION 3.16.3)
project(knapsack_dp LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "Dynammic Programming Solver for KP")

set(CMAKE_CXX_STANDARD 20)
enable_language(C)
add_definitions(-DOS=LINUX)

if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Release)
endif()

# Always run with the optimisation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -isystem -fPIC -lstdc++fs -O3 -ffast-math -Wall -fopenmp -march=native -mtune=native")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fprofile-arcs -ftest-coverage --coverage")

# Path configuration
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

include(FetchContent)
include(GNUInstallDirs)

# Source code
set(SOURCE_FILES
        src/knapsackDP.h
        src/knapsackDP.cpp
)

add_executable(DPKP
        main.cpp
        src/knapsackDP.h
        src/knapsackDP.cpp
)
target_include_directories(DPKP PRIVATE src)
