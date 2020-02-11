#include "item.h"
#include "book.h"
#include "movie.h"
#include "musicalbum.h"
#include <string>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
	cout << endl << "testing base item class" << endl;

	cout << "making item1" << endl;
	Item* item1 = new Item("item1 Title","item1 Maker",1);

	cout << "making item2(album)" << endl;
	Item* item2 = new MusicAlbum("item2 Album Title","item2 Album Maker",2);

	cout << "making item3(movie)" << endl;
	Item* item3 = new Movie("item3 Movie Title","item3 Movie Maker", 3);

	cout << "making item4(book)" << endl;
	Item* item4 = new Book("item4 Book Title","item4 Book Maker",4);

	cout << "item1 title should be 'item1 title': " << item1->getTitle() << endl;
	cout << "item1 maker should be 'item1 maker': " << item1->getMaker() << endl;
	cout << "item1 length should be '1': " << item1->getLength() << endl;

	cout << "adding keywords to item1: ace, base, case" << endl;
	item1->addKeyword("ace");
	item1->addKeyword("base");
	item1->addKeyword("case");

	cout << "printing item1 keywords" << endl;
	cout << item1->getKeywords() << endl;

	cout << "adding keywords to item1: add, bad, cadd" << endl;
	item1->addKeyword("add");
	item1->addKeyword("bad");
	item1->addKeyword("cadd");

	cout << "adding keywords to item2: cat, bat, fat" << endl;
	item2->addKeyword("cat");
	item2->addKeyword("bat");
	item2->addKeyword("fat");

	cout << "adding keywords to item3: car, bar, far" << endl;
	item3->addKeyword("car");
	item3->addKeyword("bar");
	item3->addKeyword("far");

	cout << "adding keywords to item4: but, cut, rut" << endl;
	item4->addKeyword("but");
	item4->addKeyword("cut");
	item4->addKeyword("rut");
	
	cout << "adding members to item1-4: chaz, mike, seth, zack" << endl;
	item1->addMember("chaz");
	item2->addMember("mike");
	item3->addMember("seth");
	item4->addMember("zack");

	cout << "printing item1 keywords" << endl;
	cout << item1->getKeywords() << endl;

	cout << "testing << overload on item1 and item2" << endl;
	cout << item1 << endl;
	cout << item2 << endl;
	
	cout << "testing < overload on item1 and item2" << endl;
	cout << "1 < 2: " << ('1' < '2') << endl;
	cout << "item1 < item2: " << (*(item1) < *(item2)) << endl;

	cout << "making iptr1-4" << endl;
	ItemPtr iptr1(item1);
	ItemPtr iptr2(item2);
	ItemPtr iptr3(item3);
	ItemPtr iptr4(item4);
	
	cout << "testing < overload on iptr1 and iptr2" << endl;
	cout << "iptr1 < iptr2: " << (iptr1 < iptr2) << endl;

	//left to test: item into set, add string->item into map, string->set<Item> into map

	cout << "adding iptr1-4 to set" << endl;
	
	set<ItemPtr> *items = new set<ItemPtr>();
	items->insert(iptr4);
	items->insert(iptr1);
	items->insert(iptr2);
	items->insert(iptr3);

	cout << "printing items in set" << endl;
	set<ItemPtr>::iterator it;
	for(it = items->begin(); it != items->end(); it++)
	{
		cout << (*it).getPtr() << endl;
	}

	cout << "making string to item map and inserting item1-4" << endl;
	map<string, ItemPtr> titleToItem;
	titleToItem.insert( pair<string, ItemPtr>("item4",iptr4));
	titleToItem.insert( pair<string, ItemPtr>("item1",iptr1));
	titleToItem.insert( pair<string, ItemPtr>("item2",iptr2));
	titleToItem.insert( pair<string, ItemPtr>("item3",iptr3));
	
	cout << "print items from map: titleToItem" << endl;
	map<string, ItemPtr>::iterator it2;
	for( it2=titleToItem.begin(); it2 != titleToItem.end(); it2++ )
	{
		cout << (*it2).first << " => " << endl << (*it2).second.getPtr() << endl;
	}

	cout << "making string to itemset multi-map and inserting items" << endl;
	map<string, set<ItemPtr>*> nameToSet;
	nameToSet.insert( pair<string, set<ItemPtr>*>("items", items));

	cout << "printing items from multi-map: nameToSet" << endl;
	map<string, set<ItemPtr>*>::iterator it3;
	for( it3=nameToSet.begin(); it3 != nameToSet.end(); it3++)
	{
		cout << (*it3).first << " => " << endl;
		set<ItemPtr>::iterator it4;
		for( it4=(*it3).second->begin(); it4 != (*it3).second->end(); it4++)
		{
			cout << (*it4).getPtr() << endl;
		}
	}

	cout << "testing get from map: titleToItem, item3" << endl;
	map<string, ItemPtr>::iterator it5 = titleToItem.find("item3");
	cout << (*it5).second.getPtr() << endl;

	cout << "deleing items 1-4" << endl;
	delete item1;
	delete item2;
	delete item3;
	delete item4;
	delete items;
	return 0;
}
