cmake_minimum_required(VERSION 3.3)
project(mapping_names_to_sequence_elements)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(libs)

add_subdirectory(${LIBS_DIR}/fmt ${CMAKE_CURRENT_BINARY_DIR}/fmt)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(mapping_names_to_sequence_elements example.cpp)

target_include_directories(
	mapping_names_to_sequence_elements PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	mapping_names_to_sequence_elements
	fmt)
