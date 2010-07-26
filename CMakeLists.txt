## Name of the project
project (TMF)

## Minimum required version of CMake to configure the project
cmake_minimum_required (VERSION 2.8)

## list of source files
FILE (GLOB tmf_sources src/*.cc)

## list of header files
FILE (GLOB tmf_headers src/*.h)

## Includes
include_directories (src)

## build the library
add_library (tmf ${tmf_sources})

## Install libray
install (TARGETS tmf
  DESTINATION lib
  )

## Install header files
install (FILES ${tmf_headers}
  DESTINATION include
  )

## Tests
option (BUILD_TESTS "Build tests" NO)

if (BUILD_TESTS)
    add_subdirectory (test)
endif (BUILD_TESTS)

