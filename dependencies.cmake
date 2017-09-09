list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Boost
find_package(Boost COMPONENTS program_options system filesystem thread REQUIRED)
if(Boost_FOUND)
  message(STATUS "Including Boost from: ${Boost_INCLUDE_DIRS}")
  include_directories(${Boost_INCLUDE_DIRS})
endif()

# libbitcoin
find_package(LibBitcoin REQUIRED)
if(libbitcoin_FOUND)
  message(STATUS "Including libbitcoin from: ${LIBBITCOIN_INCLUDE_DIRS}")
  include_directories(${LIBBITCOIN_INCLUDE_DIRS})
endif()

# OpenSSL
find_package(OpenSSL REQUIRED)
if(OPENSSL_FOUND)
  message(STATUS "Including openssl from: ${OPENSSL_INCLUDE_DIRS}")
  include_directories(${OPENSSL_INCLUDE_DIRS})
endif()
