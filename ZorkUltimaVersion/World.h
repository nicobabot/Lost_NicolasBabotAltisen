#ifndef _WORLD_
#define _WORLD_
#define _CRT_SECURE_NO_WARNINGS
#include"Room.h"
#include"Exit.h"
#include"Player.h"
class World{
public:
	int quit = 0;
	Player *player = nullptr;
	Room *room = nullptr;
	Exit *exit = nullptr;
public:
	World();
	void movement();
	void help()const;
	void look(const char*, const int)const;
	void createworld()const;
	~World();
};
#endif