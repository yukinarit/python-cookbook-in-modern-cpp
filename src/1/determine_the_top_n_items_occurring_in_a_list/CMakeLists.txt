cmake_minimum_required(VERSION 3.3)
project(determine_the_top_n_items_occurring_in_a_list)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(determine_the_top_n_items_occurring_in_a_list example.cpp)

target_include_directories(
	determine_the_top_n_items_occurring_in_a_list PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	determine_the_top_n_items_occurring_in_a_list
	fmt)
