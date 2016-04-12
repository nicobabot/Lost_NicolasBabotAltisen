#ifndef _EXIT_
#define _EXIT_
#include"Entity.h"
enum command{ NORTH=0, WEST, SOUTH, EAST};
class Exit : public Entity{
public:
	Room *origin;
	Room *destiny;
	bool door = false;
	bool closed = false;
	command orientation;
	





};
#endif




