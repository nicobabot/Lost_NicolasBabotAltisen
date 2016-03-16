#ifndef _WORLD_
#define _WORLD_
#define _CRT_SECURE_NO_WARNINGS
#include"Room.h"
#include"Exit.h"
#include"Player.h"
//enum command{ NORTH, WEST, SOUTH, EAST, QUIT, GO, TAKE, LOOK, OPEN, CLOSE, HELP };
class World{
public:

	int fpos=0;
	int fpos2 = 0;
	int count = 0;
	Player *player = nullptr;
	Room *room = nullptr;
	Exit *exit = nullptr;
	void movement();
	int command();
	World();
	
	void createworld();
	~World();
	


};
#endif