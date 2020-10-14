#include "FileID.hpp"

//--------------------------------------------------------------
void FileID::print(ostream& out){
    out << "iNode number: " << iNodeNumber 
        << "\t\tPath: " << pathname
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

//--------------------------------------------------------------

void FileID::printSniffWord(ostream& out){
    out << "Sniff words: ";
    for (string word : sniffWords) {
        out << word << " ";
    }
    out << endl;
}