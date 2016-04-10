#include"item.h"
#include"World.h"
#include"Inventory.h"
Item::Item(){
	
}
Item::~Item(){
	
}
void World::createitems(){
	items[0].ladder= &room[1];
	items[0].name = "Ladder";
	items[0].descrip = "A ladder that you can use it to pass walls";
	//-------
	items[1].wrench = &room[3];
	items[1].name = "Wrench";
	items[1].descrip = "You can use the wrench to fight if you have problems";
	//-------
	items[2].money = &room[4];
	items[2].name = "Money";
	items[2].descrip = "With this money you can buy somthing";
	//-------
	items[3].ticket = &room[5];
	items[3].name = "Ticket";
	items[3].descrip = "If you have this ticket means that you have some information about house 3";
	//-------
	items[4].ladder = &room[7];
	items[4].name = "Key";
	items[4].descrip = "With this key you can enter to your house!!";
	//-------
	items[5].ladder = &room[2];
	items[5].name = "Map";
	items[5].descrip = "With this special feature if you press you can see the map of the city";
}

