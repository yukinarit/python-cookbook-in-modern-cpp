cmake_minimum_required(VERSION 3.3)
project(sort_objects_without_native_comparison_support)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(sort_objects_without_native_comparison_support example.cpp)

target_include_directories(
    sort_objects_without_native_comparison_support PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    sort_objects_without_native_comparison_support
    fmt)
