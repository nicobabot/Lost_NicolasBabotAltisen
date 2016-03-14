#ifndef _WORLD_
#define _WORLD_
#include"Room.h"
#include"Exit.h"
#include"Player.h"
class World{
public:
	enum command{ GO = 0, TAKE, LOOK, OPEN, CLOSE };
	
	Player *player = nullptr;
	Room *room = nullptr;
	Exit *exit = nullptr;
	void command();
	World();
	void createworld();
	~World();
	


};
#endif