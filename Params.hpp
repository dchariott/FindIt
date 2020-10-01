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
    string convertBoolToYOrN(bool switchValue){ return switchValue? "Yes" : "No"; }
    string command;
public:
    Params() = default;
    Params(int argc, char * argv[]);
    const bool isVerbose const() { return isVerbose; }
    const bool isRecursive const() { return isRecursive; }
    const bool isCaseInsensitive const() { return isCaseInsensitive; }
    void print();
    ~Params(){ if(outputFile.is_open()) outputFile.close(); }
};




#endif /* Params_h */
