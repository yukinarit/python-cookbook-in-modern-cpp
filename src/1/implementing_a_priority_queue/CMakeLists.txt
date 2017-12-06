cmake_minimum_required(VERSION 3.3)
project(implementing_a_priority_queue)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(implementing_a_priority_queue example.cpp)

target_include_directories(
	implementing_a_priority_queue PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	implementing_a_priority_queue
	fmt)
