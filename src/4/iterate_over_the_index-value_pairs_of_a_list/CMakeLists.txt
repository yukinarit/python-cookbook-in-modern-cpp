cmake_minimum_required(VERSION 3.3)
project(iterate_over_the_index-value_pairs_of_a_list)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(iterate_over_the_index-value_pairs_of_a_list example.cpp)

target_include_directories(
    iterate_over_the_index-value_pairs_of_a_list PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    iterate_over_the_index-value_pairs_of_a_list
    fmt)
