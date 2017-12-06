cmake_minimum_required(VERSION 3.3)
project(finding_the_largest_or_smallest_n_items)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(finding_the_largest_or_smallest_n_items example.cpp)

target_include_directories(
	finding_the_largest_or_smallest_n_items PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	finding_the_largest_or_smallest_n_items
	fmt)
