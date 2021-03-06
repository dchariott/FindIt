#pragma once
#include "Params.hpp"
#include "iomanip"

class FileID {
private:
    string name;
    uint32_t iNodeNumber;
    string pathname;
    vector<string> sniffWords;
    void printSniffWords(ostream& out);
public:
    FileID() = default;
    FileID(const string name, const uint32_t iNodeNumber, const string pathname): name(name), iNodeNumber(iNodeNumber),
    pathname(pathname) {}
    void print(ostream& out);
    void insertSniffWord(string sniffWord);
    bool isSniffWordsEmpty() { return sniffWords.empty(); }
    ~FileID() = default;
};
