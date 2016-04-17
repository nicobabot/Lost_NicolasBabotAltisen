#ifndef _ITEM_
#define _ITEM_
#include"Entity.h"
#include"Room.h"
#define NUM_ITEM 7
enum Items{LADDER=0, WRENCH, MONEY, TICKET, KEY, MAP, BOX};
class Item: public Entity{
public:
	Room *itempos=nullptr;
	bool inventory = false;
	bool equipped = false;
	bool inbox = false;


	
public:
	Item(char* name, char* description, Room* position, bool invent, bool equiped, bool inbox);
	//void createitems();
	~Item();


};
#endif