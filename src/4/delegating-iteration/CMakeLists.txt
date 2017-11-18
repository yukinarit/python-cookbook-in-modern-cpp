cmake_minimum_required(VERSION 3.3)
project(delegating-iteration)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(delegating-iteration example.cpp)

target_include_directories(
    delegating-iteration PRIVATE
    ${RANGE_INCLUDE_DIR})

target_link_libraries(
    delegating-iteration
    fmt)
