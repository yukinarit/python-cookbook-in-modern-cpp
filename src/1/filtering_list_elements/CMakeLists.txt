cmake_minimum_required(VERSION 3.3)
project(filtering_list_elements)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(fmt)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(filtering_list_elements example.cpp)

target_include_directories(
	filtering_list_elements PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	filtering_list_elements
	fmt)
