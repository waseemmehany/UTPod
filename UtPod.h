//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"

//UtPod class declaration
class UtPod {
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:


    //Default constructor
    UtPod();

    //Constructor with size parameter
    UtPod(int size);


    // ADD & REMOVE
    int addSong(Song const &s);
    int removeSong(Song const &s);
    int findPosition(Song const &s);

    // ACTIONS
    void shuffle();
//    void split();
//    void interleave();
    void showSongList();
    int getLength();

    // MEMORY
    void clearMemory();
    int getTotalMemory() { return memSize; }
    int getRemainingMemory();


    ~UtPod();

};



#endif
