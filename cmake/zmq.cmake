if(zmq_included)
  return()
endif()
set(zmq_included true)

include(vars)

set(ZEROMQ_LIBRARY_STATIC ON)
set(ZMQ_BUILD_TESTS OFF)
set(BUILD_TESTS OFF)
set(WITH_DOC OFF)
# add_subdirectory(${LIBS_DIR}/libzmq ${CMAKE_CURRENT_BINARY_DIR}/libzmq)
add_subdirectory(${LIBS_DIR}/zmqpp ${CMAKE_CURRENT_BINARY_DIR}/zmqpp)

set(ZMQ_DIR "${LIBS_DIR}/zmqpp")
set(ZMQ_INCLUDE_DIRS "${ZMQ_DIR}/src")
set(ZMQ_LIBRARIES "${CMAKE_BINARY_DIR}/zmqpp/libzmq-static.a")

message("ZMQ_DIR=${ZMQ_DIR}")
message("ZMQ_INCLUDE_DIRS=${ZMQ_INCLUDE_DIRS}")
message("ZMQ_LIBRARIES=${ZMQ_LIBRARIES}")
