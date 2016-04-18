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
#define EXITNUM 36
class World{
public:
	int q = 0;
	int maxinventory = 0;
	int maxbox = 0;
	int maxequiped=0;
	Player *player = nullptr;
	Vector<Room*> room;
	Vector<Exit*> exit;
	Vector<Item*> items;
public:
	World();
	void movement();
	void help()const;
	void look(const Vector<mystring>&, int)const;
	void createworld();
	void Open(const Vector<mystring>&);
	void Close(const Vector<mystring>&);
	void pick(Vector<mystring>&);
	void inventory();
	void drop(Vector<mystring>&);
	void equip(const Vector<mystring>& options);
	void unequip(Vector<mystring>& options);
	void update();
	void itemsroom();
	void put(const Vector<mystring>& options);
	void get(Vector<mystring>& options);
	void map()const;
	~World();
};
#endif