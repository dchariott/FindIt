#include "FileID.hpp"

//--------------------------------------------------------------
void FileID::print(ostream& out){
    out << "iNode number\t\t\tPath"
        << iNodeNumber << "\t\t\t" << pathname
        << endl;
}

//--------------------------------------------------------------

void FileID::insertSniffWord(const string sniffWord){
    for (string word : sniffWords){
        if (word == sniffWord){
            return;
        }
    }
    sniffWords.push_back(sniffWord);
}