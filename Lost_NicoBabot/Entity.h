#ifndef _Entity_
#define _Entity_
#include"MyString.h"
enum TYPE{ EXIT, ROOM, PLAYER, THUG, ITEM };
class Entity{
	
public:
	mystring name;
	mystring descrip;
	TYPE Typeobj;
public:
	Entity(const char* name, const char* descrip, TYPE Typeobj);
	//virtual int Update();
	virtual ~Entity();


};
#endif

