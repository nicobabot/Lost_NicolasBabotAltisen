#ifndef _CREATURE_H_
#define  _CREATURE_H_
#include"Entity.h"
#include"Room.h"
class Creature : public Entity{
public:
	int health, damage, accuracy;
	Room* position;
	TYPE typeof;

public:
	Creature::Creature(const char* name, const char* description, const int health, const int damage, const int accuracy, TYPE entitytype, Room* position) : Entity(name, description, entitytype), health(health), damage(damage), accuracy(accuracy), typeof(typeof), position(position){

	}
	/*Creature::Update(){
		return 0;
	}*/

};
#endif