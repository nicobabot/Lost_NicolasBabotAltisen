#ifndef _THUG_H_
#define _THUG_H_
#include"Room.h"
#include"Creature.h"
#include"Entity.h"
#include<time.h>
class Thug : public Creature{
public:
	Thug(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, THUG, pos){

	}
	void Update(){
		int i = (rand() % 3) + 4;
		world->thug->position = (Room*)world->entities[i];
		if (world->player->position == world->thug->position){
			printf("HI I AM A THUG");
		}
		//printf("HI\n");
	}
};
#endif