# Declare variables for binaries' names
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

# Include directory with public headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Encrypt.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Decrypt.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Encrypt.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Decrypt.txt
DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#############################################
##### Testing
#############################################

include("CTestTests.txt")
