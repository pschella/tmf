# Set include directories
## Set include directories
include_directories (BEFORE ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})

## List of source files
FILE (GLOB tmf_sources *.c)

## List of header files
FILE (GLOB tmf_headers *.h)

## Build the library
if (TMF_SHARED_LIBRARY)
    add_library (tmf SHARED ${tmf_sources})
else (TMF_SHARED_LIBRARY)
    add_library (tmf STATIC ${tmf_sources})
endif (TMF_SHARED_LIBRARY)

## Library versioning
set_target_properties (tmf PROPERTIES VERSION ${TMF_VERSION})

## Install libray
install (TARGETS tmf
  DESTINATION lib
  )

## Install header files
install (FILES ${tmf_headers}
  DESTINATION include/tmf
  )

