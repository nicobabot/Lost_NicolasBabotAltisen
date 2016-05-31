#ifndef _SELLER_H_
#define _SELLER_H_
#include<time.h>
class Room;
class Entity;
class Creature;
class Seller : public Creature{
public:
	Seller(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, SELLER, pos){

	}

};
#endif