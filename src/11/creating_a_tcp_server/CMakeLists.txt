cmake_minimum_required(VERSION 3.3)
project(creating_a_tcp_server)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/")
include(all)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")

add_executable(echoclient echoclient.cpp)
target_include_directories(echoclient PRIVATE ${RANGE_INCLUDE_DIR} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(echoclient fmt zmqpp ${CMAKE_THREAD_LIBS_INIT})

add_executable(echoserv echoserv.cpp)
target_include_directories(echoserv PRIVATE ${RANGE_INCLUDE_DIR} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(echoserv fmt zmqpp ${CMAKE_THREAD_LIBS_INIT})

add_executable(echoserv2 echoserv2.cpp)
target_include_directories(echoserv2 PRIVATE ${RANGE_INCLUDE_DIR} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(echoserv2 fmt zmqpp ${CMAKE_THREAD_LIBS_INIT})

add_executable(echoserv3 echoserv3.cpp)
target_include_directories(echoserv3 PRIVATE ${RANGE_INCLUDE_DIR} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(echoserv3 fmt zmqpp ${CMAKE_THREAD_LIBS_INIT})

add_executable(echoserv4 echoserv4.cpp)
target_include_directories(echoserv4 PRIVATE ${RANGE_INCLUDE_DIR} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(echoserv4 fmt zmqpp ${CMAKE_THREAD_LIBS_INIT})

add_executable(echoserv5 echoserv5.cpp)
target_include_directories(echoserv5 PRIVATE ${RANGE_INCLUDE_DIR} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(echoserv5 fmt zmqpp ${CMAKE_THREAD_LIBS_INIT})
