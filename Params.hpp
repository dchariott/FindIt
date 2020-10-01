#ifndef Params_h
#define Params_h
#include "tools.hpp"
#include <vector>
#include <string>
#include <getopt.h>

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
    const bool isVerboseSwitchOn() const { return isVerbose; }
    const bool isRecursiveSwitchOn() const { return isRecursive; }
    const bool isCaseInsensitiveSwitchOn() const { return isCaseInsensitive; }
    void print();
    ~Params(){ if(outputFile.is_open()) outputFile.close(); }
};




#endif /* Params_h */
