#pragma once

#include "item.h"

class MusicAlbum :
public Item
{
public:
    MusicAlbum(const string& title, const string& artist, const int length);
    MusicAlbum(void);
    ~MusicAlbum(void);

	string		getData() const;
};

