set(NAME mylib)

# Build steps
file(GLOB_RECURSE HDR_FILES ${CMAKE_SOURCE_DIR}/include/${NAME}/*.hpp)
file(GLOB_RECURSE SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
*.cpp)

add_library(${NAME} ${LIB_TYPE} ${SRC_FILES} ${HDR_FILES})

target_link_libraries(${NAME}
  ${Boost_LIBRARIES}
)

install(TARGETS ${NAME}
  LIBRARY DESTINATION lib
)
