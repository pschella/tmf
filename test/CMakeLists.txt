set (tests
    test_jd_date
    test_angles
    test_equatorial_horizontal
    )

foreach (test ${tests})
    add_executable (${test} ${test}.cc)

    target_link_libraries (${test} tmf)
endforeach (test ${tests})

