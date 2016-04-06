#ifndef _EXIT_
#define _EXIT_
#include"Identity.h"
enum command{ NORTH, WEST, SOUTH, EAST};
class Exit: public Identity{
public:
	Room *origin;
	Room *destiny;
	bool door = false;
	bool closed = false;
	command orientation;
	





};
#endif




