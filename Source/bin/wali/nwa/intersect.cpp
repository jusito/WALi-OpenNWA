#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

#include "nwa.hpp"

//#include <boost/program_options/options_description.hpp>
//#include <boost/program_options/positional_options.hpp>
//#include <boost/program_options/variables_map.hpp>
//#include <boost/program_options/parsers.hpp>

//namespace po = boost::program_options;

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cerr;
using std::endl;
using std::exit;

int main(int argc, char** argv)
{
    //po::options_description options("Allowed options");

    //options.add_options()
    //    ("help", "Output help message")
    //    ("input-file", po::value<vector<string>>(), "The file to input")
    //     ("output-file", po::value<vector<string>>(), "The file to write")
    //   ;

    //po::variables_map args;
    //po::store(po::parse_command_line(argc, argv, options), args);
    //po::notify(args);

    //if (args.count("help")) {
    //    cerr << options << endl;
    //    return 1;
    //}


    //if (args.count("input-file")) {
    //    cout << "Read from " << args["input-file"].as<vector<string>>() << endl;
    //}
    //if (args.count("output-file")) {
    //    cout << "Write to " << args["output-file"].as<vector<string>>() << endl;
    //}

    if (argc != 5 || argv[1] != std::string("-o")) {
        cerr << "Syntax: " << argv[0] << " -o dotfilename nwa1 nwa2\n";
        exit(1);
    }

    // Open the files
    ifstream infile1(argv[3]);
    if (!infile1.good()) {
        cerr << "Error opening input file " << argv[3] << "\n";
        exit(2);
    }

    ifstream infile2(argv[4]);
    if (!infile2.good()) {
        cerr << "Error opening input file " << argv[4] << "\n";
        exit(2);
    }

    ofstream outfile(argv[2]);
    if (!outfile.good()) {
        cerr << "Error opening output file " << argv[2] << "\n";
        exit(3);
    }

    Nwa::Nwa_RefPtr nwa1 = Nwa::read_nwa(infile1);
    Nwa::Nwa_RefPtr nwa2 = Nwa::read_nwa(infile2);
    
    Nwa::Nwa_RefPtr inter = new Nwa::NWA();
    inter->intersect(*nwa1, *nwa2);
    inter->print(outfile);
}


// Yo emacs!
// Local Variables:
//     c-basic-offset: 4
//     indent-tabs-mode: nil
// End:
