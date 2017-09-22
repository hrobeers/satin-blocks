set(NAME help)
set(BIN_NAME satin-${NAME})

# Build steps
file(GLOB_RECURSE HDR_FILES ${CMAKE_SOURCE_DIR}/include/${NAME}/*.hpp)
file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
*.cpp)

add_executable(${BIN_NAME} ${SRC_FILES} ${HDR_FILES})

target_link_libraries(${BIN_NAME}
  ${Boost_LIBRARIES}
)

install(TARGETS ${BIN_NAME}
  RUNTIME DESTINATION bin
)
