#ifndef _EXIT_
#define _EXIT_
#include"Entity.h"
enum command{ NORTH=0, WEST, SOUTH, EAST};
class Exit : public Entity{
public:
	Exit(char*, char*, command orientation, Room* origen, Room* destination, bool door, bool close);
	Room *origin;
	Room *destiny;
	bool door;
	bool closed;
	command orientation;
	





};
#endif




