#include<stdio.h>
#include<stdlib.h>
#include"World.h"


Exit::Exit(char *name, char *description, command orientation, Room *origin, Room* destination, bool door, bool closed, TYPE type) : Entity(name, description, type), orientation(orientation), origin(origin), destiny(destination), door(door), closed(closed)
{
}