cmake_minimum_required(VERSION 3.3)
project(creating_new_iteration_patterns_with_generators)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(creating_new_iteration_patterns_with_generators example.cpp)

target_include_directories(
    creating_new_iteration_patterns_with_generators PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    creating_new_iteration_patterns_with_generators 
    fmt)
