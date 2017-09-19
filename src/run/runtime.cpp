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


#include "script/interpreter.h"
#include "utilstrencodings.h"

#include "run/runtime.hpp"
#include "lib/error_codes.hpp"

using namespace satin;

void runtime::run(std::istream &input)
{
  const int flags = SCRIPT_VERIFY_P2SH
    | SCRIPT_VERIFY_CHECKLOCKTIMEVERIFY
    | SCRIPT_VERIFY_CHECKSEQUENCEVERIFY;

  std::vector<unsigned char> s;
  char c;
  while(input.get(c)) s.push_back(c);

  if (!s.size()) {
    std::cout << SCRIPT_ERR_BAD_OPCODE;
    return;
  }

  std::vector<std::vector<unsigned char> > stack;
  CScript script(s.cbegin(), s.cend());
  ScriptError error;

  BaseSignatureChecker sigchecker;
  auto result = EvalScript(stack, script, flags, sigchecker, &error);
  std::cout << error;
}
