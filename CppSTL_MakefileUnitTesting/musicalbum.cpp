#include "musicalbum.h"

MusicAlbum::MusicAlbum(const string& title, const string& artist, const int length) : Item(title,artist,length)
{
}

MusicAlbum::MusicAlbum(void)
{
}

MusicAlbum::~MusicAlbum(void)
{
}

string MusicAlbum::getData() const
{
	string retData = "";
	retData += "-Music Album-\n";
	retData += ("band:     " + getMaker() + "\n");
	retData += ("# songs:  " + to_string(getLength()) + "\n");
	retData += ("members:  " + getMembers() + "\n");
	retData += ("title:    " + getTitle() + "\n");
	retData += ("keywords: " + getKeywords());
	return retData;
}
