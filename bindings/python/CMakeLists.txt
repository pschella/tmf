find_package(PythonLibs)

if (${TMF_WITH_PYTHON_BINDINGS} AND ${PYTHONLIBS_FOUND})
  include(${SWIG_USE_FILE})
  
  include_directories(${PYTHON_INCLUDE_PATH})
  
  swig_add_module(tmf python tmf.i)
  swig_link_libraries(tmf ${PYTHON_LIBRARIES} tmf)
elseif (${TMF_WITH_PYTHON_BINDINGS} AND NOT ${PYTHONLIBS_FOUND})
  message (STATUS "Cannot find Python libraries, Python bindings will NOT be build.")
endif (${TMF_WITH_PYTHON_BINDINGS} AND ${PYTHONLIBS_FOUND})

