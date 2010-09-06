cmake_minimum_required (VERSION 2.8)

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_PATH})

add_library(pytmf MODULE pytmf.cc)

target_link_libraries(pytmf
    tmf
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    )

set_target_properties(pytmf
    PROPERTIES
    PREFIX ""
    SUFFIX ".so"
    COMPILE_FLAGS "-DPYTHON -fpermissive"
    LINK_FLAGS "-fPIC -flat_namespace"
    )

install (TARGETS pytmf
    DESTINATION ${PYTHON_SITE_PACKAGES}
    )

