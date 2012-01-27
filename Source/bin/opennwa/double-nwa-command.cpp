#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

#include "opennwa/NWA.hpp"
#include "opennwa/NWAParser.hpp"

#include "opennwa/construct/constructions.hpp"

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cerr;
using std::endl;
using std::exit;

using opennwa::NWARefPtr;
using opennwa::read_nwa;
using opennwa::construct::CONSTRUCTION_FUNCTION;

int main(int argc, char** argv)
{
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

    NWARefPtr nwa1 = read_nwa(infile1);
    NWARefPtr nwa2 = read_nwa(infile2);
    
    NWARefPtr result = CONSTRUCTION_FUNCTION(*nwa1, *nwa2);

    result->print(outfile);
}


// Yo emacs!
// Local Variables:
//     c-basic-offset: 4
//     indent-tabs-mode: nil
// End:
