#include "FileID.hpp"

//--------------------------------------------------------------
void FileID::print(ostream& out){
    out << "iNode number:" << "\t\t" << setw(60) << left << "Path:" 
        << "\tFound search words:"
        << endl << iNodeNumber << "\t\t" << setw(60) << left << pathname << "\t";
    printSniffWords(out);
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

void FileID::printSniffWords(ostream& out){
    for (int k = 0; k < sniffWords.size(); ++k) {
        out << sniffWords[k];
        if (k < sniffWords.size() - 1){
            out << ", ";
        }
    }
    out << endl;
}