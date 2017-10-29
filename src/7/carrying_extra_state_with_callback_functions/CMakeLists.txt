cmake_minimum_required(VERSION 3.3)
project(carrying_extra_state_with_callback_functions)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(example example.cpp)

target_include_directories(
	example PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    example
	fmt)

cotire(example)
