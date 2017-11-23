cmake_minimum_required(VERSION 3.3)
project(iterating_on_items_in_separate_containers)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(iterating_on_items_in_separate_containers example.cpp)

target_include_directories(
    iterating_on_items_in_separate_containers PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    iterating_on_items_in_separate_containers
    fmt)
