#include "item.h"

Item::Item(const string& title, const string& artist, const int length) : m_title(title), m_maker(artist), m_length(length)
{
}

Item::Item()
{
}

Item::~Item()
{
}


string Item::getTitle()const{return m_title;}
string Item::getMaker()const{return m_maker;}
int Item::getLength()const{return m_length;}

string Item::getKeywords() const
{
	string output = "";
	set<string>::iterator it;
	for(it = m_keywords.begin(); it != m_keywords.end(); it++)
	{
		output += *it;
		output += ", ";
	}
	output.erase(output.length() - 2, 2);//cut off last comma
	return output;
}

string Item::getMembers() const
{
	string output = "";
	set<string>::iterator it;
	for(it = m_members.begin(); it != m_members.end(); it++)
	{
		output += *it;
		output += ", ";
	}
	output.erase(output.length() - 2, 2);//cut off last comma
	return output;
}

string Item::getData() const
{
	string retData = "";
	retData += "-Item-\n";
	retData += ("maker:    " + getMaker() + "\n");
	retData += ("length:   " + to_string(getLength()) + "\n");
	retData += ("members:  " + getMembers() + "\n");
	retData += ("title:    " + getTitle() + "\n");
	retData += ("keywords: " + getKeywords());
	return retData;
}

//----

void Item::addKeyword(const string word)
{
	m_keywords.insert(word);
}

void Item::addMember(string member)
{
	m_members.insert(member);
}

//----

bool operator<(const Item& i1, const Item& i2)
{
    return (i1.getTitle() < i2.getTitle());
}

bool operator<(const ItemPtr& ip1, const ItemPtr& ip2)
{
    return (*(ip1.getPtr()) < *(ip2.getPtr()) );
}

ostream& operator<<(ostream& out, const Item* const item)
{
	out << item->getData() << endl;
	return out;
}
