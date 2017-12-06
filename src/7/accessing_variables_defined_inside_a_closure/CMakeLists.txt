cmake_minimum_required(VERSION 3.3)
project(accessing_variables_defined_inside_a_closure)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(accessing_variables_defined_inside_a_closure1 example1.cpp)

target_include_directories(
	accessing_variables_defined_inside_a_closure1 PRIVATE
	${FMT_INCLUDE_DIR}
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	accessing_variables_defined_inside_a_closure1
	fmt)
