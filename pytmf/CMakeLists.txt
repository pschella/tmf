cmake_minimum_required (VERSION 2.8)

find_library(BOOST_PYTHON boost_python
    PATHS /usr/local/lib
    )

find_path(BOOST_INCLUDES boost/python.hpp
    PATHS /usr/local/include
    )

find_library(PYTHON_LIBRARIES python2.6
    PATHS /usr/local/lib
    )

find_path(PYTHON_INCLUDES pyconfig.h
    PATHS /System/Library/Frameworks/Python.framework/Versions/2.6/include/python2.6
    )

include_directories(${BOOST_INCLUDES} ${PYTHON_INCLUDES})

add_library(pytmf MODULE pytmf.cc)

target_link_libraries(pytmf
    tmf
    ${PYTHON_LIBRARIES}
    ${BOOST_PYTHON}
    )

set_target_properties(pytmf
    PROPERTIES
    PREFIX ""
    SUFFIX ".so"
    COMPILE_FLAGS "-DPYTHON -fpermissive"
    LINK_FLAGS "-fPIC -flat_namespace"
    )

