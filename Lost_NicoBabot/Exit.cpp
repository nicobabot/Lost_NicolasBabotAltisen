#include<stdio.h>
#include<stdlib.h>
#include"World.h"


Exit::Exit(char *name, char *description, command orientation, Room *origin, Room* destination, bool door, bool closed) : Entity(name, description), orientation(orientation), origin(origin), destiny(destination), door(door), closed(closed)
{
}