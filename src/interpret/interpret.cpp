// Copyright (c) 2017 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#include "interpret/interpret.hpp"

#include "script/interpreter.h"
#include "script/script.h"

using namespace satin;

void interpret::run()
{
  CScript script;

  script << OP_1 << OP_DUP << OP_HASH160 << OP_5 << OP_EQUALVERIFY;
  auto v = ToByteVector(script);
  std::cout.write((char*)v.data(), v.size());
  std::cout << std::flush;
}
