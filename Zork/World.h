#include"Rooms.h"
#include"Exits.h"

class World{
public:
	Rooms *room=nullptr;
	Exits *exit=nullptr;
public:
	void createworld();
	void enterinhouse(int&);
	bool trufols(int&);
	World();
	~World();













};