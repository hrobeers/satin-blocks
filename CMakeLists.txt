cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Project settings
project(MyProject)
set(PROJECT_NAME "myproject")
set(PROJECT_BRIEF "${PROJECT_NAME} is a toy project to illustrate a full featured C++ CMake project.")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

# Version
set(MAJOR_VERSION "0")
set(MINOR_VERSION "0")
set(REVISION "1")

# Build flags
set(CMAKE_CXX_STANDARD 11)
set(DEBUG_FLAGS "-g -O0 -Wall")
set(RELEASE_FLAGS "-O3")

# Assign the build flags
set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_C_FLAGS ${RELEASE_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${GCOV_FLAGS})

# Get the build number
execute_process(
    COMMAND git rev-list HEAD --count
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BUILD_NUMBER
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the commit hash
execute_process(
    COMMAND git rev-parse --verify HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Generate the version file
if(${GIT_BUILD_NUMBER})
    configure_file(
        ${CMAKE_SOURCE_DIR}/src/version_template.hpp
        ${CMAKE_SOURCE_DIR}/src/version_autogen.hpp
    )
    message(STATUS "GIT_BUILD_NUMBER: ${GIT_BUILD_NUMBER} GIT_COMMIT_HASH: ${GIT_COMMIT_HASH}")
else()
    message(WARNING "Not building from a git repository, the build number cannot be updated.")
endif()

# TODO OP check how this works on multiple configurations generators
# available configurations in multiple configurations enabled generators
set(CMAKE_CONFIGURATION_TYPES Debug Release)
#message("CMAKE_CFG_INTDIR = ${CMAKE_CFG_INTDIR}")

# Find the dependencies
include(${PROJECT_SOURCE_DIR}/dependencies.cmake)

add_subdirectory(src)

# Licensing and stuff like that
set(LICENSE_FILE ${PROJECT_SOURCE_DIR}/LICENSE-MIT)
set(README_FILE ${PROJECT_SOURCE_DIR}/README.md)

# Install header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/.
  DESTINATION include/${PROJECT_NAME}
  COMPONENT headers
)

# Install libraries
install(DIRECTORY ${LIBRARY_OUTPUT_PATH}/.
  DESTINATION lib
)

# Install readme and license files
install(FILES
  ${README_FILE}
  ${LICENSE_FILE}
  DESTINATION include/${PROJECT_NAME}
)

# Note: Executable installation is configured in dedicated CMakeLists.txt
