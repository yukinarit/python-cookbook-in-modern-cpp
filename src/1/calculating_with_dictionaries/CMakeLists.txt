cmake_minimum_required(VERSION 3.3)
project(calculating_with_dictionaries)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(fmt)
include(libs)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(example example.cpp)

target_include_directories(
	example	PRIVATE
    ${FMT_INCLUDE_DIR}
	${RANGE_INCLUDE_DIR})

target_link_libraries(
	example
	fmt)
