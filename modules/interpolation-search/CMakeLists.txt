# Declare variables for binaries' names
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

# Include directory with public headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)

# Add file with test data
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/test_data.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

#############################################
##### Testing
#############################################

include("CTestTests.txt")
