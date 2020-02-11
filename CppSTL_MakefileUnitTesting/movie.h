#pragma once

#include "item.h"

class Movie :
public Item
{
public:
    Movie(const string& title, const string& artist, const int length);
    Movie(void);
    ~Movie(void);

	string		getData() const;
};

