#include<time.h>
#include"World.h"
#include<Windows.h>
#define DELAY 3000
void Thug::Update(){//State machine
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
	world->thug->position = (Room*)world->entities[i];//randon movement of enemy
	if (world->player->position == world->thug->position){//if player is in the same room 
		state = FIGHT;
	}
}

void Thug::fight(){
	if (health>0){//if thug have more than 0 health
		if (timenow >= timing + DELAY){//timing of attack
			timing = timenow;
			printf("Thug hit you for %i of damage\n", damage);
			if (world->player->health <= 0){//if the player die
				state = DISAPPEAR;
			}
		}
		}
	else{
		state = DEAD;//if the thug die
	}
	}
	



void Thug::enemydead(){
	
	printf("The thug is dead");
	state = DISAPPEAR;

	
	
}

