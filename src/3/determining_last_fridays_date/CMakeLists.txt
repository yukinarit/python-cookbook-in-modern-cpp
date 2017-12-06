cmake_minimum_required(VERSION 3.3)
project(determining_last_fridays_date)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(determining_last_fridays_date example.cpp)

target_include_directories(
	determining_last_fridays_date PRIVATE
    ${DATE_INCLUDE_DIRS})

target_link_libraries(
    determining_last_fridays_date 
	fmt)
