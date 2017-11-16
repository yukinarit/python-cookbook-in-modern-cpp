cmake_minimum_required(VERSION 3.3)
project(how_to_flatten_a_nested_sequence)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(how_to_flatten_a_nested_sequence example.cpp)

target_include_directories(
	how_to_flatten_a_nested_sequence PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    how_to_flatten_a_nested_sequence
	fmt)
