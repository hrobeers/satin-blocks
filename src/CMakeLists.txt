# Include header files
include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

# Add all subdirectories
FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
SET(dirlist "")
FOREACH(child ${children})
  IF(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    ADD_SUBDIRECTORY(${child})
  ENDIF()
ENDFOREACH()
