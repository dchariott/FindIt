//
//  Params.hpp
//  SysProP2
//
//  Created by Prehax Xu on 9/15/20.
//

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
    bool isVerbose = false;
    bool isRecursive = false;
    bool isCaseInsensitive = false;
    string convertBoolToYOrN(bool switchValue);
    string command;
public:
    Params(){};
    Params(int argc, char * argv[]);
    void print();
};




#endif /* Params_h */
