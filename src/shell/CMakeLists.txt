set(NAME shell)
set(BIN_NAME satin-${NAME})
set(SCRIPT_FILE ${BIN_NAME}.sh)

# Register as build target
add_custom_target(${BIN_NAME} ALL)
# Copy script file on build
add_custom_command(
  TARGET  ${BIN_NAME} PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
          ${CMAKE_CURRENT_SOURCE_DIR}/${SCRIPT_FILE}
          ${EXECUTABLE_OUTPUT_PATH}/${BIN_NAME}
)

# Install as program
install(PROGRAMS
  ${EXECUTABLE_OUTPUT_PATH}/${BIN_NAME}
  DESTINATION bin/
)
