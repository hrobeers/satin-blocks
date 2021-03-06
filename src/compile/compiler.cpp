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
  const std::string opcode_prefix = "OP_";

  std::map<std::string, opcodetype> opcodes;
  void init_opcodes();
  std::istream& read_next_operation(std::istream& in, CScript& out);
  bool is_op_prefixed(const std::string& str);
  bool is_hex(const char* s);
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
  // Map opcodes to GetOpName() result
  for (unsigned char i=0; i<OP_INVALIDOPCODE; i++)
    {
      const char* code;
      std::string op_name = GetOpName((opcodetype)i);

      // strip prefix if present
      if (is_op_prefixed(op_name))
        code = &op_name.c_str()[opcode_prefix.size()];
      else
        code = op_name.c_str();

      // map string to opcode
      opcodes[code] = (opcodetype)i;
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
    case '#':
      // comment lines start with #
      while(in && c != '\n') in.get(c);
      return in;

    case '0':
      // Data pushes start with "0x"
      if (sz_op[0]=='0' && sz_op[1]=='x' && is_hex(&sz_op[2]))
        {
          auto data = ParseHex(&sz_op[2]);
          out << data;
          return in;
        }
      break;

    default:
      // Try translating operation to opcode and write to output
      for (char &c : str_op) c = toupper(c); // case insensitive
      // remove the OP_ prefix if present (mapped without)
      if (is_op_prefixed(str_op))
        sz_op = &sz_op[opcode_prefix.size()];
      // find the opcode
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

bool satin::is_op_prefixed(const std::string& str)
{
  return opcode_prefix.compare(0,opcode_prefix.size(),
                               str, 0, opcode_prefix.size()) == 0;
}

bool satin::is_hex(const char* s)
{
  const std::string hex_chars = "0123456789abcdef";
  for (int i=0; s[i]!='\0'; i++)
    {
      if (!std::any_of(hex_chars.cbegin(), hex_chars.cend(), [s,i](char h){ return s[i]==h; }))
        return false;
    }
  return true;
}
