if(fmt_included)
  return()
endif()
set(fmt_included true)

include(libs)

add_subdirectory(${LIBS_DIR}/fmt ${CMAKE_CURRENT_BINARY_DIR}/fmt)

set(FMT_DIR "${LIBS_DIR}/fmt")
set(FMT_INCLUDE_DIR "${LIBS_DIR}/fmt")
set(FMT_LIBRARIES "${CMAKE_BINARY_DIR}/fmt/fmt/libfmt.a")

message("FMT_DIR=${FMT_DIR}")
message("FMT_INCLUDE_DIRS=${FMT_INCLUDE_DIRS}")
message("FMT_LIBRARIES=${FMT_LIBRARIES}")
