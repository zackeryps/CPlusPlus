#include <iostream>
#include "library.h"

using namespace std;

static Library *library;

static void printItemSet(ostream& out, const ItemSet* aSet);

int main()
{
	ostream&	out(cout);
	const Item	*item;	

	cout << "making library" << endl;
	library = new Library();

	cout << "adding book1 to library" << endl;
	item = library->addBook("book1", "author", 1);
	cout << "adding keywords to book1" << endl;
	library->addKeywordsForItem(item, 3, "one", "won", "1");

	cout << "book1:" << endl;
	cout << item << endl;

	cout << "adding book2 to library" << endl;
	item = library->addBook("book2", "author", 2);
	cout << "adding keywords to book2" << endl;
	library->addKeywordsForItem(item, 5, "one", "two", "to", "too", "2");

	cout << "book2:" << endl;
	cout << item << endl;

	cout << "adding book3 to library" << endl;
	item = library->addBook("book3", "author3", 3);
	cout << "adding keywords to book3" << endl;
	library->addKeywordsForItem(item, 2, "three", "3");

	cout << "book3:" << endl;
	cout << item << endl;

	cout << "adding book4 to library" << endl;
	item = library->addBook("book4", "author4", 4);
	cout << "adding keywords to book4" << endl;
	library->addKeywordsForItem(item, 3, "for", "four", "4");

	cout << "book4:" << endl;
	cout << item << endl;

	cout << "adding movie1 to library" << endl;
	item = library->addMovie("movie1", "dir1", 1);
	cout << "adding keywords to movie1" << endl;
	library->addKeywordsForItem(item, 3, "one", "won", "1");
	cout << "adding cast members to movie1"<< endl;
	library->addCastMembers(item, 4, "zack", "seth", "mike", "chaz");

	cout << "movie1:" << endl;
	cout << item << endl;

	cout << "adding movie2 to library" << endl;
	item = library->addMovie("movie2", "dir", 2);
	cout << "adding keywords to movie2" << endl;
	library->addKeywordsForItem(item, 4, "to", "too", "2", "two");
	cout << "adding cast members to movie2"<< endl;
	library->addCastMembers(item, 3, "zack", "seth", "mike");

	cout << "movie2:" << endl;
	cout << item << endl;

	cout << "adding movie3 to library" << endl;
	item = library->addMovie("movie3", "dir", 3);
	cout << "adding keywords to movie3" << endl;
	library->addKeywordsForItem(item, 2, "three", "3");
	cout << "adding cast members to movie3"<< endl;
	library->addCastMembers(item, 3, "zack", "seth", "chaz");

	cout << "movie3:" << endl;
	cout << item << endl;

	cout << "adding movie4 to library" << endl;
	item = library->addMovie("movie4", "dir4", 4);
	cout << "adding keywords to movie4" << endl;
	library->addKeywordsForItem(item, 3, "four", "for", "4");
	cout << "adding cast members to movie4"<< endl;
	library->addCastMembers(item, 3, "zack", "mike", "chaz");

	cout << "movie4:" << endl;
	cout << item << endl;

	cout << "adding album1 to library" << endl;
	item = library->addMusicAlbum("album1", "band1", 1);
	cout << "adding keywords to album1" << endl;
	library->addKeywordsForItem(item, 3, "one", "won", "1");
	cout << "adding band members to album1"<< endl;
	library->addBandMembers(item, 3, "zack", "mike", "chaz");

	cout << "album1:" << endl;
	cout << item << endl;

	cout << "adding album2 to library" << endl;
	item = library->addMusicAlbum("album2", "band2", 2);
	cout << "adding keywords to album2" << endl;
	library->addKeywordsForItem(item, 4, "two", "to", "too", "2");
	cout << "adding band members to album2"<< endl;
	library->addBandMembers(item, 2, "zack", "mike");

	cout << "album2:" << endl;
	cout << item << endl;

	cout << "adding album3 to library" << endl;
	item = library->addMusicAlbum("album3", "band", 3);
	cout << "adding keywords to album3" << endl;
	library->addKeywordsForItem(item, 2, "three", "3");
	cout << "adding band members to album1"<< endl;
	library->addBandMembers(item, 2, "zack", "chaz");

	cout << "album3:" << endl;
	cout << item << endl;

	cout << "adding album4 to library" << endl;
	item = library->addMusicAlbum("album4", "band", 4);
	cout << "adding keywords to album4" << endl;
	library->addKeywordsForItem(item, 3, "four", "for", "4");
	cout << "adding band members to album4"<< endl;
	library->addBandMembers(item, 2, "mike", "chaz");

	cout << "album4:" << endl;
	cout << item << endl;


	cout << endl << "printing all books" << endl;
	printItemSet(out, library->books());
	
	cout << endl << "printing items for keyword 'one': " << endl;
	printItemSet(out, library->itemsForKeyword("one"));

	cout << endl << "printing items for author 'author': " << endl;
	printItemSet(out, library->booksByAuthor("author"));

	cout << endl << "printing all movies:" << endl;
	printItemSet(out, library->movies());

	cout << endl << "printing movies with cast member 'mike': " << endl;
	printItemSet(out, library->moviesByActor("mike"));

	cout << endl << "printing movies with director 'dir': " << endl;
	printItemSet(out, library->moviesByDirector("dir"));

	cout << endl << "printing all albums" << endl;
	printItemSet(out, library->musicAlbums());
	
	cout << endl << "printing albums with band member 'mike':" << endl;
	printItemSet(out, library->musicByMusician("mike"));

	cout << endl << "printing albums with band 'band':" << endl;
	printItemSet(out, library->musicByBand("band"));

	delete library;
	return 0;
}

static void printItemSet(ostream& out, const ItemSet* itemSet)
{
	cout << "printing set" << endl;
	if (itemSet != NULL && itemSet->size() > 0)
		for (ItemSet::const_iterator i = itemSet->begin(); i != itemSet->end(); i++)
			out << i->getPtr();
	else
		out << "none" << endl << endl;
}
