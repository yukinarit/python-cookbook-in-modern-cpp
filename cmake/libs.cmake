if(libs_included)
  return()
endif()
set(libs_included true)

set(ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/..")

set(LIBS_DIR "${ROOT_DIR}/libs")

set(RANGE_DIR "${LIBS_DIR}/range-v3")
set(RANGE_INCLUDE_DIR "${RANGE_DIR}/include")
message("RANGE_INCLUDE_DIR=${RANGE_INCLUDE_DIR}")
