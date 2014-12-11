cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project(MyProject)

if($ENV{BUILD_NUMBER})
  set(BUILD_NUMBER $ENV{BUILD_NUMBER})
else()
  set(BUILD_NUMBER 0)
endif()

set(MYPROJECT_NAME "MyProject")
set(MYPROJECT_VERSION "0.3.0.${BUILD_NUMBER}")
set(MYPROJECT_BRIEF "${MYPROJECT_NAME} is a toy project to illustrate a full featured C++ CMake project.")

set(DEBUG_FLAGS "-g -O0 -Wall")
set(RELEASE_FLAGS "-O3")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_C_FLAGS ${RELEASE_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_C_FLAGS_DEBUG ${GCOV_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${GCOV_FLAGS})

# TODO OP check how this works on multiple configurations generators
# available configurations in multiple configurations enabled generators
set(CMAKE_CONFIGURATION_TYPES Debug Release)
#message("CMAKE_CFG_INTDIR = ${CMAKE_CFG_INTDIR}")

add_subdirectory(src)

# Licensing and stuff like that
set(LICENSE_FILE ${PROJECT_SOURCE_DIR}/LICENSE-MIT)

install(FILES
	${README_FILE}
	${LICENSE_FILE}
  DESTINATION .
)

