cmake_minimum_required(VERSION 2.8.4)
project(gircalph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/thomas/ClionProjects/gircalph/bin")

set(SOURCE_FILES
        src/test/test_current_workflow.cpp
        src/util/cmdopts.cpp
        src/util/cmdopts.hpp
        src/util/load_file_data_opts.hpp
        src/util/load_file_data_opts.cpp
        src/api/graph_vertex.hpp
        src/api/graph_edge.hpp
        src/engine/gircalph_engine.hpp)

add_executable(gircalph ${SOURCE_FILES})