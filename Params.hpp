#ifndef Params_h
#define Params_h
#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <vector>
#include <fstream>

using namespace std;

class Params {
private:
    ofstream outputFile;
    string outputFileName;
    vector<string> keyWords;
    char* path;
    bool isVerbose;
    bool isRecursive;
    bool isCaseInsensitive;
    string convertBoolToYOrN(bool switchValue){return switchValue?"Yes":"No";};
    string command;
public:
    Params(){};
    Params(int argc, char * argv[]);
    void print();
};




#endif /* Params_h */
