#pragma once

#include <ostream>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Item
{
private:
	string			m_title;
	string			m_maker;
	int			    m_length;
	set<string>		m_keywords;
	set<string>		m_members;

public:
    Item(const string& title, const string& artist, const int length);
    Item();
    virtual ~Item();

	string 		    getTitle() const;
	string	 	    getMaker() const;
	int	 	        getLength() const;
	string		    getKeywords() const;
	string		    getMembers() const;
	virtual string	getData() const;
	void		    addKeyword(const string word);
	void		    addMember(string member);
};

// You can't store Item* in an ItemSet, because that would disable the automatic
// sorting that set does. Containers in the C++ STL are designed to store
// INSTANCES, not POINTERS to instances.
//
// Instead we store instances of ItemPtr in the ItemSet defined in Library.h.
// Each instance of ItemPtr contains a pointer to an instance of Item. In this way,
// the container can call operator< for ItemPtr (which can then call operator<
// for Item) to determine the order in which to store the items it's given.
//
// When you add a Book instance to an ItemSet, you can do things like this:
//
//		ItemSet		books;					// defined in Library.h
//		Item		*book = new Book(...);
//
//		books.insert(book);
//
// The STL's set class will internally generate an instance of ItemPtr
// which will contain the pointer to the instance of Book.

class ItemPtr
{
private:
    Item	*ptr;

public:
ItemPtr(Item *ptr) : ptr(ptr) { }
    Item* getPtr() const { return ptr; }
};

// compare two instances of Item
bool operator<(const Item& i1, const Item& i2);

// compare two instances of ItemPtr
bool operator<(const ItemPtr& ip1, const ItemPtr& ip2);

// item out stream operator<< overload
ostream& operator<<(ostream& out, const Item* const item);
