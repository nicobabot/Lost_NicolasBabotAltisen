#ifndef _EXIT_
#define _EXIT_
enum command{ NORTH, WEST, SOUTH, EAST};
class Exit{
public:
	char name[30];
	char descrip[300];
	Room *origin;
	Room *destiny;
	bool door = false;
	bool open = false;
	command orientation;
	





};
#endif




