#include "Params.hpp"

Params::Params(int argc, char* argv[]) {
    int c=0;
    int opt_index=0;
    extern char *optarg;
    extern int optind, opterr, optopt;
    
    isVerbose = false;
    isRecursive = false;
    isCaseInsensitive = false;
    path = new char('.');
    keyWords = "";

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
    }
    // fill command
    for (int k=0; k<argc; ++k) {
        command = command + argv[k] + " ";
        // fill vector keyWords
        if (k>=optind) {
            if (keyWords == "") keyWords = string(argv[k]);
            else keyWords = keyWords + " " + argv[k];
        }
    }
    // Detect keyWords content, Add usage comment
    if (keyWords == "") {
        cerr << "Command: \"" << command << "\" error. Not enough arguments.\
        \n\nusage: findit [options] switch_argument keywords\
        \noptions:\
        \n\t-d, --dir (required) needs a path as argument, search from it. \
        \n\t-o (optional) needs a filename as the output\
        \n\t--verbose (optional) print name of every file that is opened. \
        \n\t-R (optional) do a recursive search if this switch is present. \
        \n\t-i (optional) do a case-insensitive search.\
        \narguments:\
        \n\tkeywords is a string of search words, separated by spaces.";
        bye();
        exit(0);
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
