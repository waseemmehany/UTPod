//
// Created by Waseem Mehany on 10/31/18.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


//set and get all instance variables
//overload ==, <,and > operators (used in sorting)
//for < and > use artist, then title, then size

class Song {
private:
    string author;
    string song;
    int size;

public:
    Song();
    //Constructor with parameters
    Song(string author, string song, int size);

    // Author Name
    string getAuthor() const;
    int setAuthor(string newAuthor);

    // Song Name
    string getSong() const;
    int setSong(string newSong);

    // Song Size
    int getSize() const;
    int setSize(int newSize);


//    bool operator== (Song const &obj1, Song const &obj2) {


    ~Song();
};


#endif //UTPOD_SONG_H
