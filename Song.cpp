//
// Created by Waseem Mehany on 10/31/18.
//

#include "Song.h"

using namespace std;

Song::Song() {
    author = "";
    song = "";
    size = 0;
}

Song::Song(string Author, string Song, int Size) {
    author = Author;
    song = Song;
    size = Size;
}

// Get Author Name
string Song::getAuthor() const { return author; }
// Set Author Name.
// Return 0 if successful
int Song::setAuthor(string newAuthor) {
    author = newAuthor;
    return 0;
}


// Get Song Name
string Song::getSong() const { return song; }
// Set Song Name
// Return 0 if successful
int Song::setSong(string newSong) {
    song = newSong;
    return 0;
}


// Get Size
int Song::getSize() const { return size; }
// Set Size
// Return 0 if successful
int Song::setSize(int newSize) {
    size = newSize;
    return 0;
}

// DESTRUCTOR
Song::~Song() {
//    cout << "Destructor" << endl;
}

//bool operator== (Song const &obj1, Song const &obj2) {
//    if (obj1.getAuthor() == obj2.getAuthor() && obj1.getSong() == obj2.getSong() && obj1.getSize() == obj2.getSize()) { return true; }
//    else { return false; }
//}