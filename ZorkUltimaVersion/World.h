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
#define EXITNUM 35
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
	void look(Vector<mystring>&, int);
	void createworld();
	void Open(Vector<mystring>&);
	void Close(Vector<mystring>&);
	void pick(Vector<mystring>&);
	void inventory();
	void drop(Vector<mystring>&);
	void equip(Vector<mystring>& options);
	void unequip(Vector<mystring>& options);
	void update();
	void itemsroom();
	~World();
};
#endif
