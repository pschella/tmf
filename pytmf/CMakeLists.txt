cmake_minimum_required (VERSION 2.8)

# Find Python
include (FindPythonLibs)

# Find Boost Python
find_package (Boost COMPONENTS python)

# Find Python site-packages directory for installation
execute_process ( COMMAND python -c "from distutils.sysconfig import get_python_lib; print get_python_lib()" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE )

# Build PyTMF if both the Python and Boost Python libraries were found
if (Boost_FOUND AND PYTHONLIBS_FOUND)
    set (BUILD_PYTMF ON)
else (Boost_FOUND AND PYTHONLIBS_FOUND)
    message (WARNING "Unable to build pytmf missing dependencies.")
endif (Boost_FOUND AND PYTHONLIBS_FOUND)

if (${BUILD_PYTMF})
    include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_PATH})
    
    add_library(pytmf MODULE pytmf.cc)
    
    target_link_libraries(pytmf
        tmf
        ${Boost_LIBRARIES}
        ${PYTHON_LIBRARIES}
        )
    
    if (APPLE)
        set_target_properties(pytmf
            PROPERTIES
            PREFIX ""
            SUFFIX ".so"
            COMPILE_FLAGS "-DPYTHON -fpermissive"
            LINK_FLAGS "-fPIC -flat_namespace"
            )
    else (APPLE)
        set_target_properties(pytmf
            PROPERTIES
            PREFIX ""
            SUFFIX ".so"
            COMPILE_FLAGS "-DPYTHON"
            LINK_FLAGS "-fPIC -shared -Wl"
            )
    endif (APPLE)
    
    install (TARGETS pytmf
        DESTINATION ${PYTHON_SITE_PACKAGES}
        )
endif (${BUILD_PYTMF})

