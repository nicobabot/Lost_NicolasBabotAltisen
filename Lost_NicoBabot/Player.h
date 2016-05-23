#ifndef _PLAYER_
#define _PLAYER_
#include"Room.h"
#include"Entity.h"
class Player: public Entity{
public:
	Player(const char* name, const char* descrip, TYPE, Room*);
	Room *playerposit = nullptr;
	void pick(const Vector<mystring>&);
	void inventory();
	void drop(const Vector<mystring>&);
	void equip(const Vector<mystring>& options);
	void put(const Vector<mystring>& options);
	void unequip(const Vector<mystring>& options);
	void get(const Vector<mystring>& options);


};
#endif