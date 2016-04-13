#include"item.h"
#include"World.h"

Item::Item(char* name, char* description, Room* position, bool invent, bool equiped) : Entity(name, description)
{
	this->itempos = position;
	this->inventory = invent;
	this->equipped = equiped;
}
Item::~Item(){
	
}