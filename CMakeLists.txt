## Name of the project
project (TMF)

## Minimum required version of CMake to configure the project
cmake_minimum_required (VERSION 2.8)

## Default flags
set (CMAKE_BUILD_TYPE Release)
set (CMAKE_C_FLAGS_DEBUG "-g -Wall -Werror")
set (CMAKE_C_FLAGS_RELEASE "-O2 -Wall -Werror")

## List of source files
FILE (GLOB tmf_sources src/*.c)

## List of header files
FILE (GLOB tmf_headers src/*.h)

## Includes
include_directories (src)

## Build the library
add_library (tmf ${tmf_sources})

## Add definitions
add_definitions (-fPIC)

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

## Bindings
include (FindSWIG)

if (${SWIG_FOUND})
  add_subdirectory (bindings)
endif (${SWIG_FOUND})

