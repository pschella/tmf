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
add_library (tmf ${tmf_sources})

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
option (BUILD_TESTS "Build tests" NO)

if (BUILD_TESTS)
    add_subdirectory (test)
endif (BUILD_TESTS)

## Python bindings
option (BUILD_PYTMF "Build pytmf" NO)

if (BUILD_PYTMF)
    # Find Python
    include (FindPythonLibs)

    # Find Python site-packages directory for installation
    execute_process ( COMMAND python -c "from distutils.sysconfig import get_python_lib; print get_python_lib()" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE )

    # Find Boost Python
    find_package (Boost COMPONENTS python)

    if (Boost_FOUND AND PYTHONLIBS_FOUND)
        add_subdirectory (pytmf)
    else (Boost_FOUND AND PYTHONLIBS_FOUND)
        message (WARNING "Unable to build pytmf missing dependencies.")
    endif (Boost_FOUND AND PYTHONLIBS_FOUND)
endif (BUILD_PYTMF)

