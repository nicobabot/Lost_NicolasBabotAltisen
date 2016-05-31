#ifndef _TALKNPC_H_
#define _TALKNPC_H_
#include<time.h>
class Room;
class Entity;
class Creature;
enum Statetalking{IDLE, TALKING, FINISH};
class Person : public Creature{
public:
	Statetalking state;
	Person(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, PERSON, pos){

	}
	void Update();
	void idle();
	void talking();
};
#endif