/**********************************************************************************
Name: Rudy Gonzalez
Date: 4/17/2013
Problem Number: prog6
Instructor: Komogortsev, TSU
***********************************************************************************
This header file provides the prototypes of the function definitions
for the tsuPod project. This file has to be included in the program that
tests the functionality of tsuPod.
***********************************************************************************

Objective:
Implement the storage portion of the tsuPod (pronounced "su Pod" -
the much smaller version of the iPod).

General design:
The code is designed to allow the storage of the following data:
• total songs not to exceed 256MB
• for each song, store the title (string), artist (string), and size (int) in MB
• the title and artist cannot be blank
• the size of each song must be greater than zero

Testing:
• File test_tsuPod.cpp is going to test the functionality of the tsuPod
  program
• Following storage functionalities are tested:
  o Initialization
  o Successful song addition
  o Unsuccessful song addition – failure due to the lack of title
  o Successful song removal
  o Successful song removal
  o Unsuccessful song removal – failure because a song with such name was not found
  o Clearing of the song list
  o Shuffle functionality – implementation and testing of this function
  o Showing remaining memory
  o showing total memory

**********************************************************************************/

/**********************************************************************************
This header file provides the prototypes of the function definitions
for the tsuPod project. This file has to be included in the program that
tests the functionality of tsuPod.
**********************************************************************************/

#include "Song.h"

class tsuPod
{
   private:
     struct SongNode // the Nodes of the linked list
      {
         Song s; // song data
         SongNode *next; // points to next node in list
      };
      SongNode *head; // the head pointer
      int totalMemory, // total memory in tsuPod
          memoryUsed, // memory used by songs
          numberSongs; // number of songs in list
   public:
      tsuPod(int); // constructor
     ~tsuPod(); // deconstructor
      int   addSong(Song), // adds songs to list
            removeSong(Song); // removes song from list
      void  showSongList(), // displays song list contents
            sortSongList(), // sorts song list in ascending order
            shuffle(), // shuffle song list
            clearSongList(); // clears all songs from list
      int  getTotalMemory(), // get total memory of TsuPod
    	   getRemainingMemory(); // get remaining memory left
      Song searchLeast(); // find lowest value song
      bool remove(Song); // removes specific song (used in removeSong())
};
