//
//  Params.cpp
//  SysProP2
//
//  Created by Prehax Xu on 9/15/20.
//

#include "Params.hpp"

Params::Params(int argc, char* argv[]) {
    int c;
    int opt_index=0;
    extern char *optarg;
    extern int optind, opterr, optopt;

    static struct option long_options[]={
        {"dir", required_argument, NULL, 'd'},
        {"verbose", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0}
    };
    
    // For test options
    for (int j = 0; j < argc; ++j) {
        c=getopt_long(argc, argv, "iRo:d:", long_options, &opt_index);
        if (c==-1) break;

        command += argv[j];
        command += " ";
        switch (c){
            case 0:
                std::cout << "No option" << std::endl;
                break;
            case 'd':
                path = optarg;
                command += "--dir ";
                command += path;
                command += " ";
                break;
            case 'i':
                isCaseInsensitive = true;
                break;
            case 'R':
                isRecursive = true;
                break;
            case 'o':
                command += optarg;
                command += " ";
                outputFile.open(optarg, ofstream::app);
                outputFileName = optarg;
                break;
            case 'v':
                isVerbose = true;
                break;
            default:
                keyWords.push_back(optarg);
        }
    }
}

//--------------------------------------------------------------
string Params::convertBoolToYOrN(bool switchValue) {
    if (switchValue){
        return "Yes";
    }
    return "No";
}

//--------------------------------------------------------------
void Params::print() {
    if(outputFile.is_open()){
        outputFile << "Command: " << command << endl
                   << "\tVerbose? " << convertBoolToYOrN(isVerbose) << endl
                   << "\tCase Insensitive? " << convertBoolToYOrN(isCaseInsensitive) << endl
                   << "\tRecursive? " << convertBoolToYOrN(isRecursive) << endl
                   << "\tOutput file name: " << outputFileName << endl
                   << "\tDirectory: " << path << endl;
    } else {
        cout << "Command: " << command << endl
                   << "\tVerbose? " << convertBoolToYOrN(isVerbose) << endl
                   << "\tCase Insensitive? " << convertBoolToYOrN(isCaseInsensitive) << endl
                   << "\tRecursive? " << convertBoolToYOrN(isRecursive) << endl
                   << "\tOutput file name: " << outputFileName << endl
                   << "\tDirectory: " << path << endl;
    }
}
