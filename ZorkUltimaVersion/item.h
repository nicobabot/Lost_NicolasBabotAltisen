#ifndef _ITEM_
#define _ITEM_
#include"Entity.h"
#include"Room.h"
#define NUM_ITEM 6
enum Items{LADDER=0, WRENCH, MONEY, TICKET, KEY, MAP};
class Item: public Entity{
public:
	Room *itempos=nullptr;
	bool inventory = false;
	bool equipped = false;
	int maxequiped=3;
	int maximum = 0;
public:
	Item();
	//void createitems();
	~Item();


};
#endif