#include "Params.hpp"

Params::Params(int argc, char* argv[]) {
    int c=0;
    int opt_index=0;
    extern char *optarg;
    extern int optind, opterr, optopt;
    
    isVerbose = false;
    isRecursive = false;
    isCaseInsensitive = false;

    static struct option long_options[]={
        {"dir", required_argument, NULL, 'd'},
        {"verbose", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0}
    };
    
    // This loop only deal with options and their arguments
    while(true) {
        c=getopt_long(argc, argv, "iRo:d:", long_options, &opt_index);
        if (c==-1) break;

        switch (c){
            case 'd':
                path = optarg;
                break;
            case 'i':
                isCaseInsensitive = true;
                break;
            case 'R':
                isRecursive = true;
                break;
            case 'o':
                outputFileName = optarg;
                outputFile.open(outputFileName, ofstream::app);
                break;
            case 'v':
                isVerbose = true;
                break;
            default:
                cout << "Option: '" << (char)c << "' doesn't exist.\n";
                break;
        }
        printf("optind: %d\n", optind);
    }
    // fill command
    for (int k=0; k<argc; ++k) {
        command = command + argv[k] + " ";
        // fill vector keyWords
        if (k>=optind) {
            keyWords.push_back(argv[k]);
            printf("%s\n", argv[k]);
        }
    }
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
