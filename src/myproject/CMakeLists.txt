set(NAME myproject)

# Build steps
file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
*.cpp)

add_executable(${NAME} ${SRC_FILES})

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${NAME}
  ${Boost_LIBRARIES}
)

install(TARGETS ${NAME}
  RUNTIME DESTINATION bin
)
