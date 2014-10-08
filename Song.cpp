#include "Song.h"

// constructor, initializes title, artist, size
Song::Song()
{
   title = "";
   artist = "";
   size = 0;
}

// mutator constructor sets values to title, artist, size
Song::Song(string newTitle, string newArtist, int newSize)
{
   title = newTitle;
   artist = newArtist;
   size = newSize;
}

// getTitle: accessor function to return name (string)
string Song::getTitle()
{
	return title;
}

// getArtist: function accessor to return artist (string)
string Song::getArtist()
{
   return artist;
}
// getSize: function that retrieves size (int)
int Song::getSize()
{
   return size;
}

// setTitle: mutator function to set the title
void Song::setTitle(string newTitle)
{
	title = newTitle;
}

// setArtist: mutator function to set the artist
void Song::setArtist(string newArtist)
{
   artist = newArtist;
}

// setSize: function to set the size
void Song::setSize(int newSize)
{
	size =  newSize;
}

//***********************************************************
// operator>: compares this song to another
//   compares title, artist, size
//***********************************************************
bool Song::operator< (const Song &rhs)
{
		if(title != rhs.title)
			return (title < rhs.title);
		if(artist != rhs.artist)
			return (artist < rhs.artist);
		if(size != rhs.size)
			return (size < rhs.size);
	   return false;
}

//***********************************************************
// operator>: compares this song to another
//   compares title, artist, size
//***********************************************************
bool Song::operator> (const Song &rhs)
{
		if(title != rhs.title)
			return (title > rhs.title);
		if(artist != rhs.artist)
			return (artist > rhs.artist);
		if(size != rhs.size)
			return (size > rhs.size);
	   return false;
}

//***********************************************************
// operator==: compares this song to another
//   songs are equal if all three member variables are equal
//***********************************************************
bool Song::operator== (const Song &right)
{
   if (title != right.title)
      return false;
   if (artist != right.artist)
      return false;
   if (size != right.size)
      return false;
   return true;
}
