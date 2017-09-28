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
#include "script/script.h"
#include "utilstrencodings.h"

#include "compile/compiler.hpp"

#include <map>

namespace satin {
  std::map<std::string, opcodetype> opcodes;
  void init_opcodes();
  std::istream& read_next_operation(std::istream& in, CScript& out);
  bool isHexString(const char* s);
}

using namespace satin;

void compiler::run(std::istream &input)
{
  init_opcodes();
  CScript script;

  while(read_next_operation(input, script)) {}

  auto v = ToByteVector(script);
  std::cout.write((char*)v.data(), v.size());
  std::cout << std::flush;
}

void satin::init_opcodes()
{
  // Map opcodes to standard GetOpName() result
  for (unsigned char i=0; i<OP_INVALIDOPCODE; i++)
    opcodes[GetOpName((opcodetype)i)] = (opcodetype)i;

  // Map missing pushcodes
  for (int i=0; i<16; i++)
    {
      std::stringstream pushcode;
      pushcode << "OP_" << i+1;
      opcodes[pushcode.str()] = (opcodetype)(OP_1 + i);
    }
}

std::istream& satin::read_next_operation(std::istream& in, CScript& out)
{
  const std::string whitespace = " \t\r\n";
  char c = ' ';
  // Skip whitespace
  while(in && std::any_of(whitespace.cbegin(), whitespace.cend(), [c](char w){ return c==w; }))
    {
      in.get(c);
    }
  // Read until next whitespace
  std::stringstream operation;
  while(in && !std::any_of(whitespace.cbegin(), whitespace.cend(), [c](char w){ return c==w; }))
    {
      operation << c;
      in.get(c);
    }

  std::string str_op = operation.str();

  if (!str_op.size()) return in;
  const char* sz_op = str_op.c_str();
  switch (sz_op[0])
    {
    case '0':
      // Data pushes start with "0x"
      if (sz_op[0]=='0' && sz_op[1]=='x' && isHexString(&sz_op[2]))
        {
          auto data = ParseHex(&sz_op[2]);
          out << data;
          return in;
        }
      break;

    default:
      // Try translating operation to opcode and write to output
      for (char &c : str_op) c = toupper(c); // case insensitive
      auto opit = opcodes.find(sz_op);
      if (opit != opcodes.end())
        {
          out << opit->second;
          return in;
        }
      break;
    }

  out << OP_INVALIDOPCODE;
  return in;
}

bool satin::isHexString(const char* s)
{
  const std::string hex_chars = "0123456789abcdef";
  for (int i=0; s[i]!='\0'; i++)
    {
      if (!std::any_of(hex_chars.cbegin(), hex_chars.cend(), [s,i](char h){ return s[i]==h; }))
        return false;
    }
  return true;
}
