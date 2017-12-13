cmake_minimum_required(VERSION 3.3)
project(generators_with_state)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(generators_with_state example.cpp)

target_include_directories(
    generators_with_state PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    generators_with_state
    fmt)
