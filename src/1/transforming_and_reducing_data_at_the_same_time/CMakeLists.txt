cmake_minimum_required(VERSION 3.3)
project(transforming_and_reducing_data_at_the_same_time)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

add_executable(transforming_and_reducing_data_at_the_same_time example.cpp)

target_include_directories(
	transforming_and_reducing_data_at_the_same_time PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    transforming_and_reducing_data_at_the_same_time
	fmt)
