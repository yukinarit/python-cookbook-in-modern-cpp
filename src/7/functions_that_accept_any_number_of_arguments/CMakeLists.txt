cmake_minimum_required(VERSION 3.3)
project(functions_that_accept_any_number_of_arguments)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(functions_that_accept_any_number_of_arguments example.cpp)

target_include_directories(
	functions_that_accept_any_number_of_arguments PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    functions_that_accept_any_number_of_arguments
	fmt)
