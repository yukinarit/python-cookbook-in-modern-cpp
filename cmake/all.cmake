if(all_included)
  return()
endif()
set(all_included true)

include(vars)
include(fmt)
include(date)
include(zmq)

#add_subdirectory(${LIBS_DIR}/boost-cmake ${CMAKE_CURRENT_BINARY_DIR}/boost-cmake)
