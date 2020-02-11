#include "movie.h"

Movie::Movie(const string& title, const string& artist, const int length) : Item(title,artist,length)
{
}

Movie::Movie(void)
{
}

Movie::~Movie(void)
{
}

string Movie::getData() const
{
	string retData = "";
	retData += "-Movie-\n";
	retData += ("director: " + getMaker() + "\n");
	retData += ("# scenes: " + to_string(getLength()) + "\n");
	retData += ("cast:     " + getMembers() + "\n");
	retData += ("title:    " + getTitle() + "\n");
	retData += ("keywords: " + getKeywords());
	return retData;
}
