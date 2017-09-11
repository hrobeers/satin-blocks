set(NAME satin-interpret)

# Build steps
file(GLOB_RECURSE HDR_FILES ${CMAKE_SOURCE_DIR}/include/${NAME}/*.hpp)
file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
*.cpp)

add_executable(${NAME} ${SRC_FILES} ${HDR_FILES})

target_link_libraries(${NAME}
  ${Boost_LIBRARIES}
  ${LIBBITCOIN_LIBRARIES}
  ${OPENSSL_LIBRARIES}
)

install(TARGETS ${NAME}
  RUNTIME DESTINATION bin
)
