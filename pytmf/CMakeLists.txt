## Set include directories
include_directories (BEFORE ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})

## Find packages
find_package(SWIG)

if (NOT PYTHONLIBS_FOUND)
    find_package(PythonLibs)
endif (NOT PYTHONLIBS_FOUND)

## Find Python site-packages directory for installation
if (NOT PYTHON_SITE_PACKAGES)
    execute_process (COMMAND python -c "from distutils.sysconfig import get_python_lib; print get_python_lib()" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
endif (NOT PYTHON_SITE_PACKAGES)

## Determine if build will work
if (TMF_WITH_PYTHON_BINDINGS AND NOT PYTHONLIBS_FOUND)
    message (WARNING "[TMF] Python bindings disabled, cannot find Python libraries")
    set (TMF_WITH_PYTHON_BINDINGS OFF)
endif (TMF_WITH_PYTHON_BINDINGS AND NOT PYTHONLIBS_FOUND)

if (TMF_WITH_PYTHON_BINDINGS AND TMF_SINGLE_PRECISION)
    message (WARNING "[TMF] Python bindings disabled, cannot build against single precision library.")
    set (TMF_WITH_PYTHON_BINDINGS OFF)
endif (TMF_WITH_PYTHON_BINDINGS AND TMF_SINGLE_PRECISION)

## Add target for build and installation
if (TMF_WITH_PYTHON_BINDINGS)
    message (STATUS "------------------------------------------------------------")
    message (STATUS "[PyTMF] Configuration summary.")
    message (STATUS "------------------------------------------------------------")
    message (STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
    message (STATUS "PYTHON_INCLUDE_PATH = ${PYTHON_INCLUDE_PATH}")
    message (STATUS "PYTHON_SITE_PACKAGES = ${PYTHON_SITE_PACKAGES}")
    message (STATUS "------------------------------------------------------------")

    include(${SWIG_USE_FILE})

    include_directories(${PYTHON_INCLUDE_PATH})

    swig_add_module(pytmf python pytmf.i)
    swig_link_libraries(pytmf ${PYTHON_LIBRARIES} tmf)

    install (FILES ${CMAKE_CURRENT_BINARY_DIR}/_pytmf.so ${CMAKE_CURRENT_BINARY_DIR}/pytmf.py
             DESTINATION ${PYTHON_SITE_PACKAGES})
endif (TMF_WITH_PYTHON_BINDINGS)

