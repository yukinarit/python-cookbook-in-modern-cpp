cmake_minimum_required(VERSION 3.3)
project(how_to_communicate_between_threads)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(how_to_communicate_between_threads1 example1.cpp)
target_include_directories(
    how_to_communicate_between_threads1 PRIVATE
    ${RANGE_INCLUDE_DIR})
target_link_libraries(
    how_to_communicate_between_threads1
    fmt ${CMAKE_THREAD_LIBS_INIT})

add_executable(how_to_communicate_between_threads2 example2.cpp)
target_include_directories(
    how_to_communicate_between_threads2 PRIVATE
    ${RANGE_INCLUDE_DIR})
target_link_libraries(
    how_to_communicate_between_threads2
    fmt ${CMAKE_THREAD_LIBS_INIT})
