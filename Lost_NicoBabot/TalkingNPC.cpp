#include<time.h>
#include"World.h"
#include<Windows.h>
#define DELAY 3000
void Person::Update(){

		timenow = GetTickCount();
		switch (state){
		case IDLE:
			idle();
			break;
		case TALKING:
			talking();
			break;
		case FINISH :
			break;

		}

}

void Person::idle(){
	world->guy->position = (Room*)world->entities[0];//pacific npc
	if (world->player->position == world->guy->position && world->option2 == "talk"){//if the player says talk
		state = TALKING;
		return;
	}
}

void Person::talking(){
	if (!world->option2.empty()){
		if (world->option2 == "talk"){//if the user says talk
			printf("Hi how are you?\n");
			printf("1.Sad im lost\n");
			printf("2.Happy im in an adventure\n");
			return;

		}
		else if (world->option2 == "1"){//if the user choice option 1
			printf("Ohhh im sorry\n");
			state = FINISH;
			return;
		}
		else if (world->option2 == "2"){//if the user choice option 2
			printf("Nice im really excited for you\n");
			return;
			state = FINISH;
		}
	}
	

}