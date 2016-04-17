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
	int maxinventory = 0;
	int maxequipped = 0;
	int maxitembox = 0;
	int q = 0;
	Player *player = nullptr;
	Vector<Room*> room;
	Vector<Exit*> exit;
	Vector<Item*> items;
public:
	World();
	void movement();
	void help()const;
	void look(Vector<mystring>&, int)const;
	void createworld();
	void Open(Vector<mystring>&)const;
	void Close(Vector<mystring>&)const;
	void pick(Vector<mystring>&);
	void inventory()const;
	void drop(Vector<mystring>&)const;
	void equip(Vector<mystring>& options)const;
	void unequip(Vector<mystring>& options)const;
	void update()const;
	void itemsroom()const;
	void put(Vector<mystring>& options)const;
	void get(Vector<mystring>& options)const;
	void map()const;
	~World();
};
#endif
