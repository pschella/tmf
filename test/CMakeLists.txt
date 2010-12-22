if (${TMF_WITH_TESTS})
  set (tests
      test_equatorial_horizontal
      test_nutation_obliquity
      )
  
  foreach (test ${tests})
    add_executable (${test} ${test}.cc)
  
    target_link_libraries (${test} tmf)
  endforeach (test ${tests})
endif (${TMF_WITH_TESTS})

