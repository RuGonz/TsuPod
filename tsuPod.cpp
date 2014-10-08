#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "tsuPod.h"

/**********************************************************************************
 * Function Definitions
**********************************************************************************/
// Constructor for tsuPod
tsuPod::tsuPod(int memorySpace)
{
	totalMemory = memorySpace;
	head = NULL;
	memoryUsed = 0;
	numberSongs = 0;
}

// Deconstructor for tsuPod
tsuPod::~tsuPod(){}

/****************************************************************************************
 * Functions Definitions
****************************************************************************************/

/* FUNCTION - int addSong
  *attempts to add a new song to the tsuPod
          o returns a 0 if successful
          o returns -1 if not enough memory to add the song
          o returns -2 for any other error (such as a blank title or artist)
 input parms - s object
 output parms - 0 (int), -1(int), or -2(int)
*/
int tsuPod::addSong(Song song)
{
	//return -2 if no title, no artist, and size less than 0
	if(song.getTitle() == "" || song.getArtist() == "" || song.getSize() < 1)
		return -2; // return unsuccessful
	// return -1 if no memory is available
	else if(song.getSize() > getRemainingMemory())
		return -1; // return unsuccessful
	//return 0 if song was added successfully
	else
	{
		numberSongs++;
		memoryUsed += song.getSize();
		SongNode *newNode;  // To point to a new node
		SongNode *nodePtr;  // To move through the list

		// Allocate a new node and store song
		newNode = new SongNode;
		newNode->s = song;
		newNode->next = NULL;

		// If empty, make newNode the first node
		if (!head)
			head = newNode;
		else
		{
			// make nodePtr to head of list
			nodePtr = head;
			// traverse list to find last node
			while (nodePtr->next)
				nodePtr = nodePtr->next;

			// make last node point to newNode
			nodePtr->next = newNode;
		}
		return 0; // return successful
	}
}

/* FUNCTION - int removeSong
   * attempts to remove a song from the tsuPod
          o returns 0 if successful
          o returns -1 if nothing is removed
 input parms - s object
 output parms - 0(int) or -1(int)
*/
int tsuPod::removeSong(Song song)
{
	bool found; // true if removeOne did remove one
	// keep trying to remove one, until there are no more
	found = remove(song);
	while (found) // if song found, remove
	{
		found = remove(song);
		numberSongs--; // subtract song from number of songs
		memoryUsed -= song.getSize(); // decrease memory used
		return 0; // return successful
	}
	return -1; // return unsuccessful
}

/* FUNCTION - bool removeSong
   * attempts to remove a song from the tsuPod
          o returns 0 if successful
          o returns -1 if nothing is removed
 input parms - s object
 output parms - true(bool or false (bool)
*/
bool tsuPod::remove(Song song)
{
	SongNode *nodePtr = head;   // to traverse the list of songs
	SongNode *previousNode = NULL;   // node before nodePtr
	while (nodePtr) // traverse list if songs
	{
		if (nodePtr->s == song) // if song matchs is found, delete song
		{
			if (previousNode == NULL) // if node reaches end of list
				head = nodePtr->next;
			else
				previousNode->next = nodePtr->next;

			delete nodePtr; // deletes song
			return true; // returns successful
		}
		previousNode = nodePtr; //else: advance both pointers
		nodePtr = nodePtr->next;
	}
	return false; // returns unsuccessful
}

/* FUNCTION - void showSongList
  *displays current list of songs
 input parms - none
 output parms - prints song list to console.
*/
void tsuPod::showSongList()
{
	SongNode *nodePtr; // pointer used to traverse the list
	nodePtr = head; // sets node to beginning of list

	while (nodePtr) // traverses through all elements in the list.
	{
		// displays list contents
		cout << "Title: " << nodePtr->s.getTitle()
		    		 << "    Artist: " << nodePtr->s.getArtist()
		    		 << "    Size: " << nodePtr->s.getSize() << endl;
		//moves to next song
		nodePtr = nodePtr->next;
	}
}

/* FUNCTION - void sortSongList
  *sorts list according to title, artist, and size
 input parms - none
 output parms - none
*/
void tsuPod::sortSongList()
{
	SongNode *buff; // buff initialized
	buff = NULL; // set to NULL
	SongNode *pointer;  // pointer to traverse song list

	while(head) //Loop is executed as long as there are movies in movieList
	{
		// Allocate a new node for song.
		SongNode *newNode; // create node
		newNode = new SongNode; // create new songNode
		newNode->s = searchLeast(); // newNode equal to lowest value vound
		newNode->next = NULL;

		// Remove lowest song found
		remove(searchLeast());

		// If empty, make newNode first node.
		if (!buff)
			buff = newNode;
		else
		{
			// make pointer to head of buff list.
			pointer = buff;

			// traverse list to find last node in buff.
			while(pointer->next)
				pointer = pointer->next;
			// makes last node point to newNode
			pointer->next = newNode;
		}
	}
	//makes old head point to new head.
	head = buff;
}

/* FUNCTION - Song lowest()
  *traverses list to find lowest alphabetical value
 input parms - none
 output parms - none
*/
Song tsuPod::searchLeast()
{
	SongNode *nodePtr; // to traverse list of songs.
	nodePtr = head;
	Song temp = nodePtr->s; // initializes temp and sets
	// values of song to temp
	nodePtr = nodePtr->next; //points node to next song in list.

	while(nodePtr) // while node available to traverse.
	{
		if(nodePtr->s < temp) //comparison of song values.
			temp = nodePtr->s; // set temp song to value of node
		nodePtr = nodePtr->next; // node set values of next song
	}
	return temp; // return lowest valued song
}

/* FUNCTION - int getTotalMemory
  *Retrieves current memory of tsuPod
 input parms - none
 output parms - returns totalMemory(int)
*/
int tsuPod::getTotalMemory()
{
	return totalMemory;
}

/* FUNCTION - void clearSongList
 	 *clears all the songs from memory
    input parms - none
    output parms - none
*/
void tsuPod::clearSongList()
{
	SongNode *temp;
	temp  = head; // temp set to beginning
	while(temp != NULL) // while temp has not reached end
	{
		head->next = temp->next;
		temp->next = NULL;
		delete temp; // deletes temp songNode
		temp = head->next;
	}
	head = NULL; // no songs in list
	numberSongs = 0; // resets song counter to 0
	memoryUsed = 0; // resets memory used to 0
	cout << "\nSong list cleared.\n";
}

/* FUNCTION - int remainingMemory
  *Retrieves unused memory
 input parms - none
 output parms - returns remainingMemory(int)
*/
int tsuPod::getRemainingMemory()
{
	return (getTotalMemory() - memoryUsed);
}

/* FUNCTION - void shuffle
  *shuffles the songs into random order
 o will do nothing if there are less than two songs in the current list
 input parms - none
 output parms - none void
*/
void tsuPod::shuffle ()
{
	srand(time(NULL));
	int randomNum; // stores random number
	SongNode *prevSong, *swapSong, *pointer1, *pointer2; // pointers to travel
	//the list
	Song buffer; // buffer to store song temporarily
	int newNumber = numberSongs;

	pointer1 = head; // sets pointer 1 to beginning of song list

	for(int a = 0; a < newNumber; a++)
	{
		// traverse to newNumber position in song list
		pointer2 = head;// start at beginning
		prevSong = pointer1;
		randomNum = (rand() % newNumber) + 1; // generates random number
		// but not 0

		for(int k = 1; k <= randomNum; k++)
		{
			if(k == randomNum) // when k matches random number do not switch
				swapSong = pointer2; // set swapSong equal to pointer2
			pointer2 = pointer2->next; // traverse to next song
		}
		//swapping of songs
		buffer = prevSong->s; // prevSong stored in buffer
		prevSong->s = swapSong->s; // previous song now holds song in switchsong
		swapSong->s = buffer; // switchsong holds song in prevSong
		pointer1 = pointer1->next; // go to next song in the list
	}
}
