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

#include <cstdlib>
#include <string>
#include <fstream>

#include "../version_autogen.hpp"
#include "lib/help.hpp"

using namespace std;
using namespace satin;

int main(int argc, char *argv[])
{
  try
  {
    //
    // Printing options
    //
    po::options_description printing_params("Printing options");
    printing_params.add_options()
      ("copyright,c", po::value<string>(), "Overwrite the default copyright holder")
      ("version,v", "Write verbose satin-blocks version string to stdout")
      ("verion-number,n", "Write version number to stdout")
      ("about,a", "Write satin-blocks about to stdout")
      /*("help,h", "Write help to stdout")*/;

    //
    // Process the actual command line arguments given by the user
    //
    po::options_description cmdline_options;
    cmdline_options.add(printing_params);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(cmdline_options).run(), vm);
    po::notify(vm);

    std::string copyright_holder = satin::default_copyright;
    if (vm.count("copyright"))
      copyright_holder = vm["copyright"].as<string>();

    // Process the printing options
    if (vm.count("version") || vm.count("verion-number")) {
      bool verbose = vm.count("version");
      if (verbose)
        cout << "satin-blocks ";

      cout << MAJOR_VERSION << '.'
           << MINOR_VERSION << '.'
           << REVISION << '.'
           << BUILD_NUMBER << std::endl;

      if (verbose) {
        cout << "git-hash: " << COMMIT_HASH << '\n';
        copyright_short(copyright_holder);
      }
      exit(EXIT_SUCCESS);
    }
    if (vm.count("about")) {
      about(copyright_holder);
      exit(EXIT_SUCCESS);
    }


    //
    // Run the application
    //

    cout << "Utility to print generic help and program information to stdout." << "\n"
         << "Use it in your satin scripts to avoid reimplementing generic parameter handling." << "\n";
    help(cmdline_options, cerr);

    exit(EXIT_SUCCESS);
  }
  catch (std::exception &ex)
  {
    cerr << ex.what() << endl;
    exit(EXIT_FAILURE);
  }
}
