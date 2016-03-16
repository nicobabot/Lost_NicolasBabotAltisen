#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
World::World(){
	player = new Player;
	room = new Room[9];
	exit = new Exit[33];

}
World::~World(){
	delete[] room;
	delete[] exit;
	delete player;
}

void World::createworld(){

	strcpy_s(room[0].name, "Entrance of the city");
	strcpy_s(room[0].description, "You are in the entrance of the city and you have to find your house.");
	
	strcpy_s(exit[0].name, "Main street");
	strcpy_s(exit[0].descrip, "In the east there is the house 1");
	exit[0].origin = &room[0];
	exit[0].destiny = &room[1];
	exit[0].orientation = EAST;
	exit[0].open = true;

	strcpy_s(exit[1].name, "There's a wall");
	exit[1].orientation = NORTH;
	exit[1].origin = &room[0];
	exit[1].destiny = &room[0];

	exit[2].orientation = SOUTH;
	strcpy_s(exit[2].name, "There's a wall");
	exit[2].origin = &room[0];
	exit[2].destiny = &room[0];

	exit[3].orientation = WEST;
	strcpy_s(exit[3].name, "There's a wall");
	exit[3].origin = &room[0];
	exit[3].destiny = &room[0];

	
	//--------------------------------------------------------------------
	strcpy_s(room[1].name, "House 1");
	strcpy_s(room[1].description, "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[4].descrip, "In the east there is the school");
	exit[4].origin = &room[1];
	exit[4].destiny = &room[2];
	exit[4].orientation = EAST;


	strcpy_s(exit[5].name, "There's a wall");
	exit[5].orientation = NORTH;
	exit[5].origin = &room[1];
	exit[5].destiny = &room[1];

	exit[6].orientation = SOUTH;
	strcpy_s(exit[6].name, "There's a wall");
	exit[6].origin = &room[1];
	exit[6].destiny = &room[1];

	strcpy_s(exit[7].descrip, "In the west there is the entrance of the city");
	exit[7].orientation = WEST;
	exit[7].origin = &room[1];
	exit[7].destiny = &room[0];

	//--------------------------------------------------------------------
	strcpy_s(room[2].name, "School");
	strcpy_s(room[2].description, "There's a girl and she want to talk with you.");
	//--------------------------------------------------------------------
	

	strcpy_s(exit[8].descrip, "There's a wall");
	exit[8].origin = &room[2];
	exit[8].destiny = &room[2];
	exit[8].orientation = EAST;
	

	strcpy_s(exit[9].descrip, "There's a wall");
	exit[9].orientation = NORTH;
	exit[9].origin = &room[4];
	exit[9].destiny = &room[4];

	strcpy_s(exit[10].descrip, "In the south there is the house 2");
	exit[10].orientation = SOUTH;
	exit[10].origin = &room[2];
	exit[10].destiny = &room[3];

	strcpy_s(exit[11].descrip, "In the west there is the house 1");
	exit[11].orientation = WEST;
	exit[11].origin = &room[2];
	exit[11].destiny = &room[1];
	//----------------------------------------------
	strcpy_s(room[3].name, "House 2,");
	strcpy_s(room[3].description, "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.");
	//--------------------------------------------------------------------
	strcpy_s(exit[12].descrip, "In the east there is the shop");
	exit[12].origin = &room[3];
	exit[12].destiny = &room[4];
	exit[12].orientation = EAST;


	strcpy_s(exit[13].descrip, "In the north there is the school");
	exit[13].orientation = NORTH;
	exit[13].origin = &room[3];
	exit[13].destiny = &room[2];

	strcpy_s(exit[14].name, "There's a wall");
	exit[14].orientation = SOUTH;
	exit[14].origin = &room[3];
	exit[14].destiny = &room[3];

	strcpy_s(exit[15].name, "There's a wall");
	exit[15].orientation = WEST;
	exit[15].origin = &room[3];
	exit[15].destiny = &room[3];
	//--------------------------------------------------------------------
	strcpy_s(room[4].name, "Shop");
	strcpy_s(room[4].description, "The seller gives you money because he is sad because you are lost.");
	//--------------------------------------------------------------------
	strcpy_s(exit[16].descrip, "In the east there is the cinema");
	exit[16].origin = &room[4];
	exit[16].destiny = &room[5];
	exit[16].orientation = EAST;


	strcpy_s(exit[17].descrip, "There's a wall");
	exit[17].orientation = NORTH;
	exit[17].origin = &room[4];
	exit[17].destiny = &room[4];

	strcpy_s(exit[18].name, "There's a wall");
	exit[18].orientation = SOUTH;
	exit[18].origin = &room[4];
	exit[18].destiny = &room[4];

	strcpy_s(exit[16].descrip, "In the east there is the house 2");
	exit[19].orientation = WEST;
	exit[19].origin = &room[4];
	exit[19].destiny = &room[3];
	//--------------------------------------------------------------------
	strcpy_s(room[5].name, "Cinema");
	strcpy_s(room[5].description, "If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[20].name, "There's a wall");	
	exit[20].origin = &room[5];
	exit[20].destiny = &room[5];
	exit[20].orientation = EAST;

	strcpy_s(exit[21].descrip, "There's a wall");
	exit[21].orientation = NORTH;
	exit[21].origin = &room[5];
	exit[21].destiny = &room[5];

	strcpy_s(exit[22].descrip, "In the south there is the park");
	exit[22].orientation = SOUTH;
	exit[22].origin = &room[5];
	exit[22].destiny = &room[6];

	strcpy_s(exit[23].descrip, "In the south there is the shop");
	exit[23].orientation = WEST;
	exit[23].origin = &room[5];
	exit[23].destiny = &room[4];
	//--------------------------------------------------------------------
	strcpy_s(room[6].name, "Park");
	strcpy_s(room[6].description, "Oh no! There is a thug take care!");
	//--------------------------------------------------------------------
	
	strcpy_s(exit[24].descrip, "In the east there is the house 3");
	exit[24].origin = &room[6];
	exit[24].destiny = &room[7];
	exit[24].orientation = EAST;

	strcpy_s(exit[25].descrip, "In the north there is the cinema");
	exit[25].orientation = NORTH;
	exit[25].origin = &room[6];
	exit[25].destiny = &room[5];

	strcpy_s(exit[26].descrip, "There's a wall");
	exit[26].orientation = SOUTH;
	exit[26].origin = &room[6];
	exit[26].destiny = &room[6];

	strcpy_s(exit[27].descrip, "There's a wall");
	exit[27].orientation = WEST;
	exit[27].origin = &room[6];
	exit[27].destiny = &room[6];
	//--------------------------------------------------------------------
	strcpy_s(room[7].name, "House 3");
	strcpy_s(room[7].description, "Its seems that there is something important...");
	//--------------------------------------------------------------------
	
	strcpy_s(exit[28].descrip, "In the east there is the goal");
	exit[28].origin = &room[7];
	exit[28].destiny = &room[8];
	exit[28].orientation = EAST;

	strcpy_s(exit[29].descrip, "There's a wall");
	exit[29].orientation = NORTH;
	exit[29].origin = &room[7];
	exit[29].destiny = &room[7];

	strcpy_s(exit[30].descrip, "There's a wall");
	exit[30].orientation = SOUTH;
	exit[30].origin = &room[7];
	exit[30].destiny = &room[7];

	strcpy_s(exit[28].descrip, "In the east there is the park");
	exit[31].orientation = WEST;
	exit[31].origin = &room[7];
	exit[31].destiny = &room[8];
	//--------------------------------------------------------------------
	strcpy_s(room[8].name, "Finish");
	strcpy_s(room[8].description, "You finish the game");
	exit[32].origin = &room[8];
	exit[8].open = true;
}

void World::movement(){
	int i = 0, j = 0, space = 0, roompos = 0;
	char direction, direction2;
	int compexits, comprooms = 0;
	//int option;
	char option[25];
	player->playerposit = &room[roompos];
	/*printf("%s\n", room[roompos].name);
	printf("%s\n", room[roompos].description);*/
	do{
		printf("What do you want to do?");
		gets_s(option);
		int exitnum = 0, roomnum = 0;
			if (strcmp(option, "go") == 0)
			{
				printf("Which direction do you want to go? ");
				fflush(stdin);
				gets_s(option);
				fflush(stdin);
			}
			
			if (strcmp(option, "n") == 0 || strcmp(option, "north") == 0 || strcmp(option, "go north") == 0)
			{
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == NORTH)
					{
						if (exit[exitnum].origin == player->playerposit)
						{
							if (exit[exitnum].origin == exit[exitnum].destiny)
							{
								printf("%s\n", exit[27].descrip);
								break;

							}
							for (roomnum = 0; roomnum < 9; roomnum++)
							{
								if (exit[exitnum].destiny == &room[roomnum])
								{
									
									roompos = roomnum;
									player->playerposit = exit[exitnum].destiny;
									printf("Now you are in %s.\n", player->playerposit);
									break;
								}
							}break;
						}
					}
				}
			}
		
			if (strcmp(option, "s") == 0 || strcmp(option, "south") == 0 || strcmp(option, "go south") == 0)
			{
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == SOUTH)
					{
						if (exit[exitnum].origin == player->playerposit)
						{
							if (exit[exitnum].origin == exit[exitnum].destiny)
							{
								printf("%s\n", exit[27].descrip);
								break;

							}
							for (roomnum = 0; roomnum < 9; roomnum++)
							{
								if (exit[exitnum].destiny == &room[roomnum])
								{
									roompos = roomnum;
									player->playerposit = exit[exitnum].destiny;
									printf("Now you are in %s.\n", player->playerposit);
									break;
								}
							}break;
						}
					}
				}
			}


			if (strcmp(option, "w") == 0 || strcmp(option, "west") == 0 || strcmp(option, "go west") == 0)
			{
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == WEST)
					{
						if (exit[exitnum].origin == player->playerposit)
						{
							if (exit[exitnum].origin == exit[exitnum].destiny)
							{
								printf("%s\n", exit[27].descrip);
								break;

							}
							for (roomnum = 0; roomnum < 9; roomnum++)
							{
								if (exit[exitnum].destiny == &room[roomnum])
								{
									roompos = roomnum;
									player->playerposit = exit[exitnum].destiny;
									printf("Now you are in %s.\n", player->playerposit);
									break;
								}
							}break;
						}
					}
				}
			}
			if (strcmp(option, "e") == 0 || strcmp(option, "east") == 0 || strcmp(option, "go east") == 0)
			{
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == EAST)
					{
						if (exit[exitnum].origin == player->playerposit)
						{
							if (exit[exitnum].origin == exit[exitnum].destiny)
							{
								printf("%s\n", exit[27].descrip);
								break;

							}
							for (roomnum = 0; roomnum < 9; roomnum++)
							{
								if ((exit+exitnum)->destiny == &room[roomnum])
								{
									
									roompos = roomnum;
									player->playerposit = exit[exitnum].destiny;
									printf("Now you are in %s.\n", player->playerposit);
									break;
								}
							}break;
						}
					}
				}

			}
		}while (1);
		}
	



int World::command(){

	int space = 0;
	int i = 0, direction2 = 0;
	char fullcommand[20];
	char firstcommand[10];
	char secondcommand[10];
	char command[10];
	char *context;//Strtok_s variable, need it to save the state of the string he analyzes. Doesn't needed with strtok.
	printf("What do you want to do?\n");
	gets_s(fullcommand);
	for (i = 0; i <= (strlen(fullcommand)); i++){
		if (fullcommand[i] == ' '){
			space++;
		}
	}
	if (space > 0){
		strcpy_s(firstcommand, strtok_s(fullcommand, " ", &context));
		strcpy_s(secondcommand, strtok_s(NULL, " ", &context));
		if (strcmp("go", firstcommand) == 0){
			if (strcmp("north", secondcommand) == 0){
				return NORTH;
			}
			if (strcmp("west", secondcommand) == 0){
				return WEST;
			}
			if (strcmp("south", secondcommand) == 0){
				return SOUTH;
			}
			if (strcmp("east", secondcommand) == 0){
				return EAST;
			}
		}
	}
	if (strcmp("north", fullcommand) == 0 || strcmp("n", fullcommand) == 0){
		return NORTH;
	}
	if (strcmp("west", fullcommand) == 0 || strcmp("w", fullcommand) == 0){
		return WEST;
	}
	if (strcmp("south", fullcommand) == 0 || strcmp("s", fullcommand) == 0){
		return SOUTH;
	}
	if (strcmp("east", fullcommand) == 0 || strcmp("e", fullcommand) == 0){
		return EAST;
	}

	if (strcmp("look", fullcommand) == 0){
		return LOOK;
	}

	if (strcmp("open", fullcommand) == 0){
		return OPEN;
		
	}
	if (strcmp("close", fullcommand) == 0){
		return CLOSE;

	}
	if (strcmp("help", fullcommand)){

		return HELP;


	}












}