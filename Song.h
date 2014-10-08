#include <string>
using namespace std;

class Song
{
   private:
      string  title, // title of song
      	  	  artist; // artist of the Song
      int     size; // size of song

    public:
      Song(); // constructor
      Song(string, string, int); // mutator constructor
      ~Song(){}; // destructor
      string getTitle(), // retrieves title of song
    		 getArtist(); // retrieves artist of song
      int    getSize(); // retrieves size of song

      void setTitle(string); // sets title of song
      void setArtist(string); // sets artist of song
      void setSize(int); // sets size of song

      bool operator < (const Song &); // comparison operator
      bool operator > (const Song &); // comparison operator
      bool operator == (const Song &); // comparison operator
};
