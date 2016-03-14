#ifndef _EXIT_
#define _EXIT_
#define NONE -1
enum direct{ NORTH = 0, WEST, SOUTH, EAST };
class Exit{
public:
	char name[30];
	char descrip[300];
	Room *origin;
	Room *destiny;
	bool open = false;
	direct orientation;





};
#endif




