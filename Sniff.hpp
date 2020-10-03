#ifndef Sniff_hpp
#define Sniff_hpp

#include "FileID.hpp"
#include <dirent.h>
#include <sys/stat.h>

class Sniff {
private:
    Params * params;
    string currentDir;
    char * pathName;
    vector<string> words;
    vector<FileID> fileNames;
    struct dirent * entry;
public:
    Sniff(int argc, char * argv[]);
    void oneDir();
    FileID oneFile(string fileName);
    string trim(string word);
    string toLower(string word);
    
};

#endif /* Sniff_hpp */

/*
 tool.hpp include many basic headers
 Params.hpp include tool.hpp
 FileID.hpp include Params.hpp
 Sniff.hpp include FileID.hpp
 */
