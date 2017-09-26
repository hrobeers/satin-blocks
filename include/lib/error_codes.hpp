// Copyright (C) 2017 hrobeers (https://github.com/hrobeers)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SATIN_ERROR_CODES_HPP
#define SATIN_ERROR_CODES_HPP

#include "termcolor/termcolor.hpp"
#include "script/script_error.h"

namespace satin {
  bool force_tty = false;

  std::ostream& operator <<(std::ostream& stream, const ScriptError& script_err) {
    if (force_tty || termcolor::_internal::is_atty(stream)) {
      if (script_err == SCRIPT_ERR_OK)
        stream << "Success";
      else
        stream << termcolor::red << ScriptErrorString(script_err) << termcolor::reset;
      stream << std::endl;
    }
    else
      stream << (unsigned char)script_err;
    return stream;
  }
}

#endif // SATIN_ERROR_CODES_HPP
