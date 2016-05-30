#ifndef _THUG_H_
#define _THUG_H_
#include<time.h>
class Room;
class Entity;
class Creature;
enum StateThug{ MOVING, ASKING, FIGHT, DEAD, DISAPPEAR };
class Thug : public Creature{
public:
	StateThug state;
	Thug(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, THUG, pos){

	}
	void Update();
	void movementenemy();
	void ask();
	void fight();
	void enemydead();
};
#endif