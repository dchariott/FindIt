#pragma once
#include <vector>
#include <string>

class FileID {
private:
    string name;
    string iNodeNumber;
    string pathname;
    vector<string> sniffWords;
public:
    FileID() = default;
    FileID(const string name, const string iNodeNumber, const string pathname): name(name), iNodeNumber(iNodeNumber),
    pathname(pathname) {}
    void print(ostream& out);
    void insertSniffWord(string sniffWord);
};