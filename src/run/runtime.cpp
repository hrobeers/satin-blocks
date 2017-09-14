// Copyright (c) 2017 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.


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

  std::vector<std::vector<unsigned char> > stack;
  CScript script(s.cbegin(), s.cend());
  ScriptError error;

  BaseSignatureChecker sigchecker;
  auto result = EvalScript(stack, script, flags, sigchecker, &error);
  std::cout << error;
}
