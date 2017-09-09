# - Try to find libbitcoin
# Once done this will define
#  LIBBITCOIN_FOUND - System has libbitcoin
#  LIBBITCOIN_INCLUDE_DIRS - The libbitcoin include directories
#  LIBBITCOIN_LIBRARIES - The libraries needed to use libbitcoin
#  LIBBITCOIN_DEFINITIONS - Compiler switches required for using libbitcoin

find_package(PkgConfig)
pkg_check_modules(PC_LIBBITCOIN QUIET libbitcoin)
set(LIBBITCOIN_DEFINITIONS ${PC_LIBBITCOIN_CFLAGS_OTHER})

find_path(LIBBITCOIN_INCLUDE_DIR consensus/merkle.h
          HINTS ${PC_LIBBITCOIN_INCLUDEDIR} ${PC_LIBBITCOIN_INCLUDE_DIRS}
          PATH_SUFFIXES libbitcoin )

find_library(LIBBITCOIN_COMMON NAMES bitcoin_common libbitcoin_common
             HINTS ${PC_LIBBITCOIN_LIBDIR} ${PC_LIBBITCOIN_LIBRARY_DIRS} )
find_library(LIBBITCOIN_UTIL NAMES bitcoin_util libbitcoin_util
             HINTS ${PC_LIBBITCOIN_LIBDIR} ${PC_LIBBITCOIN_LIBRARY_DIRS} )
find_library(LIBBITCOIN_SECP256 NAMES secp256k1 libsecp256k1
             HINTS ${PC_LIBBITCOIN_LIBDIR} ${PC_LIBBITCOIN_LIBRARY_DIRS} )
find_library(LIBBITCOIN_CRYPTO NAMES bitcoin_crypto libbitcoin_crypto
             HINTS ${PC_LIBBITCOIN_LIBDIR} ${PC_LIBBITCOIN_LIBRARY_DIRS} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBBITCOIN_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libbitcoin DEFAULT_MSG
                                  LIBBITCOIN_COMMON LIBBITCOIN_UTIL LIBBITCOIN_SECP256 LIBBITCOIN_CRYPTO LIBBITCOIN_INCLUDE_DIR)

mark_as_advanced(LIBBITCOIN_INCLUDE_DIR LIBBITCOIN_COMMON LIBBITCOIN_UTIL LIBBITCOIN_SECP256 LIBBITCOIN_CRYPTO )

set(LIBBITCOIN_LIBRARIES ${LIBBITCOIN_COMMON} ${LIBBITCOIN_UTIL} ${LIBBITCOIN_SECP256} ${LIBBITCOIN_CRYPTO} )
set(LIBBITCOIN_INCLUDE_DIRS ${LIBBITCOIN_INCLUDE_DIR} )
