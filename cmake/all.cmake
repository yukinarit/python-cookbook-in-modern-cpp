list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cotire/CMake")

include(libs)
include(fmt)
include(date)
include(cotire)

add_subdirectory(${LIBS_DIR}/boost-cmake ${CMAKE_CURRENT_BINARY_DIR}/boost-cmake)
