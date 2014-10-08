#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

#include "tsuPod.h"

int main()
{

	tsuPod Tpod(256); // initialize Tpod with max 256 MB memory

	Song s0("title0", "title0", 1); // song add successful
	int retCode = Tpod.addSong(s0);
	//cout << "retCode = " << retCode << endl;

	Song s1("title3", "title3", 2); // song add successful
	retCode = Tpod.addSong(s1);
	//cout << "retCode = " << retCode << endl;

	Song s2("title2", "title2", 3); // song add successful
	retCode = Tpod.addSong(s2);
	//cout << "retCode = " << retCode << endl;

	Song s4("title1", "title1", 4); // song add successful
	retCode = Tpod.addSong(s4);
	cout << "add retCode = " << retCode << endl;

	Song s3("", "title5", 5); // add song with blank title unsuccessful
	retCode = Tpod.addSong(s3);
	cout << "add retCode = " << retCode << endl;

	cout << "\nshowSongList(): \n";
	Tpod.showSongList();

	retCode = Tpod.removeSong(s2); // remove song2 successfully
	cout << "\nremove retCode = " << retCode << endl;

	retCode = Tpod.removeSong(s3); // remove song3 unsuccessfully
	cout << "remove retCode = " << retCode << endl;

	cout << "\nshowSongList() after deletion:\n";
	Tpod.showSongList(); // shows list after deletion.

    cout << "\nsortedList():\n";
	Tpod.sortSongList(); // sorts song list
	Tpod.showSongList(); // shows song list

	cout << "\nshuffle()\n";
	Tpod.shuffle(); // shuffles song list
	Tpod.showSongList(); // shows song list

	//show total memory and remaining memory
	cout << endl << Tpod.getRemainingMemory() << "MB available out of "
			<< Tpod.getTotalMemory() << "MB.\n";

	Tpod.clearSongList(); // clear song list

	// show total memory and remaining memory after song list cleared
	cout << endl << Tpod.getRemainingMemory() << "MB available out of "
			<< Tpod.getTotalMemory() << "MB.";

	Tpod.~tsuPod(); // Tpod deconstructor
	return EXIT_SUCCESS;
}

