#ifndef _WORLD_
#define _WORLD_
#define _CRT_SECURE_NO_WARNINGS
#include"Entity.h"
#include"Room.h"
#include"Exit.h"
#include"Player.h"
#include"Thug.h"
#include"Vector.h"
#include"item.h"
#include"TalkingNPC.h"
#include"Seller.h"
#define ROOMNUM 9
#define EXITNUM 36
class World{
public:
	int q = 0;
	int maxinventory = 0;
	int maxbox = 0;
	
	Player *player = nullptr;
	Thug *thug = nullptr;
	Item *box = nullptr;
	Item *item=nullptr;
	Person *guy = nullptr;
	Seller *seller = nullptr;
	Vector<Entity*> entities;
	mystring option2;
public:
	World();
	void movement(const Vector<mystring>&);
	void help()const;
	void look(const Vector<mystring>&, int)const;
	void createworld();
	void Open(const Vector<mystring>&);
	void Close(const Vector<mystring>&);
	void inventory()const;

	
	
	
	~World();
};
extern World *world;
#endif
