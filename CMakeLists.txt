cmake_minimum_required(VERSION 3.28) 

set(ENV{CC} "/usr/bin/gcc-15")
set(ENV{CXX} "/usr/bin/g++-15")

project(CPP-OPTIMIZATION-LAB)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(BUILD_BENCHMARKS "Enable benchmarking" OFF)
if(BUILD_BENCHMARKS)
    set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        192ef10025eb2c4cdd392bc502f0c852196baa48 #1.9.5
    FIND_PACKAGE_ARGS CONFIG
    )
    FetchContent_MakeAvailable(googlebenchmark)

    add_subdirectory(stl_data_structures)
endif()


add_executable(lifetime_lab lifetime-lab/main.cpp)
add_executable(object_size_lab object-size-lab/main.cpp)
