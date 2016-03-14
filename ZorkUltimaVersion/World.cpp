#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
World::World(){
	player = new Player;
	room = new Room[9];
	exit = new Exit[16];
}
World::~World(){
	delete[] room;
	delete[] exit;
	delete player;
}

void World::createworld(){

	strcpy_s(room[0].name, "Entrance of the city");
	strcpy_s(room[0].description, "You are in the entrance of the city and you have to find your house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[0].name, "Main street");
	strcpy_s(exit[0].descrip, "In the east there is the house 1");
	exit[0].origin = &room[0];
	exit[0].destiny = &room[1];
	exit[0].orientation = EAST;	
	exit[0].open = true;
	//--------------------------------------------------------------------

	strcpy_s(room[1].name, "House 1");
	strcpy_s(room[1].description, "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[1].name, "Verdi street");
	strcpy_s(exit[1].descrip, "In the east there is the school");
	exit[1].origin = &room[1];
	exit[1].destiny = &room[0];
	exit[1].orientation = WEST;
	exit[2].destiny = &room[2];
	exit[1].orientation = EAST;
	//--------------------------------------------------------------------
	strcpy_s(room[2].name, "School");
	strcpy_s(room[2].description, "There's a girl and she want to talk with you.");
	//--------------------------------------------------------------------
	strcpy_s(exit[2].name, "Ramblas street");
	strcpy_s(exit[2].descrip, "In the south there is the house 2");
	exit[2].origin = &room[2];
	exit[3].destiny = &room[1];
	exit[3].orientation = WEST;
	exit[4].destiny = &room[3];
	exit[4].orientation = SOUTH;
	//--------------------------------------------------------------------
	strcpy_s(room[3].name, "House 2,");
	strcpy_s(room[3].description, "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.");
	//--------------------------------------------------------------------
	strcpy_s(exit[3].name, "Joan Oliver street");
	strcpy_s(exit[3].descrip, "In the east there is the shop");
	exit[3].origin = &room[3];
	exit[5].destiny = &room[2];
	exit[5].orientation = NORTH;
	exit[6].destiny = &room[4];
	exit[6].orientation = EAST;
	//--------------------------------------------------------------------
	strcpy_s(room[4].name, "Shop");
	strcpy_s(room[4].description, "The seller gives you money because he is sad because you are lost.");
	//--------------------------------------------------------------------
	strcpy_s(exit[4].name, "Gracia street");
	strcpy_s(exit[4].descrip, "In the east there is the cinema");
	exit[4].origin = &room[4];
	exit[7].destiny = &room[3];
	exit[7].orientation = WEST;
	exit[8].destiny = &room[5];
	exit[8].orientation = EAST;
	//--------------------------------------------------------------------
	strcpy_s(room[5].name, "Cinema");
	strcpy_s(room[5].description, "If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[5].name, "Angli street");
	strcpy_s(exit[5].descrip, "In the south there is the park");
	exit[5].origin = &room[5];
	exit[9].destiny = &room[4];
	exit[9].orientation = WEST;
	exit[10].destiny = &room[6];
	exit[10].orientation = SOUTH;
	//--------------------------------------------------------------------
	strcpy_s(room[6].name, "Park");
	strcpy_s(room[6].description, "Oh no! There is a thug take care!");
	//--------------------------------------------------------------------
	strcpy_s(exit[6].name, "Joselito street");
	strcpy_s(exit[6].descrip, "In the east there is the house 3");
	exit[6].origin = &room[6];
	exit[11].destiny = &room[5];
	exit[11].orientation = NORTH;
	exit[12].destiny = &room[7];
	exit[12].orientation = EAST;
	//--------------------------------------------------------------------
	strcpy_s(room[7].name, "House 3");
	strcpy_s(room[7].description, "Its seems that there is something important...");
	//--------------------------------------------------------------------
	strcpy_s(exit[7].name, "Bronx street");
	strcpy_s(exit[7].descrip, "In the east there is the goal");
	exit[7].origin = &room[7];
	exit[13].destiny = &room[6];
	exit[13].orientation = WEST;
	exit[14].destiny = &room[8];
	exit[14].orientation = EAST;
	//--------------------------------------------------------------------
	strcpy_s(room[8].name, "Finish");
	strcpy_s(room[8].description, "You finish the game");
	exit[8].origin = &room[8];
	exit[8].open = true;
}

void World::command(){
	World world;
	char direction;
	int fpos = 0;
	int compexits, comprooms;
	/*char fullcommand[20];
	char firstcommand[10];
	char secondcommand[10];
	char command[10];
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	printf("What do you want to do?\n");
	gets_s(fullcommand);
	strcpy_s(firstcommand, strtok_s(fullcommand, " ", &context));
	strcpy_s(secondcommand, strtok_s(NULL, " ", &context));
	if (strcmp("go north", fullcommand) == 0){

	}*/
	printf("You are in %s\n", room[fpos].name);
	printf("What do you want to do?\n");
	scanf_s("%c", &direction);
	player->playerposit = &room[fpos];
	do{
		switch (direction)
		{
		case 'n': for (compexits = 0; compexits < 16; compexits++){//16 exits
					  if (exit[compexits].origin == player->playerposit && exit[compexits].orientation == NORTH){
						  for (comprooms = 0; comprooms < 9; comprooms++){//9 rooms
							  if (exit[compexits].destiny == (room + comprooms)){
								  printf("You are in %s\n", player->playerposit);
								  fpos = comprooms;
								  return;

							  }
						  }
					  }
		}
				  break;

		case 'w': for (compexits = 0; compexits < 16; compexits++){//16 exits
					  if (exit[compexits].origin == player->playerposit && exit[compexits].orientation == WEST){
						  for (comprooms = 0; comprooms < 9; comprooms++){//9 rooms
							  if (exit[compexits].destiny == (room + comprooms)){
								  printf("You are in %s\n", player->playerposit);
								  fpos = comprooms;
								  return;

							  }
						  }
					  }
		}
				  break;

		case 's': for (compexits = 0; compexits < 16; compexits++){//16 exits
					  if (exit[compexits].origin == player->playerposit && exit[compexits].orientation == SOUTH){
						  for (comprooms = 0; comprooms < 9; comprooms++){//9 rooms
							  if (exit[compexits].destiny == (room + comprooms)){
								  printf("You are in %s\n", player->playerposit);
								  fpos = comprooms;
								  return;

							  }
						  }
					  }
		}
				  break;

		case 'e': for (compexits = 0; compexits < 16; compexits++){//16 exits
					  if (exit[compexits].origin == player->playerposit && exit[compexits].orientation == EAST){
						  for (comprooms = 0; comprooms < 9; comprooms++){//9 rooms
							  if (exit[compexits].destiny == (room + comprooms)){
								  printf("You are in %s\n", player->playerposit);
								  fpos = comprooms;
								  return;

							  }
						  }
					  }
		}
				  break;
		}
	} while (direction != 'q');

}


