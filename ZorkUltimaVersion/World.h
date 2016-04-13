#ifndef _WORLD_
#define _WORLD_
#define _CRT_SECURE_NO_WARNINGS
#include"Entity.h"
#include"Room.h"
#include"Exit.h"
#include"Player.h"
#include"Vector.h"
#include"item.h"
#define ROOMNUM 9
#define EXITNUM 32
class World{
public:
	
	int quit = 0;
	mystring *direction = nullptr;
	Player *player = nullptr;
	Vector<Room*> room;
	Vector<Exit*> exit;
	Vector<Item*> items;
public:
	World();
	void movement();
	void help()const;
	void look(const mystring*, int);
	void createworld();
	void Open(mystring*);
	void Close(mystring*);
	void pick(mystring*);
	void inventory();
	void drop(mystring*);
	void equip(mystring*);
	void unequip(mystring*);
	~World();
};
#endif
