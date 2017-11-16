cmake_minimum_required(VERSION 3.3)
project(removing_duplicates_from_a_sequence_while_maintaining_order)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

add_subdirectory(${LIBS_DIR}/fmt ${CMAKE_CURRENT_BINARY_DIR}/fmt)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(removing_duplicates_from_a_sequence_while_maintaining_order example.cpp)

target_include_directories(
	removing_duplicates_from_a_sequence_while_maintaining_order PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    removing_duplicates_from_a_sequence_while_maintaining_order	
	fmt)
