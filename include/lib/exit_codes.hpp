// Copyright (c) 2012 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#ifndef SATIN_EXIT_CODES_HPP
#define SATIN_EXIT_CODES_HPP

#include <cstdlib>

namespace satin {
  enum EXIT_CODE {
    SUCCESS = EXIT_SUCCESS,
    FAILURE = EXIT_FAILURE,
    // satin specific
    SATIN_MASK = 0x40,
    NO_EXEC = SATIN_MASK | 1,
  };
}

#endif // SATIN_EXIT_CODES_HPP
