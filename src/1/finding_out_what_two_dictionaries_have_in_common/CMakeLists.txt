cmake_minimum_required(VERSION 3.3)
project(finding_out_what_two_dictionaries_have_in_common)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(libs)

add_subdirectory(${LIBS_DIR}/fmt ${CMAKE_CURRENT_BINARY_DIR}/../../fmt)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(example example.cpp)

target_include_directories(
	example	PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	example
	fmt)
