cmake_minimum_required(VERSION 3.3)
project(finding_out_what_two_dictionaries_have_in_common)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(finding_out_what_two_dictionaries_have_in_common example.cpp)

target_include_directories(
	finding_out_what_two_dictionaries_have_in_common PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	finding_out_what_two_dictionaries_have_in_common
	fmt)
