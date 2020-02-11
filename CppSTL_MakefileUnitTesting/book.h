#pragma once

#include "item.h"

class Book :
public Item
{
public:
    Book(const string& title, const string& artist, const int length);
    Book(void);
    ~Book(void);
	
	string	 	getData() const;
};

