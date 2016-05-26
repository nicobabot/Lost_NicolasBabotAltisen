#ifndef _THUG_H_
#define _THUG_H_
#include"Room.h"
#include"Creature.h"
#include"Entity.h"
class Thug : public Creature{
public:
	Thug(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, THUG, pos){

	}
	void Thug::Update(){
		//printf("HI\n");
	}
};
#endif