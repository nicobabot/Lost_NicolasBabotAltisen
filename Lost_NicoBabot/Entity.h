#ifndef _Entity_
#define _Entity_
#include"MyString.h"
#include"Dlist.h"
enum TYPE{ EXIT, ROOM, PLAYER, THUG, ITEM, PERSON, SELLER };
class Entity{
	
public:
	mystring name;
	mystring descrip;
	TYPE Typeobj;
	Dlist<Entity*> list;
public:
	Entity(const char* name, const char* descrip, TYPE Typeobj);
	virtual void Update();
	virtual ~Entity();


};
#endif

