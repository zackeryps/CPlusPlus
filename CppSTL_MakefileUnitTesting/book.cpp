#include "book.h"

Book::Book(const string& title, const string& artist, const int length) : Item(title,artist,length)
{
}

Book::Book(void)
{
}

Book::~Book(void)
{
}

string Book::getData() const
{
	string retData = "";
	retData += "-Book-\n";
	retData += ("author:   " + getMaker() + "\n");
	retData += ("# pages:  " + to_string(getLength()) + "\n");
	retData += ("title:    " + getTitle() + "\n");
	retData += ("keywords: " + getKeywords());
	return retData;
}
