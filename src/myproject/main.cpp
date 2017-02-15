#include <string>
#include <iostream>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include "../version_autogen.hpp"

using namespace std;

inline void showHelp(const po::options_description &cmdline_options, std::ostream &stream = cout)
{
    stream << cmdline_options << "\n";
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
    bool exit = false;
    if (vm.count("version")) {
      cout << MAJOR_VERSION << '.'
           << MINOR_VERSION << '.'
           << REVISION << '.'
           << BUILD_NUMBER << '\n'
           << COMMIT_HASH << '\n';
      exit = true;
    }
    if (vm.count("help")) {
      showHelp(cmdline_options);
      exit = true;
    }
    if (exit) return 0;


    //
    // Run the application
    //

    if (false)
    {
    }
    else
    {
      showHelp(cmdline_options, cerr);
    }

    return 0;
  }
  catch (std::exception &ex)
  {
    cerr << ex.what() << endl;
    return 1;
  }
}
