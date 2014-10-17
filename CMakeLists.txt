cmake_minimum_required(VERSION 2.8.4)
project(gircalph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/thomas/ClionProjects/gircalph/bin")

set(SOURCE_FILES
        src/test/check_parameter_loading.cpp
        src/util/cmdopts.cpp
        src/util/config_loader.cpp
        src/util/graph_loader.cpp
        src/api/graph_edge.hpp
        src/api/graph_vertex.hpp)
add_executable(gircalph ${SOURCE_FILES})