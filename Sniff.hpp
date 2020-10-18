#ifndef Sniff_hpp
#define Sniff_hpp

#include "FileID.hpp"
#include <dirent.h>
#include <sys/stat.h>

class Sniff {
private:
    Params params;
    string currentDir;
    char* pathName;
    vector<string> words;
    vector<FileID> suspectFiles;
    struct dirent* entry;
    static string trim(string word);
    static string toLower(string word);
    void travel(const string& path, const string& nextDir);
    FileID oneFile(const string& fileName, const string& path);
public:
    Sniff() = default;
    Sniff(int argc, char* argv[]);
    void run();
    ~Sniff() = default;
};

#endif /* Sniff_hpp */

/*
 tool.hpp include many basic headers
 Params.hpp include tool.hpp
 FileID.hpp include Params.hpp
 Sniff.hpp include FileID.hpp
 */
