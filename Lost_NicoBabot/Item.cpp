#include"item.h"
#include"World.h"

Item::Item(char* name, char* description, Room* position, bool invent, bool equiped, bool inbox, TYPE type) : Entity(name, description, type)
{
	this->itempos = position;
	this->inventory = invent;
	this->equipped = equiped;
	this->inbox = inbox;
}
Item::~Item(){
	
}