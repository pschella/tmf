## Name of the project
project (TMF)

## Minimum required version of CMake to configure the project
cmake_minimum_required (VERSION 2.8)

## List of source files
FILE (GLOB tmf_sources src/*.cc)

## List of header files
FILE (GLOB tmf_headers src/*.h)

## Includes
include_directories (src)

## Build the library
add_library (tmf SHARED ${tmf_sources})

## Library versioning
set_target_properties (tmf PROPERTIES VERSION 1.0)

## Install libray
install (TARGETS tmf
  DESTINATION lib
  )

## Install header files
install (FILES ${tmf_headers}
  DESTINATION include
  )

## Tests
option (BUILD_TESTS "Build tests" YES)

if (BUILD_TESTS)
    add_subdirectory (test)
endif (BUILD_TESTS)

