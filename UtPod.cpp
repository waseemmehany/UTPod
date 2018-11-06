//
// Created by Waseem Mehany on 10/31/18.
//

#include "UtPod.h"

using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod() {
    songs = NULL;
    memSize = MAX_MEMORY;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
    songs = NULL;
    if (size > MAX_MEMORY || size <= 0) { memSize = MAX_MEMORY; }
    else { memSize = size; }
}




/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song
*/

int UtPod::addSong(Song const &s) {
    int proposedMemory = getTotalMemory() - s.getSize();

    if (proposedMemory >= 0) {
        SongNode *newNode = new SongNode;
        newNode->next = NULL;
        newNode->s = s;
        newNode->next = songs;
        songs = newNode;

        // memory
        memSize-= s.getSize();

        return 0;
    } else { return -1; }
}




/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -2 if nothing is removed
*/

int UtPod::removeSong(Song const &s) {
    // 1) CHECK IF THERE AND UPDATE MEMORY
    SongNode *foundLoop = songs;
    int found = -1;
    while (foundLoop != NULL) {
        if (foundLoop->s.getAuthor() == s.getAuthor() && foundLoop->s.getSong() == s.getSong() && foundLoop->s.getSize() == s.getSize()) {
            found = 0;
            //update memory
            memSize+= foundLoop->s.getSize();
        }
        foundLoop = foundLoop->next;
    }
    free(foundLoop);
    if (found == -1) { return -2; }

    // 2) FIND POSITION
    int position = findPosition(s);

    // 3) DELETE NODE
    SongNode *temp1 = songs;
    if (position == 1) {
        songs = temp1->next;
        return 0;
    } else {
        for (int i = 0; i < position-2; i++) { temp1 = temp1->next; }
        SongNode *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        return 0;
    }
}

// FIND POSITION OF SONG CONST &S HELPER FUNCTION
int UtPod::findPosition(Song const &s) {
    SongNode *positionFinder = songs;
    int position = 1;
    while (positionFinder != NULL) {
        if (positionFinder->s.getAuthor() == s.getAuthor() && positionFinder->s.getSong() == s.getSong() && positionFinder->s.getSize() == s.getSize())
            return position;
        else
            position++;
        positionFinder = positionFinder->next;
    }
    free(positionFinder);
    cout << "Position: " << position << endl;
    return position;
}




/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list
*/

void UtPod::shuffle() {
    if (songs == NULL) { return; }
    int length = getLength();
    cout << "Length: " << length << endl;

    // Get first half
    SongNode *firstHalf = songs;
    if (length%2 == 0 && length >=2) {
        for (int i = 0; i < length/2 - 1; i++) { firstHalf = firstHalf->next; }
        SongNode *secondHalf = firstHalf->next;
        firstHalf->next = NULL;

        SongNode* tail = NULL;
        while (secondHalf != NULL) {
            if (tail == NULL) {
                tail = secondHalf;
            } else {
                tail->next = secondHalf;
                tail = secondHalf;
            }

            SongNode* next = secondHalf->next;
            secondHalf->next = NULL;
            secondHalf = next;

            SongNode* temp = firstHalf;
            firstHalf = secondHalf;
            secondHalf = firstHalf;
        }



//        cout << "\nFirst Half:" << endl;
//        while (firstHalf != NULL) {
//            cout << firstHalf->s.getSong() << ", ";
//            cout << firstHalf->s.getAuthor() << ", ";
//            cout << firstHalf->s.getSize() << " MB" << endl;
//            firstHalf = firstHalf->next;
//        }
//
//        cout << "\nSecond Half:" << endl;
//        while (secondHalf != NULL) {
//            cout << secondHalf->s.getSong() << ", ";
//            cout << secondHalf->s.getAuthor() << ", ";
//            cout << secondHalf->s.getSize() << " MB" << endl;
//            secondHalf = secondHalf->next;
//            cout << "" << endl;
//        }
//    } else if (length%2 != 0 && length >=2) {
//        for (int i = 0; i < length/2; i++) { secondHalf = secondHalf->next; }
//        SongNode *firstHalf = secondHalf->next;
//        secondHalf->next = NULL;
//
//        for (int i = 0; i < length/2; i++) { firstHalf = firstHalf->next; }
//        SongNode *secondHalf = firstHalf->next;
//        firstHalf->next = NULL;
//
//
//        cout << "\nFirst Half:" << endl;
//        while (firstHalf != NULL) {
//            cout << firstHalf->s.getSong() << ", ";
//            cout << firstHalf->s.getAuthor() << ", ";
//            cout << firstHalf->s.getSize() << " MB" << endl;
//            firstHalf = firstHalf->next;
//        }
//
//        cout << "\nSecond Half:" << endl;
//        while (secondHalf != NULL) {
//            cout << secondHalf->s.getSong() << ", ";
//            cout << secondHalf->s.getAuthor() << ", ";
//            cout << secondHalf->s.getSize() << " MB" << endl;
//            secondHalf = secondHalf->next;
//        }
    }





}




/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)
*/

void UtPod::showSongList() {
    SongNode* current = songs;
    while (current != NULL) {
        cout << current->s.getSong() << ", ";
        cout << current->s.getAuthor() << ", ";
        cout << current->s.getSize() << " MB" << endl;
        current = current->next;
    }
    delete current;
}





/* FUNCTION - void clearMemory
 * clears all the songs from memory
*/
void UtPod::clearMemory() {
//    SongNode* current = songs;
//    SongNode* next;
//
//    while (current != NULL)
//    {
//        next = current->next;
//        free(current);
//        current = next;
//    }
//
//    /* deref head_ref to affect the real head back
//       in the caller. */
//    *head_ref = NULL;
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs
*/

int UtPod::getRemainingMemory() { return memSize; }



int UtPod::getLength() {
    int length = 0;
    SongNode* countList = songs;  // Initialize current
    while (countList != NULL) {
        length++;
        countList = countList->next;
    }
    return length;
}




// DESTRUCTOR
UtPod::~UtPod() {
//    cout << "Destructor" << endl;
}