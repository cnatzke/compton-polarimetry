//////////////////////////////////////////////////////////////////////////////////
// Creates and analyses histograms for Compton Polarimetry of GRIFFIN data
//
// Author:        Connor Natzke (cnatzke@triumf.ca)
// Creation Date: 05-11-2021
// Last Update:   05-11-2021
// Usage:
//
//////////////////////////////////////////////////////////////////////////////////
#include <iostream>
//#include <map>
#include "TGRSIUtilities.h"
#include "TParserLibrary.h"
#include "TEnv.h"

#include "ComptonPolarimetry.h"


int main(int argc, char **argv)
{
    if (argc == 1) { // no inputs given
        PrintUsage(argv);
        return 0;
    }
    else if (argc == 2) {
        std::cout << "Gee Billy, two arguments!?" << std::endl;
        return 0;
    }
    else if (argc == 3) {
        InitGRSISort();
        // makes output look nicer
        std::cout << std::endl;
    }
    return 0;
} // main()

void InitGRSISort(){
    // makes time retrival happy and loads GRSIEnv
    grsi_path = getenv("GRSISYS");
    if(grsi_path.length() > 0) {
        grsi_path += "/";
    }
    grsi_path += ".grsirc";
    gEnv->ReadFile(grsi_path.c_str(), kEnvChange);

    TParserLibrary::Get()->Load();
} // end InitGRSISort

/******************************************************************************
 * Prints usage message and version
 *****************************************************************************/
void PrintUsage(char* argv[]){
    std::cerr << argv[0] << " Version: " << ComptonPolarimetry_VERSION_MAJOR << "." << ComptonPolarimetry_VERSION_MINOR << "\n"
              << "\n----- Matrix Creation ------\n"
              << "usage: " << argv[0] << " analysis_tree_1 analysis_tree_2 ... analysis_tree_n\n"
              << " analysis_tree_n: unpacked GRIFFIN analysis tree\n"
              << "\n----- Matrix Analysis ------\n"
              << "usage: " << argv[0] << " matrix_file\n"
              << " matrix_file: ROOT file containing sorted matrices\n"
              << std::endl;
} // end PrintUsage
