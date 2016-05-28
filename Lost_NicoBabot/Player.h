#ifndef _PLAYER_
#define _PLAYER_
#include"Room.h"
#include"Creature.h"
#include"Entity.h"
class Player: public Creature{
public:
	Player(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, PLAYER, pos){

	}
	//Room *playerposit = nullptr;
	Dlist<Entity*> equipedlist;
	void pick(const Vector<mystring>&);
	void drop(const Vector<mystring>&);
	void equip(const Vector<mystring>& options);
	void put(const Vector<mystring>& options);
	void unequip(const Vector<mystring>& options);
	void get(const Vector<mystring>& options);
	void buy(const Vector<mystring>& options);
	int count = 0;
	int money = 0;
	int other = 0;
};
#endif