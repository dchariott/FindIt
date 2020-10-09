#ifndef Params_hpp
#define Params_hpp
#include "tools.hpp"
#include <vector>
#include <string>
#include <getopt.h>

class Params {
private:
    ofstream outputFile;
    string outputFileName;
    string keyWords;
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
    const string getKeyWords() { return keyWords; }
    ofstream& getOutputFileStream() { return outputFile; }
    char * getPath () { return path;}
    void print();
    ~Params(){ if(outputFile.is_open()) outputFile.close(); }
};




#endif /* Params_hpp */
