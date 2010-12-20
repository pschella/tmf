find_package(PerlLibs)

if (${TMF_WITH_PERL_BINDINGS} AND ${PERLLIBS_FOUND})
  include(${SWIG_USE_FILE})
  
  include_directories(${PERL_INCLUDE_PATH})
  
  swig_add_module(tmf perl tmf.i)
  swig_link_libraries(tmf ${PERL_LIBRARIES} tmf)
elseif (${TMF_WITH_PERL_BINDINGS} AND NOT ${PERLLIBS_FOUND})
  message (STATUS "Cannot find Perl libraries, Perl bindings will NOT be build.")
endif (${TMF_WITH_PERL_BINDINGS} AND ${PERLLIBS_FOUND})

