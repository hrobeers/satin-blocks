// Copyright (c) 2017 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#ifndef SATIN_ERROR_CODES_HPP
#define SATIN_ERROR_CODES_HPP

#include "termcolor/termcolor.hpp"
#include "script/script_error.h"

namespace satin {
  std::ostream& operator <<(std::ostream& stream, const ScriptError& script_err) {
    if (termcolor::_internal::is_atty(stream)) {
      if (script_err == SCRIPT_ERR_OK)
        stream << "Success";
      else
        stream << termcolor::red << ScriptErrorString(script_err) << termcolor::reset;
    }
    else
      stream << (unsigned char)script_err;
  }
}

#endif // SATIN_ERROR_CODES_HPP
