#include "Sniff.hpp"

//---------------------------- Initialize members in this object
Sniff::Sniff(int argc, char* argv[]): params(argc, argv) {
    pathName = params.getPath();

    // Transform space separated string into vector of words
    string word;
    istringstream instr(params.getKeyWords());
    for(;;) {
        if( instr.eof()) break;
        instr >> word;
        if (params.isCaseInsensitiveSwitchOn()) {
            // Change to lower case if -i
            word = toLower(word);
        }
        words.push_back(word);
    }    
}

//---------------------------- Run
void Sniff::run() {
    ofstream& outputFile = params.getOutputFileStream();
    currentDir = string(pathName);
    string::size_type startOfDName = currentDir.find_last_of("/");
    currentDir = currentDir.substr(startOfDName + 1, string::npos);

    travel(pathName, currentDir);

    // params.print();

    for (FileID file : suspectFiles) {
        if (params.getOutputFileStream().is_open()){
            outputFile << endl;
            file.print(outputFile);
            outputFile << endl;
        } else {
            cout << endl;
            file.print(cout);
            cout << endl;
        }
    }
}

//---------------------------- Travel function
void Sniff::travel(const string& path, const string& nextDir) {
    FileID tempID;

    int status = chdir(nextDir.c_str());
    if (status == -1 ){
        cout << "There was a problem opening the directory: " << nextDir << endl;
        abort();
    }

    DIR * dirp;
    dirp = opendir("./");

    if(params.isVerboseSwitchOn()){
        cout << "Processing the Directory: " << nextDir << endl;
    }

    for(;;) {
        entry = readdir(dirp);
        if (entry==nullptr) break;
        // Skip the first two directories
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0)
            continue;
        else {
            switch (entry->d_type) {
                case DT_DIR:
                    if(params.isRecursiveSwitchOn()){
                        if (params.isVerboseSwitchOn()){
                            cout << "Opening Directory: " << entry->d_name << endl;
                        }
                        travel(path+"/"+entry->d_name, entry->d_name);
                        status = chdir("..");
                    } else{
                        if (params.isVerboseSwitchOn()){
                            cout << "Skipping Directory: " << entry->d_name << endl;
                        }
                    }
                    break;
                case DT_REG:
                    if (params.isVerboseSwitchOn()){
                        cout << "Searching file: " << entry->d_name << endl;
                    }
                    tempID = oneFile(string(entry->d_name), path);
                    if (!tempID.isSniffWordsEmpty()) {
                        suspectFiles.push_back(tempID);
                    }
                    break;
                default:
                    break;
            }
        }
    }

    closedir(dirp);

    cout << "\nDirectory \"" << nextDir << "\" is done." << endl;
    if (params.isVerboseSwitchOn()){
        cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    }
}

//-------------------------------------- Search a file
FileID Sniff::oneFile(const string& fileName, const string& path) {
    FileID fileID(fileName, entry->d_ino, path+"/"+fileName);
    ifstream cFile(fileName);
    string inFileWord;
    while (true) {
        if (cFile.eof()) break;
        cFile >> inFileWord;
        inFileWord = Sniff::trim(inFileWord);
        if (params.isCaseInsensitiveSwitchOn()) {
            // Change to lower case if -i
            inFileWord = Sniff::toLower(inFileWord);
        }
        for (string& sniffWord : words) {
            if (sniffWord == inFileWord) {
                if(params.isVerboseSwitchOn()){
                    cout << fileName << ": a search word was found in the file: " << sniffWord << endl;
                }
                fileID.insertSniffWord(sniffWord);
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

