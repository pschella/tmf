option (TMF_WITH_PYTHON_BINDINGS "Build TMF Python bindings." ON)

# Find packages
find_package(SWIG)

if (NOT ${PYTHONLIBS_FOUND})
    find_package(PythonLibs)
endif (NOT ${PYTHONLIBS_FOUND})

# Find Python site-packages directory for installation
execute_process (COMMAND python -c "from distutils.sysconfig import get_python_lib; print get_python_lib()" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)

# Determine if build will work
if (${TMF_WITH_PYTHON_BINDINGS} AND NOT ${PYTHONLIBS_FOUND})
    message (STATUS "Python bindings disabled, cannot find Python libraries")
    set (TMF_WITH_PYTHON_BINDINGS OFF)
endif (${TMF_WITH_PYTHON_BINDINGS} AND NOT ${PYTHONLIBS_FOUND})

if (${TMF_WITH_PYTHON_BINDINGS} AND ${TMF_SINGLE_PRECISION})
    message (WARNING "Python bindings disabled, cannot build against single precision library.")
    set (TMF_WITH_PYTHON_BINDINGS OFF)
endif (${TMF_WITH_PYTHON_BINDINGS} AND ${TMF_SINGLE_PRECISION})

# Add target for build and installation
if (${TMF_WITH_PYTHON_BINDINGS})
    include(${SWIG_USE_FILE})

    include_directories(${PYTHON_INCLUDE_PATH})

    swig_add_module(pytmf python pytmf.i)
    swig_link_libraries(pytmf ${PYTHON_LIBRARIES} tmf)

    install (FILES ${CMAKE_CURRENT_BINARY_DIR}/_pytmf.so ${CMAKE_CURRENT_BINARY_DIR}/pytmf.py
             DESTINATION ${PYTHON_SITE_PACKAGES})
endif (${TMF_WITH_PYTHON_BINDINGS})

