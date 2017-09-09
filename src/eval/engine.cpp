// Copyright (c) 2012 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#include "eval/engine.hpp"

#include "script/interpreter.h"
#include "utilstrencodings.h"
#include <iostream>

using namespace satin;

void engine::run()
{
  const int flags = SCRIPT_VERIFY_P2SH
    | SCRIPT_VERIFY_CHECKLOCKTIMEVERIFY
    | SCRIPT_VERIFY_CHECKSEQUENCEVERIFY;

  std::vector<std::vector<unsigned char> > stack;
  CScript script;
  ScriptError error;

  script << OP_1 << OP_DUP << OP_HASH160 << OP_5 << OP_EQUALVERIFY;
  BaseSignatureChecker sigchecker;
  auto result = EvalScript(stack, script, flags, sigchecker, &error);
  std::cout << error << std::endl;
}
