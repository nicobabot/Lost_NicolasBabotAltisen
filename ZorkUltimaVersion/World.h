#ifndef _WORLD_
#define _WORLD_
#define _CRT_SECURE_NO_WARNINGS
#include"Entity.h"
#include"Room.h"
#include"Exit.h"
#include"Player.h"
#define ROOMNUM 9
#define EXITNUM 38
class World{
public:
	int quit = 0;
	Player *player = nullptr;
	Room *room = nullptr;
	Exit *exit = nullptr;
	mystring *direction = nullptr;
public:
	World();
	void movement();
	void help()const;
	void look(const mystring*, int)const;
	void createworld()const;
	void Open(mystring*);
	void Close(mystring*);
	~World();
};
#endif