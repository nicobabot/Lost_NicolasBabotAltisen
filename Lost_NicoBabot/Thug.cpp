#include<time.h>
#include"World.h"
#include<Windows.h>
#define DELAY 3000
void Thug::Update(){
	timenow = GetTickCount();
	switch (state){
	case MOVING:
		movementenemy();
		break;
	case FIGHT:
		fight();
		break;
	case DEAD:
		enemydead();
		break;
	case DISAPPEAR:
		break;
	}
	
}


void Thug::movementenemy(){
	int i = (rand() % 2) + 5;
	world->thug->position = (Room*)world->entities[i];
	if (world->player->position == world->thug->position){
		state = FIGHT;
	}
}

void Thug::fight(){
	if (health>0){
		if (timenow >= timing + DELAY){
			timing = timenow;
			printf("Thug hit you for %i of damage\n", damage);
			//world->player->health -= damage;
			if (world->player->health <= 0){
				state = DISAPPEAR;
			}
		}
		}
	else{
		state = DEAD;
	}
	}
	



void Thug::enemydead(){
	
	printf("The thug is dead");
	state = DISAPPEAR;

	
	
}

