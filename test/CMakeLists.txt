set (tests
    testjd
    test_angles
    test_horizontal_equatorial
    )

foreach (test ${tests})
    add_executable (${test} ${test}.cc)

    target_link_libraries (${test} tmf)
endforeach (test ${tests})

