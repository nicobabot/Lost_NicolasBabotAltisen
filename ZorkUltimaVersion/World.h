#ifndef _WORLD_
#define _WORLD_
#define _CRT_SECURE_NO_WARNINGS
#include"Identity.h"
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
public:
	World();
	void movement();
	void help()const;
	void look(const char*, int)const;
	void createworld()const;
	void doors(int, char*);
	void Open(char*);
	void Close(char*);
	~World();
};
#endif