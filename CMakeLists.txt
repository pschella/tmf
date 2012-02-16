## Minimum required version of CMake to configure the project
cmake_minimum_required (VERSION 2.8)

## Name of the project
project (TMF)

## Project release version
set (TMF_VERSION_MAJOR 2)
set (TMF_VERSION_MINOR 1)
set (TMF_VERSION_PATCH 2)
set (TMF_VERSION "${TMF_VERSION_MAJOR}.${TMF_VERSION_MINOR}.${TMF_VERSION_PATCH}")

## Add definitions
add_definitions (-fPIC)
add_definitions (-Wall)
add_definitions (-g)

## Options
option (TMF_SHARED_LIBRARY "Build TMF as shared library." ON)
option (TMF_SINGLE_PRECISION "Use single precision for all floating point calculations." OFF)
option (TMF_WITH_PYTHON_BINDINGS "Build TMF Python bindings." ON)

## Configuration
configure_file (
    ${PROJECT_SOURCE_DIR}/tmf_config.h.in
    ${PROJECT_BINARY_DIR}/tmf_config.h
)

## Install header files
install (FILES ${PROJECT_SOURCE_DIR}/tmf.h ${PROJECT_BINARY_DIR}/tmf_config.h
  DESTINATION include
  )

## Library
add_subdirectory (tmf)

## Bindings
add_subdirectory (pytmf)

## Tests
add_subdirectory (test)

## Documentation
add_subdirectory (doc)

