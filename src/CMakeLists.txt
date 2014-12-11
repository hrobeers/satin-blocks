# Build steps
file(GLOB_RECURSE MYPROJECT_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
*.cpp)

add_executable(MyProject ${MYPROJECT_SRC_FILES})

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)


install(DIRECTORY ${PROJECT_SOURCE_DIR}/include
  DESTINATION .
  COMPONENT headers
)
