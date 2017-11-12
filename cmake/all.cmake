if(all_included)
  return()
endif()
set(all_included true)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cotire/CMake")

include(vars)
include(fmt)
include(date)

#add_subdirectory(${LIBS_DIR}/boost-cmake ${CMAKE_CURRENT_BINARY_DIR}/boost-cmake)
