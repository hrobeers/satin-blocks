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

#ifndef SATIN_HELP_HPP
#define SATIN_HELP_HPP

#include <string>
#include <iostream>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

namespace satin {

  const std::string default_copyright = "hrobeers (https://github.com/hrobeers)";

  inline void help(const po::options_description &cmdline_options, std::ostream &stream = std::cout)
  {
    stream << cmdline_options << "\n";
  }

  inline void copyright(const std::string &copyright_holder = default_copyright, std::ostream &stream = std::cout)
  {
    stream << "Copyright (c) 2017 " << copyright_holder << "\n"
           << "\n"
           << "This program is free software: you can redistribute it and/or modify" << "\n"
           << "it under the terms of the GNU General Public License as published by" << "\n"
           << "the Free Software Foundation, either version 3 of the License, or" << "\n"
           << "(at your option) any later version." << "\n"
           << "\n"
           << "This program is distributed in the hope that it will be useful," << "\n"
           << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << "\n"
           << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << "\n"
           << "GNU General Public License for more details." << "\n"
           << "\n"
           << "You should have received a copy of the GNU General Public License" << "\n"
           << "along with this program.  If not, see <http://www.gnu.org/licenses/>."
           << std::endl;
  }

  inline void copyright_short(const std::string &copyright_holder = default_copyright, std::ostream &stream = std::cout)
  {
    stream << "Copyright (c) 2017 " << copyright_holder << "\n"
           << "satin-blocks comes with ABSOLUTELY NO WARRANTY." << "\n"
           << "You may redistribute copies of satin blocks" << "\n"
           << "under the terms of the GNU General Public License."
           << std::endl;
  }

  inline void about(const std::string &copyright_holder = default_copyright, std::ostream &stream = std::cout)
  {
    stream << "Satoshi interpreter building blocks" << "\n"
           << "A commandline toolbox for composing Bitcoin script development tools." << "\n"
           << "Satin is architected as a collection of pipable building blocks and composed applications," << "\n"
           << "inspired by git, gstreamer and the Unix philosophy." << "\n";
    stream << "\n";
    copyright(copyright_holder, stream);
  }
}

#endif // SATIN_HELP_HPP
