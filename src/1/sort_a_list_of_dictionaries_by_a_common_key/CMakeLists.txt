cmake_minimum_required(VERSION 3.3)
project(sort_a_list_of_dictionaries_by_a_common_key)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

add_subdirectory(${LIBS_DIR}/fmt ${CMAKE_CURRENT_BINARY_DIR}/fmt)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(sort_a_list_of_dictionaries_by_a_common_key example.cpp)

target_include_directories(
	sort_a_list_of_dictionaries_by_a_common_key PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    sort_a_list_of_dictionaries_by_a_common_key
	fmt)
