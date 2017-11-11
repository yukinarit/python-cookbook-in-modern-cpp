if(date_included)
  return()
endif()
set(date_included true)

include(libs)

set(DATE_DIR "${LIBS_DIR}/date")
set(DATE_INCLUDE_DIRS "${DATE_DIR}/include")

message("DATE_DIR=${DATE_DIR}")
message("DATE_INCLUDE_DIRS=${DATE_INCLUDE_DIRS}")
