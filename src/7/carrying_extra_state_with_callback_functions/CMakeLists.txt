cmake_minimum_required(VERSION 3.3)
project(carrying_extra_state_with_callback_functions)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(carrying_extra_state_with_callback_functions example.cpp)

target_include_directories(
	carrying_extra_state_with_callback_functions PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    carrying_extra_state_with_callback_functions
	fmt)
