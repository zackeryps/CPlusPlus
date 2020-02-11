// do not remove any of the function prototypes from this class definition

#pragma once

#include <map>
#include <set>
#include <string>
#include "item.h"
#include "book.h"
#include "movie.h"
#include "musicalbum.h"

using namespace std;

// C++ Standard Library definitions for containers you may need
typedef set<string>	StringSet;
typedef set<ItemPtr>	ItemSet;		// see comment in Item.h about use of ItemPtr
typedef map<string,ItemSet*>	StringToItemSetMap;

class Library
{
private:
	StringToItemSetMap	keywordToItems;
	map<string, ItemPtr>	titleToItem;
	ItemSet*		m_allBooks; //master list
	map<string, ItemPtr>	titleToBook;
	StringToItemSetMap	authorToBooks;
	ItemSet*		m_allMovies; //master list
	map<string, ItemPtr>	titleToMovie;
	StringToItemSetMap	memberToMovies;
	StringToItemSetMap	directorToMovies;
	ItemSet*		m_allAlbums; //master list;
	map<string, ItemPtr>	titleToAlbum;
	StringToItemSetMap	memberToAlbums;
	StringToItemSetMap	bandToAlbums;

	void addItemToSingleMap(Item* item, string key, map<string, ItemPtr> &singleItemMap);
	void addItemToMultiMap(Item* item, string key, StringToItemSetMap &multiItemMap);
	ItemPtr getItemByTitle(const string title);
	ItemPtr getBookByTitle(const string title);
	ItemPtr getMovieByTitle(const string title);
	ItemPtr getAlbumByTitle(const string title);
	void delItemSet(ItemSet* itemSet);
	void delMultiMap(StringToItemSetMap multiMap);

public:
    // general functions
    void addKeywordsForItem(const Item* const item, int nKeywords, ...);
    const ItemSet* itemsForKeyword(const string& keyword) const;

    // book-related functions
    const Item* addBook(const string& title, const string& author, const int nPages);
    const ItemSet* booksByAuthor(const string& author) const;
    const ItemSet* books() const;			// returns set containing all the books

    // music-related functions
    const Item* addMusicAlbum(const string& title, const string& band, const int nSongs);
    void addBandMembers(const Item* const musicCD, int nBandMembers, ...);
    const ItemSet* musicByBand(const string& band) const;
    const ItemSet* musicByMusician(const string& musician) const;
    const ItemSet* musicAlbums() const;		// returns set containing all the music

    // movie-related functions
    const Item* addMovie(const string& title, const string& director, const int nScenes);
    void addCastMembers(const Item* const movie, const int nCastMembers, ...);
    const ItemSet* moviesByDirector(const string& director) const;
    const ItemSet* moviesByActor(const string& actor) const;
    const ItemSet* movies() const;			// returns set containing all the movies

	Library();
    virtual ~Library();
};

