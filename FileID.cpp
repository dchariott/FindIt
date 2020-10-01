#include "FileID.hpp"

//--------------------------------------------------------------
void FileID::print(ostream& out){
    out << "iNode number\t\t\tPath"
        << iNodeNumber << "\t\t\t" << pathname
        << endl;
}

//--------------------------------------------------------------

void FileID::insertSniffWord(const string sniffWord){
    if (sniffWords.find(sniffWord) == -1 ){
        sniffWords.push_back(sniffWord);
    }
}