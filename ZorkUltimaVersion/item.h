#ifndef _ITEM_
#define _ITEM_
#include"Entity.h"
#include"Room.h"
class Item: public Entity{
public:
	Room *ladder;
	Room *wrench;
	Room *money;
	Room *ticket;
	Room *key;
	Room *map;
public:
	Item();
	//void createitems();
	~Item();


};
#endif