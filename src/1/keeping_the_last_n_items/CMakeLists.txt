cmake_minimum_required(VERSION 3.3)
project(keeping_the_last_n_items)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17 -stdlib=libc++")

add_executable(keeping_the_last_n_items example.cpp)

target_include_directories(
	keeping_the_last_n_items PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	keeping_the_last_n_items
	fmt)
