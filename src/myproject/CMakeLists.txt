# Build steps
file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
*.cpp)

add_executable(myproject ${SRC_FILES})

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(myproject
  ${Boost_LIBRARIES}
)

install(TARGETS myproject
  RUNTIME DESTINATION bin
)
