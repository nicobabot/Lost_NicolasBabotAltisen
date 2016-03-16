#ifndef _EXIT_
#define _EXIT_
enum command{ NORTH, WEST, SOUTH, EAST, QUIT, GO, TAKE, LOOK, OPEN, CLOSE, HELP };
class Exit{
public:
	char name[30];
	char descrip[300];
	Room *origin;
	Room *destiny;
	bool open = false;
	command orientation;





};
#endif




