// Copyright (c) 2017 hrobeers (https://github.com/hrobeers)
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include "../version_autogen.hpp"
#include "compile/compiler.hpp"

using namespace std;
using namespace satin;

inline void showHelp(const po::options_description &cmdline_options, std::ostream &stream = cout)
{
  stream << cmdline_options << "\n";
}

inline void about(std::ostream &stream = cout)
{
  stream << "satin-compile is the script compilation engine of the satin-blocks project." << "\n";
  stream << "\n";
  stream << "Copyright (c) 2017 hrobeers (https://github.com/hrobeers)" << "\n";
  stream << "Distributed under the MIT/X11 software license, see the accompanying file LICENSE or http://www.opensource.org/licenses/mit-license.php." << "\n";
}

int main(int argc, char *argv[])
{
  try
  {
    //
    // Positional options
    //
    po::positional_options_description positional_options;
    positional_options.add("input-file", -1);

    po::options_description positional_params;
    positional_params.add_options()
      ("input-file", po::value<string>(), "Optional input file (can also be provided through stdin)");


    //
    // Generic options
    //
    po::options_description generic_params("Generic options");
    generic_params.add_options()
      ("version,v", "Print version string")
      ("about,a", "About this application")
      ("help,h", "Print help");

    //
    // Process the actual command line arguments given by the user
    //
    po::options_description cmdline_options;
    cmdline_options.add(positional_params).add(generic_params);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(positional_options).run(), vm);
    po::notify(vm);

    // Process the generic options
    if (vm.count("version")) {
      cout << MAJOR_VERSION << '.'
           << MINOR_VERSION << '.'
           << REVISION << '.'
           << BUILD_NUMBER << '\n'
           << COMMIT_HASH << '\n';
      exit(EXIT_SUCCESS);
    }
    if (vm.count("help")) {
      showHelp(cmdline_options);
      exit(EXIT_SUCCESS);
    }
    if (vm.count("about")) {
      about();
      exit(EXIT_SUCCESS);
    }


    //
    // Run the application
    //

    if (true)
    {
      if (vm.count("input-file"))
      {
        std::ifstream ifs;
        ifs.open(vm["input-file"].as<string>(), std::ifstream::in);
        compiler::run(ifs);
      }
      else
        compiler::run(std::cin);
    }
    else
    {
      showHelp(cmdline_options, cerr);
    }

    exit(EXIT_SUCCESS);
  }
  catch (std::exception &ex)
  {
    cerr << ex.what() << endl;
    exit(EXIT_FAILURE);
  }
}
