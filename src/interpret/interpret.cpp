// Copyright (c) 2017 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#include "script/interpreter.h"
#include "script/script.h"
#include "utilstrencodings.h"

#include "interpret/interpret.hpp"

#include <map>

namespace satin {
  std::map<std::string, opcodetype> opcodes;
  void init_opcodes();
  std::istream& read_next_operation(std::istream& in, CScript& out);
  bool isHexString(const char* s);
}

using namespace satin;

void interpret::run(std::istream &input)
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

  switch (operation.peek())
    {
    case '0':
      // Data pushes start with "0x"
      const char* op_str;
      op_str = operation.str().c_str();
      if (op_str[0]=='0' && op_str[1]=='x' && isHexString(&op_str[2]))
        {
          auto data = ParseHex(&op_str[2]);
          out << data;
        }
      break;

    default:
      // Try translating operation to opcode and write to output
      auto opit = opcodes.find(operation.str());
      if (opit != opcodes.end())
        {
          out << opit->second;
        }
      break;
    }
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
