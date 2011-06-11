## Minimum required version of CMake to configure the project
cmake_minimum_required (VERSION 2.8)

## Name of the project
project (TMF)

## Project release version
set (TMF_VERSION_MAJOR 2)
set (TMF_VERSION_MINOR 0)
set (TMF_VERSION_PATCH 0)
set (TMF_VERSION "${TMF_VERSION_MAJOR}.${TMF_VERSION_MINOR}.${TMF_VERSION_PATCH}")

## Add definitions
add_definitions (-fPIC)
add_definitions (-Wall)
add_definitions (-Werror)
add_definitions (-g)

## Options
OPTION (TMF_SHARED_LIBRARY "Build TMF as shared library." ON)
OPTION (TMF_SINGLE_PRECISION "Use single precision for all floating point calculations." OFF)

## Configuration
configure_file (
    ${PROJECT_SOURCE_DIR}/tmf_config.h.in
    ${PROJECT_BINARY_DIR}/tmf_config.h
)

include_directories (src ${PROJECT_BINARY_DIR})

## List of source files
FILE (GLOB tmf_sources src/*.c)

## List of header files
FILE (GLOB tmf_headers src/*.h)

## Build the library
if (TMF_SHARED_LIBRARY)
    add_library (tmf SHARED ${tmf_sources})
else (TMF_SHARED_LIBRARY)
    add_library (tmf STATIC ${tmf_sources})
endif (TMF_SHARED_LIBRARY)

## Library versioning
set_target_properties (tmf PROPERTIES VERSION ${TMF_VERSION})

## Install libray
install (TARGETS tmf
  DESTINATION lib
  )

## Install header files
install (FILES ${tmf_headers}
  DESTINATION include
  )

## Bindings
add_subdirectory (bindings)

## Tests
add_subdirectory (test)

