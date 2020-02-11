#include <cstdarg>		// support macros for vararg
#include <iostream>
#include "library.h"

// private functions
void Library::addItemToSingleMap(Item* item, string key, map<string, ItemPtr> &singleItemMap)
{
	ItemPtr itemptr(item);
	singleItemMap.insert( pair<string, ItemPtr>(key, itemptr));
}

void Library::addItemToMultiMap(Item* item, string key, StringToItemSetMap &multiItemMap)
{
	ItemPtr itemptr(item);
	if ( multiItemMap.find(key) == multiItemMap.end() )//key doesn't exist in map
	{
		ItemSet*	aSet = new ItemSet();
		aSet->insert(itemptr);
		multiItemMap.insert( pair<string, ItemSet*>(key, aSet));
	}
	else//key does exist in map
	{
		multiItemMap.find(key)->second->insert(itemptr);
	}
}

ItemPtr Library::getItemByTitle(const string title)
{
	map<string, ItemPtr>::iterator it = titleToItem.find(title);
	return (*it).second;
}

ItemPtr Library::getBookByTitle(const string title)
{
	map<string, ItemPtr>::iterator it = titleToBook.find(title);
	return (*it).second;
}

ItemPtr Library::getMovieByTitle(const string title)
{
	map<string, ItemPtr>::iterator it = titleToMovie.find(title);
	return (*it).second;
}

ItemPtr Library::getAlbumByTitle(const string title)
{
	map<string, ItemPtr>::iterator it = titleToAlbum.find(title);
	return (*it).second;
}

void Library::delItemSet(ItemSet* itemSet)
{
	for (ItemSet::iterator i = itemSet->begin(); i != itemSet->end(); i++)
	{
		delete i->getPtr();
	}
	delete itemSet;
}

void Library::delMultiMap(StringToItemSetMap multiMap)
{
	for (StringToItemSetMap::iterator i = multiMap.begin(); i != multiMap.end(); i++)
	{
		delete i->second;
	}
}

// general functions

void Library::addKeywordsForItem(const Item* const item, int nKeywords, ...)
{
    // the code in this function demonstrates how to handle a vararg in C++

    va_list		keywords;
    char		*keyword;
	ItemPtr		itemptr = getItemByTitle(item->getTitle());
	

    va_start(keywords, nKeywords);
    for (int i = 0; i < nKeywords; i++) {
	keyword = va_arg(keywords, char*);
	string strword(keyword);
	itemptr.getPtr()->addKeyword(strword);
	addItemToMultiMap(itemptr.getPtr(), strword, keywordToItems);
    }
    va_end(keywords);
}

const ItemSet* Library::itemsForKeyword(const string& keyword) const
{
	ItemSet* retItems = NULL;

	if(keywordToItems.find(keyword) != keywordToItems.end())
	{
		retItems = keywordToItems.find(keyword)->second;
	}

    return retItems;
}

// book-related functions

const Item* Library::addBook(const string& title, const string& author, const int nPages)
{
	Item* iBook = new Book(title, author, nPages);
	ItemPtr iptrBook(iBook);

	if(!m_allBooks)
	{
		m_allBooks = new ItemSet;
	}

	m_allBooks->insert(iptrBook);
	addItemToSingleMap(iBook, title, titleToBook);
	addItemToSingleMap(iBook, title, titleToItem);
	addItemToMultiMap(iBook, author, authorToBooks);

    return iBook;
}

const ItemSet* Library::booksByAuthor(const string& author) const
{
	ItemSet* retItems = NULL;

	if(authorToBooks.find(author) != authorToBooks.end())
	{
		retItems = authorToBooks.find(author)->second;
	}

    return retItems;
}

const ItemSet* Library::books() const
{
    return m_allBooks;
}

// music-related functions

const Item* Library::addMusicAlbum(const string& title, const string& band, const int nSongs)
{
	Item* iAlbum = new MusicAlbum(title, band, nSongs);
	ItemPtr iptrAlbum(iAlbum);

	if(!m_allAlbums)
	{
		m_allAlbums = new ItemSet;
	}

	m_allAlbums->insert(iptrAlbum);
	addItemToSingleMap(iAlbum, title, titleToAlbum);
	addItemToSingleMap(iAlbum, title, titleToItem);
	addItemToMultiMap(iAlbum, band, bandToAlbums);

    return iAlbum;
}

void Library::addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...)
{
    va_list		members;
    char		*member;
	ItemPtr         itemptr = getAlbumByTitle(musicAlbum->getTitle());

    va_start(members, nBandMembers);
    for (int i = 0; i < nBandMembers; i++) {
	member = va_arg(members, char*);
	string strword(member);
	itemptr.getPtr()->addMember(strword);
	addItemToMultiMap(itemptr.getPtr(), strword, memberToAlbums);
    }
    va_end(members);
}

const ItemSet* Library::musicByBand(const string& band) const
{
	ItemSet* retItems = NULL;

	if(bandToAlbums.find(band) != bandToAlbums.end())
	{
		retItems = bandToAlbums.find(band)->second;
	}

    return retItems;
}

const ItemSet* Library::musicByMusician(const string& musician) const
{
	ItemSet* retItems = NULL;

	if(memberToAlbums.find(musician) != memberToAlbums.end())
	{
		retItems = memberToAlbums.find(musician)->second;
	}

    return retItems;
}

const ItemSet* Library::musicAlbums() const
{
    return m_allAlbums;
}

// movie-related functions

const Item* Library::addMovie(const string& title, const string& director, const int nScenes)
{
	Item* iMovie = new Movie(title, director, nScenes);
	ItemPtr iptrMovie(iMovie);

	if(!m_allMovies)
	{
		m_allMovies = new ItemSet;
	}

	m_allMovies->insert(iptrMovie);
	addItemToSingleMap(iMovie, title, titleToMovie);
	addItemToSingleMap(iMovie, title, titleToItem);
	addItemToMultiMap(iMovie, director, directorToMovies);

    return iMovie;
}

void Library::addCastMembers(const Item* const movie, const int nCastMembers, ...)
{
    va_list             members;
    char                *member;
	ItemPtr         itemptr = getMovieByTitle(movie->getTitle());


   va_start(members, nCastMembers);
   for (int i = 0; i < nCastMembers; i++) {
	member = va_arg(members, char*);
	string strword(member);
	itemptr.getPtr()->addMember(strword);
	addItemToMultiMap(itemptr.getPtr(), strword, memberToMovies);
   }
   va_end(members);
}

const ItemSet* Library::moviesByDirector(const string& director) const
{
	ItemSet* retItems = NULL;

	if(directorToMovies.find(director) != directorToMovies.end())
	{
		retItems = directorToMovies.find(director)->second;
	}

    return retItems;
}

const ItemSet* Library::moviesByActor(const string& actor) const
{
	ItemSet* retItems = NULL;

	if(memberToMovies.find(actor) != memberToMovies.end())
	{
		retItems = memberToMovies.find(actor)->second;
	}

    return retItems;
}

const ItemSet* Library::movies() const
{
    return m_allMovies;
}

static void deleteMapContents(StringToItemSetMap& s2ism)
{
    // your code here
}

static void deleteItemSetContents(ItemSet& itemSet)
{
    // your code here
}

Library::Library()
{
	m_allBooks = NULL;
	m_allMovies = NULL;
	m_allAlbums = NULL;
}

Library::~Library()
{
	//delete all item pointers from the master lists
	if(m_allBooks)
	{
		delItemSet(m_allBooks);
	}
	if(m_allMovies)
	{
		delItemSet(m_allMovies);
	}
	if(m_allAlbums)
	{
		delItemSet(m_allAlbums);
	}
	//delete additional lists
	if(!keywordToItems.empty())
	{
		delMultiMap(keywordToItems);
	}
	if(!authorToBooks.empty())
	{
		delMultiMap(authorToBooks);
	}
	if(!memberToMovies.empty())
	{
		delMultiMap(memberToMovies);
	}
	if(!directorToMovies.empty())
	{
		delMultiMap(directorToMovies);
	}
	if(!memberToAlbums.empty())
	{
		delMultiMap(memberToAlbums);
	}
	if(!bandToAlbums.empty())
	{
		delMultiMap(bandToAlbums);
	}
}
