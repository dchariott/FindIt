#include "Sniff.hpp"

Sniff::Sniff(int argc, char * argv[]) {
    // Initial params
    params = new Params(argc, argv);
    pathName = params->getPath();
//    params->print();
    // Transform space separated string into vector of words
    string word;
    istringstream instr(params->getKeyWords());
    for(;;) {
        if( instr.eof()) break;
        instr >> word;
        if (params->isCaseInsensitiveSwitchOn()) {
            // Change to lower case if -i
            word = toLower(word);
        }
        words.push_back(word);
    }
//    for (int i=0; i<words.size(); i++) {
//        cout << words[i] << endl;
//    }
    
}
//----------------------
void Sniff::oneDir() {
    FileID tempID;
    DIR * dirp;
    if ((dirp = opendir(pathName)) == NULL) {
        cout << "Open Directory " << pathName << " Error." << endl;
    }
    cout << "\nDirectory \"" << pathName << "\" includes: " << endl;
    for(;;) {
        entry = readdir(dirp);
        if (entry==nullptr) break;
        // Skip the first two directories
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0)
            continue;
        else {
            switch (entry->d_type) {
                case DT_DIR:
                    cout << "Directory: " << entry->d_name << endl;
                    break;
                case DT_REG:
                    cout << "File: " << entry->d_name << endl;
                    tempID = oneFile(string(entry->d_name));
                    if (!tempID.isSniffWordsEmpty()) {
                        fileNames.push_back(tempID);
                    }
                    break;
                case DT_LNK:
                    cout << "Sym Link: " << entry->d_name << endl;
                    break;
                default:
                    cout << "Skip file: " << entry->d_name << endl;
                    break;
            }
            /*
            // This is declared in Lecture, but it's not working
            cout << "Type code: " << entry->d_type << " -> ";
            if (S_ISDIR(entry->d_type)) {
                // If directory
                cout << "Directory: " << entry->d_name << endl;
            } else if (S_ISREG(entry->d_type)) {
                // If regular file
                cout << entry->d_name << endl;
            } else if (S_ISLNK(entry->d_type)) {
                // If Symbolic link
                cout << "Sym link: " << entry->d_name << endl;
            } else if (S_ISSOCK(entry->d_type)) {
                // If socket
                cout << "Socket: " << entry->d_name << endl;
            } else if (S_ISFIFO(entry->d_type)) {
                // If pipe or socket
                cout << "Pipe: " << entry->d_name << endl;
            } else {
                cout << "Skip file: " << entry->d_name << endl;
            }
             */
        }
    }
    cout << endl;
    closedir(dirp);
    // Print the files that includes keywords.
    for (int k=0; k<fileNames.size(); k++) {
        fileNames[k].print(cout);
    }
    cout << "\nDirectory \"" << pathName << "\" is done." << endl;
}
//--------------------------------------Search a file
FileID Sniff::oneFile(string fileName) {
    FileID fileID(fileName, entry->d_ino, string(pathName)+"/"+fileName);
    ifstream cFile(string(pathName)+"/"+fileName);
    string inFileWord;
    while (true) {
        if (cFile.eof()) break;
        cFile >> inFileWord;
        inFileWord = trim(inFileWord);
        if (params->isCaseInsensitiveSwitchOn()) {
            // Change to lower case if -i
            inFileWord = toLower(inFileWord);
        }
        for (int k=0; k<words.size(); k++) {
            if (words[k] == inFileWord) {
                fileID.insertSniffWord(words[k]);
                break;
            }
        }
    }
    
    cFile.close();
    return fileID;
}
//--------------------------------Take off non-alpha character
string Sniff::trim(string word) {
    for (string::iterator k=word.begin(); k<word.end(); k++) {
        if (!isalpha(word.at(k - word.begin()))) {
            word.erase(k);
            k--;
        }
    }
    return word;
}
//--------------------------------To lower case string
string Sniff::toLower(string word) {
    for (int k=0; k<word.size(); k++) {
        if (isupper(word[k])) {
            word[k] = tolower(word[k]);
        }
    }
    return word;
}

