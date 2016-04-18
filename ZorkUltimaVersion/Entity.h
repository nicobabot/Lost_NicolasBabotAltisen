#ifndef _Entity_
#define _Entity_
#include"MyString.h"
class Entity{
public:
	mystring name;
	mystring descrip;

public:
	Entity(const char* name, const char* descrip);
	virtual ~Entity();


};
#endif

