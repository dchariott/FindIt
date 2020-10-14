# FindIt
10-02-20 Longlong
-i option is working;
can search keywords in one directory

10-14-20 Longlong {
in main.cpp, change sniff.oneDir() to sniff.run();

in Sniff class, add run and travel function, but not completed yet. move print codes to run() function. I didn't figure out how to implement travel function yet. I'm not sure the directory processed in oneDir() should be currentDir or pathName, and we might need to change currentDir's type to c-string.

in FileID class, add print sniff words function. I changed the format of printing iNode number and pathname, because it's difficult to add a column SniffWords.

Now the output:
prehax@PreBook FindIt % findit -d ./testDir -i csci trump sunny class

---------------------------------------------------------------
        Dylan Chariott & Longlong Xu
        CSCI 4547/6647
        Wed Oct 14 2020 19:24:53
---------------------------------------------------------------

Directory "./testDir" is done.

iNode number: 45708774          Path: ./testDir/note.txt
sniff words: csci class 


iNode number: 45708776          Path: ./testDir/hlinkNote.txt
sniff words: csci class 


iNode number: 45708777          Path: ./testDir/election.txt
sniff words: trump 


iNode number: 45708778          Path: ./testDir/diary.txt
sniff words: sunny class 


---------------------------------------------------------------
Normal termination.
}