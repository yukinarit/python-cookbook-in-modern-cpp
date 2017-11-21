cmake_minimum_required(VERSION 3.3)
project(iterating_in_sorted_order_over_merged_sorted_iterables)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(iterating_in_sorted_order_over_merged_sorted_iterables example.cpp)

target_include_directories(
    iterating_in_sorted_order_over_merged_sorted_iterables PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    iterating_in_sorted_order_over_merged_sorted_iterables
    fmt)
