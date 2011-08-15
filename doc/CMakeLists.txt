find_package (Doxygen)

if (DOXYGEN_FOUND)
  option (DOXYGEN_GENERATE_HTML "Build HTML documentation" ON)
  option (DOXYGEN_GENERATE_XML "Build XML documentation" OFF)
  option (DOXYGEN_GENERATE_LATEX "Build LaTeX documentation" OFF)
  
  mark_as_advanced (DOXYGEN_GENERATE_HTML)
  mark_as_advanced (DOXYGEN_GENERATE_XML)
  mark_as_advanced (DOXYGEN_GENERATE_LATEX)
  
  if (DOXYGEN_GENERATE_HTML)
    set (GENERATE_HTML "YES")
  else (DOXYGEN_GENERATE_HTML)
    set (GENERATE_HTML "NO")
  endif (DOXYGEN_GENERATE_HTML)
  
  if (DOXYGEN_GENERATE_XML)
    set (GENERATE_XML "YES")
  else (DOXYGEN_GENERATE_XML)
    set (GENERATE_XML "NO")
  endif (DOXYGEN_GENERATE_XML)
  
  if (DOXYGEN_GENERATE_LATEX)
    set (GENERATE_LATEX "YES")
  else (DOXYGEN_GENERATE_LATEX)
    set (GENERATE_LATEX "NO")
  endif (DOXYGEN_GENERATE_LATEX)

  set (DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  
  configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    )
  
  add_custom_target (doc
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
  message (STATUS "Doxygen found, run 'make doc' to generate the TMF documentation.")
else (DOXYGEN_FOUND)
  message (WARNING "Cannot find doxygen executable, doc target disabled.")
endif (DOXYGEN_FOUND)

