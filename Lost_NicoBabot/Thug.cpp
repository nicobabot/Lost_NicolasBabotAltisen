#include<time.h>
#include"World.h"
void Thug::Update(){
	int i = (rand() % 3) + 4;
	world->thug->position = (Room*)world->entities[i];
	if (world->player->position == world->thug->position){
	//	printf("HI I AM A THUG");
		fight();
	}
	//printf("HI\n");
}

void Thug::fight(){





}