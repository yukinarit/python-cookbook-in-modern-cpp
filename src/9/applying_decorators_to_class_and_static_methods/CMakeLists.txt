cmake_minimum_required(VERSION 3.3)
project(applying_decorators_to_class_and_static_methods)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(applying_decorators_to_class_and_static_methods example.cpp)

target_include_directories(
	applying_decorators_to_class_and_static_methods PRIVATE
	${RANGE_INCLUDE_DIR})

target_link_libraries(
    applying_decorators_to_class_and_static_methods
	fmt)
