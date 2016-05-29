#include<time.h>
#include"World.h"
#include<Windows.h>
#define DELAY 2500
void Thug::Update(){
	timenow = GetTickCount();
	switch (state){
	case MOVING:
		movementenemy();
		break;
	case ASKING:
		ask();
		break;
	case FIGHT:
		fight();
		break;
	case DEAD:
		enemydead();
		break;
	}
	
}


void Thug::movementenemy(){
	int i = (rand() % 3) + 4;
	world->thug->position = (Room*)world->entities[i];
	if (world->player->position == world->thug->position){
		state = FIGHT;
	}
}

void Thug::ask(){
	printf("Hi give me the money!");
	





}

void Thug::fight(){
	if (health>0){
		if (timenow >= timing + DELAY){
			timing = timenow;
			printf("Thug hit you for %i of damge\n", damage);
			world->player->health -= damage;
			state = FIGHT;



		}
	}
	else{
		state = DEAD;
	}
	



}

void Thug::enemydead(){
	
	printf("The thug is dead");
	//position = nullptr;
}