#ifndef _PLAYER_
#define _PLAYER_
#include"Room.h"
#include"Entity.h"
class Player: public Entity{
public:
	Player(const char* name, const char* descrip, TYPE, Room*);
	Room *playerposit = nullptr;
	void pick(Vector<mystring>&);
	void inventory();
	void drop(Vector<mystring>&);
	void equip(const Vector<mystring>& options);
	void put(const Vector<mystring>& options);
	void unequip(Vector<mystring>& options);
	void get(Vector<mystring>& options);


};
#endif