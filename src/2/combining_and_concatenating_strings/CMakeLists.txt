cmake_minimum_required(VERSION 3.3)
project(combining_and_concatenating_strings)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(combining_and_concatenating_strings example.cpp)

target_include_directories(
	combining_and_concatenating_strings PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    combining_and_concatenating_strings
	fmt)
