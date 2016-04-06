#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
World::World(){
	player = new Player;//player
	room = new Room[ROOMNUM];//9 rooms
	exit = new Exit[EXITNUM];//33 exits

}
World::~World(){
	delete[] room;//free memory
	delete[] exit;//free memory
	delete player;//free memory
}

void World::createworld()const{

	strcpy_s(room[0].name, "Entrance of the city");
	strcpy_s(room[0].descrip, "You are in the entrance of the city and you have to find your house.");
	
	strcpy_s(exit[0].name, "Main street");
	strcpy_s(exit[0].descrip, "In the east there is the house 1");
	exit[0].origin = &room[0];
	exit[0].destiny = &room[1];
	exit[0].orientation = EAST;
	
	
	strcpy_s(exit[1].descrip, "There's a wall");
	exit[1].orientation = NORTH;
	exit[1].origin = &room[0];
	exit[1].destiny = &room[0];

	exit[2].orientation = SOUTH;
	strcpy_s(exit[2].descrip, "There's a wall");
	exit[2].origin = &room[0];
	exit[2].destiny = &room[0];

	exit[3].orientation = WEST;
	strcpy_s(exit[3].descrip, "There's a wall");
	exit[3].origin = &room[0];
	exit[3].destiny = &room[0];


	//--------------------------------------------------------------------
	strcpy_s(room[1].name, "House 1");
	strcpy_s(room[1].descrip, "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[4].name, "Studiant Street");
	strcpy_s(exit[4].descrip, "In the east there is the school");
	exit[4].origin = &room[1];
	exit[4].destiny = &room[2];
	exit[4].orientation = EAST;

	strcpy_s(exit[5].descrip, "There's a wall");
	exit[5].orientation = NORTH;
	exit[5].origin = &room[1];
	exit[5].destiny = &room[1];

	exit[6].orientation = SOUTH;
	strcpy_s(exit[6].descrip, "There's a wall");
	exit[6].origin = &room[1];
	exit[6].destiny = &room[1];

	strcpy_s(exit[7].name, "Main street");
	strcpy_s(exit[7].descrip, "In the west there is the entrance of the city");
	exit[7].orientation = WEST;
	exit[7].origin = &room[1];
	exit[7].destiny = &room[0];

	//--------------------------------------------------------------------
	strcpy_s(room[2].name, "School");
	strcpy_s(room[2].descrip, "There's a girl and she want to talk with you.");
	//--------------------------------------------------------------------
	

	strcpy_s(exit[8].descrip, "There's a wall");
	exit[8].origin = &room[2];
	exit[8].destiny = &room[2];
	exit[8].orientation = EAST;


	strcpy_s(exit[9].descrip, "There's a wall");
	exit[9].orientation = NORTH;
	exit[9].origin = &room[2];
	exit[9].destiny = &room[2];

	strcpy_s(exit[10].name, "Joan Oliver street");
	strcpy_s(exit[10].descrip, "In the south there is the house 2");
	exit[10].orientation = SOUTH;
	exit[10].origin = &room[2];
	exit[10].destiny = &room[3];
	
	strcpy_s(exit[11].name, "Student Street");
	strcpy_s(exit[11].descrip, "In the west there is the house 1");
	exit[11].orientation = WEST;
	exit[11].origin = &room[2];
	exit[11].destiny = &room[1];
	
	//----------------------------------------------
	strcpy_s(room[3].name, "House 2");
	strcpy_s(room[3].descrip, "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.");
	//--------------------------------------------------------------------
	strcpy_s(exit[12].name, "Verdi street");
	strcpy_s(exit[12].descrip, "In the east there is the shop");
	exit[12].origin = &room[3];
	exit[12].destiny = &room[4];
	exit[12].orientation = EAST;

	strcpy_s(exit[13].name, "Joan Oliver street");
	strcpy_s(exit[13].descrip, "In the north there is the school");
	exit[13].orientation = NORTH;
	exit[13].origin = &room[3];
	exit[13].destiny = &room[2];

	strcpy_s(exit[14].descrip, "There's a wall");
	exit[14].orientation = SOUTH;
	exit[14].origin = &room[3];
	exit[14].destiny = &room[3];

	strcpy_s(exit[15].descrip, "There's a wall");
	exit[15].orientation = WEST;
	exit[15].origin = &room[3];
	exit[15].destiny = &room[3];
	
	//--------------------------------------------------------------------
	strcpy_s(room[4].name, "Shop");
	strcpy_s(room[4].descrip, "The seller gives you money because he is sad because you are lost.");
	//--------------------------------------------------------------------
	strcpy_s(exit[16].name, "Elisenda street");
	strcpy_s(exit[16].descrip, "In the east there is the cinema");
	exit[16].origin = &room[4];
	exit[16].destiny = &room[5];
	exit[16].orientation = EAST;


	strcpy_s(exit[17].descrip, "There's a wall");
	exit[17].orientation = NORTH;
	exit[17].origin = &room[4];
	exit[17].destiny = &room[4];

	strcpy_s(exit[18].descrip, "There's a wall");
	exit[18].orientation = SOUTH;
	exit[18].origin = &room[4];
	exit[18].destiny = &room[4];

	strcpy_s(exit[19].name, "Verdi street");
	strcpy_s(exit[19].descrip, "In the east there is the house 2");
	exit[19].orientation = WEST;
	exit[19].origin = &room[4];
	exit[19].destiny = &room[3];
	//--------------------------------------------------------------------
	strcpy_s(room[5].name, "Cinema");
	strcpy_s(room[5].descrip, "If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house.");
	//--------------------------------------------------------------------
	strcpy_s(exit[20].descrip, "There's a wall");
	exit[20].origin = &room[5];
	exit[20].destiny = &room[5];
	exit[20].orientation = EAST;

	strcpy_s(exit[21].descrip, "There's a wall");
	exit[21].orientation = NORTH;
	exit[21].origin = &room[5];
	exit[21].destiny = &room[5];

	strcpy_s(exit[22].name, "Hobby street");
	strcpy_s(exit[22].descrip, "In the south there is the park");
	exit[22].orientation = SOUTH;
	exit[22].origin = &room[5];
	exit[22].destiny = &room[6];

	strcpy_s(exit[23].name, "Elisenda street");
	strcpy_s(exit[23].descrip, "In the south there is the shop");
	exit[23].orientation = WEST;
	exit[23].origin = &room[5];
	exit[23].destiny = &room[4];

	//--------------------------------------------------------------------
	strcpy_s(room[6].name, "Park");
	strcpy_s(room[6].descrip, "Oh no! There is a thug take care!");
	//--------------------------------------------------------------------
	strcpy_s(exit[24].name, "Residencial Street");
	strcpy_s(exit[24].descrip, "In the east there is the house 3");
	exit[24].origin = &room[6];
	exit[24].destiny = &room[7];
	exit[24].orientation = EAST;
	
	strcpy_s(exit[25].name, "Hobby street");
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
	strcpy_s(room[7].descrip, "Its seems that there is something important...");
	//--------------------------------------------------------------------
	strcpy_s(exit[28].name, "Residencial Street");
	strcpy_s(exit[28].descrip, "In the east there is the goal");
	exit[28].origin = &room[7];
	exit[28].destiny = &room[8];
	exit[28].orientation = EAST;
	exit[28].door = true;
	exit[28].closed = true;

	strcpy_s(exit[29].descrip, "There's a wall");
	exit[29].orientation = NORTH;
	exit[29].origin = &room[7];
	exit[29].destiny = &room[7];

	strcpy_s(exit[30].descrip, "There's a wall");
	exit[30].orientation = SOUTH;
	exit[30].origin = &room[7];
	exit[30].destiny = &room[7];

	strcpy_s(exit[31].name, "Residencial Street");
	strcpy_s(exit[31].descrip, "In the east there is the park");
	exit[31].orientation = WEST;
	exit[31].origin = &room[7];
	exit[31].destiny = &room[6];
	//--------------------------------------------------------------------
	strcpy_s(room[8].name, "Finish");
	strcpy_s(room[8].descrip, "You finish the game");
	//--------------------------------------------------------------------
	strcpy_s(exit[32].descrip, "There's a wall");
	exit[32].origin = &room[8];
	exit[32].destiny = &room[8];
	exit[32].orientation = EAST;

	strcpy_s(exit[33].descrip, "There's a wall");
	exit[33].orientation = NORTH;
	exit[33].origin = &room[8];
	exit[33].destiny = &room[8];

	strcpy_s(exit[34].descrip, "There's a wall");
	exit[34].orientation = SOUTH;
	exit[34].origin = &room[8];
	exit[34].destiny = &room[8];

	strcpy_s(exit[35].name, "Residencial Street");
	strcpy_s(exit[35].descrip, "In the west there's house 3");
	exit[35].orientation = WEST;
	exit[35].origin = &room[8];
	exit[35].destiny = &room[7];
	exit[35].door = true;
	exit[35].closed = true;
}

void World::movement(){
	int roompos = 0;
	int i = 0, j = 0;
	int x = 0;
	char direction[15];
	help();
	do{
		player->playerposit = &room[roompos];
		printf("Where do you want to go?\n");
		fflush(stdin);
		gets_s(direction);

		fflush(stdin);
		if (strcmp(direction, "go") == 0){
			printf("Which direction?");
			gets_s(direction);
			fflush(stdin);
		}
		system("cls");
		//-------------------------------------------------------------------------------------------------------------North
		if (strcmp(direction, "n") == 0 || strcmp(direction, "north") == 0 || strcmp(direction, "go north") == 0){
			for (i = 0; i < EXITNUM; i++){
				if (player->playerposit == exit[i].origin && exit[i].orientation == NORTH){
					if (exit[i].origin == exit[i].destiny){
						printf("There's a wall");
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i].destiny == &room[j]){
							if (exit[i].origin == exit[i].destiny){
								printf("%s", exit[i].descrip);
								break;
							}
							else{
								if (exit[i].door == true && exit[i].closed == true){
									printf("There's a door");

									break;
								}
								else{
									printf("%s\n", exit[i].name);
									printf("%s\n", &room[j].name);
									printf("%s\n", &room[j].descrip);
									//player->playerposit = &room[j]
									roompos = j;
									break;
									if (player->playerposit - 1 == &room[8] - 1){
										printf("%s\n", exit[i].name);
										system("pause");
										printf("%s\n", &room[j].name);
										printf("%s\n", &room[j].descrip);
										printf("You have finished the game!");
										roompos = j;
										break;
									}
								}
							}
						}
					}break;
				}
			}
		}
		//----------------------------------------------------------------------------------------------------------------West
		if (strcmp(direction, "w") == 0 || strcmp(direction, "west") == 0 || strcmp(direction, "go west") == 0){
			for (i = 0; i < EXITNUM; i++){
				if (player->playerposit == exit[i].origin && exit[i].orientation == WEST){
					if (exit[i].origin == exit[i].destiny){
						printf("There's a wall");
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i].destiny == &room[j]){
							if (exit[i].origin == exit[i].destiny){
								printf("%s", exit[i].descrip);
								break;
							}
							else{
								if (exit[i].door == true && exit[i].closed == true){
									printf("There's a door");
									break;
								}
								else{
									printf("%s\n", exit[i].name);
									printf("%s\n", &room[j].name);
									printf("%s\n", &room[j].descrip);
									//player->playerposit = &room[j]
									roompos = j;
									//break;
									if (player->playerposit - 1 == &room[8] - 1){
										printf("%s\n", exit[i].name);
										system("pause");
										printf("%s\n", &room[j].name);
										printf("%s\n", &room[j].descrip);
										printf("You have finished the game!");
										roompos = j;
										break;
									}
								}
							}
						}
					}break;
				}
			}
		}
		//----------------------------------------------------------------------------------------------------------------South
		if (strcmp(direction, "s") == 0 || strcmp(direction, "south") == 0 || strcmp(direction, "go south") == 0){
			for (i = 0; i < EXITNUM; i++){
				if (player->playerposit == exit[i].origin && exit[i].orientation == SOUTH){
					if (exit[i].origin == exit[i].destiny){
						printf("There's a wall");
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i].destiny == &room[j]){
							if (exit[i].origin == exit[i].destiny){
								printf("%s", exit[i].descrip);
								break;
							}
							else{
								if (exit[i].door == true && exit[i].closed == true){
									printf("There's a door");
									break;
								}
								else{
									printf("%s\n", exit[i].name);
									printf("%s\n", &room[j].name);
									printf("%s\n", &room[j].descrip);
									//player->playerposit = &room[j]
									roompos = j;
									break;
									if (player->playerposit->name == room[j].name){
										printf("%s\n", exit[i].name);
										system("pause");
										printf("%s\n", &room[j].name);
										printf("%s\n", &room[j].descrip);
										printf("You have finished the game!");
										roompos = j;
										break;
									}
								}
							}
						}
					}break;
				}
			}
		}
		//-----------------------------------------------------------------------------------------------------------------East
		if (strcmp(direction, "e") == 0 || strcmp(direction, "east") == 0 || strcmp(direction, "go east") == 0){
			for (i = 0; i < EXITNUM; i++){
				if (player->playerposit == exit[i].origin && exit[i].orientation == EAST){
					if (exit[i].origin == exit[i].destiny){
						printf("%s", exit[i].descrip);
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i].destiny == &room[j]){
							if (exit[i].origin == exit[i].destiny){
								printf("%s", exit[i].descrip);
								break;
							}
							else{
								if (exit[i].door == true && exit[i].closed == true){
									printf("There's a door");
									break;
								}
								else{
									printf("%s\n", exit[i].name);
									printf("%s\n", &room[j].name);
									printf("%s\n", &room[j].descrip);
									//player->playerposit = &room[j]
									roompos = j;
									//break;
									if (player->playerposit - 1 == &room[8] - 1){
										printf("%s\n", exit[i].name);
										system("pause");
										printf("%s\n", &room[j].name);
										printf("%s\n", &room[j].descrip);
										printf("You have finished the game!");
										roompos = j;
										break;
									}
								}
							}
						}
					}break;
				}
			}
		}
		if (strcmp(direction, "h") == 0 || strcmp(direction, "help") == 0){
			help();
		}

		if (strcmp(direction, "look") == 0 || strcmp(direction, "look north") == 0 || strcmp(direction, "look east") == 0 || strcmp(direction, "look west") == 0 || strcmp(direction, "look south") == 0){
			look(direction, roompos);
		}

		if (strcmp(direction, "open") == 0 || strcmp(direction, "open north") == 0 || strcmp(direction, "open east") == 0 || strcmp(direction, "open west") == 0 || strcmp(direction, "open south") == 0){
			if (strcmp(direction, "open") == 0){
				printf("Which direction?\n");
				gets_s(direction);
			}
			Open(direction);
		}

		if (strcmp(direction, "close") == 0 || strcmp(direction, "close north") == 0 || strcmp(direction, "close east") == 0 || strcmp(direction, "close west") == 0 || strcmp(direction, "close south") == 0){
			if (strcmp(direction, "close") == 0){
				printf("Which direction?\n");
				gets_s(direction);
			}
			Close(direction);
		}
		if (player->playerposit - 1 == &room[8] - 1){
			break;
		}



	} while (strcmp(direction, "q") != 0);
}


		void World::help()const{

			printf("You are lost in the city and you have to find your new house.\n You can move arround the map using ONLY lowercase.\n You can use to move: n, e, s, w or north, east, south, west, also go north, go south, go west, go east.\n There will be doors in the map you can open and close some them using open and to close use the word close.\n You can look what is in the room you are and int his directions\n There is only a door you have to open and close that now you can but in nexts Zorks you will need a key\n");


		}
		void World::look(const char *looks, int numroom)const{
			int exitnum=0;//count
			if ((strcmp(looks, "look") == 0)){//if the user only says look
				printf("%s\n", room[numroom].descrip);
			}

			if ((strcmp(looks, "look north") == 0)){//if the user says look north
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == NORTH)//exits with north orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum].descrip);
						}

					}
				}
			}
			if ((strcmp(looks, "look west") == 0)){//if the user says look west
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == WEST)//exits with west orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum].descrip);
						}
					}
				}
				//printf("%s\n", exit[numexit].descrip);
			}

			if ((strcmp(looks, "look south") == 0)){//if the user says look south
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == SOUTH)//exits with south orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum].descrip);
						}
					}
				}
			}

			if ((strcmp(looks, "look east") == 0)){//if the user says look east
				for (exitnum = 0; exitnum < 33; exitnum++)
				{
					if (exit[exitnum].orientation == EAST)//exits with east orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s", exit[exitnum].descrip);
						}
					}
				}
			}


		}

		

		void World::Open(char *direction)
		{

			int i, j;
			if (strcmp(direction, "open north") == 0 || strcmp(direction, "open n") == 0 || strcmp(direction, "north") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == NORTH){
							if (exit[i].door == true){
								if (exit[i].closed == true){
									exit[i].closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation == SOUTH){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = false;
												printf("The door is opened.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}


			if (strcmp(direction, "open west") == 0 || strcmp(direction, "open west") == 0 || strcmp(direction, "west") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == WEST){
							if (exit[i].door == true){
								if (exit[i].closed == true){
									exit[i].closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation == EAST){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = false;
												printf("The door is opened.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}


			if (strcmp(direction, "open east") == 0 || strcmp(direction, "open e") == 0 || strcmp(direction, "east") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == EAST){
							if (exit[i].door == true){
								if (exit[i].closed == true){
									exit[i].closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation == WEST){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = false;
												printf("The door is opened.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}


			if (strcmp(direction, "open south") == 0 || strcmp(direction, "open s") == 0 || strcmp(direction, "south") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == SOUTH){
							if (exit[i].door == true){
								if (exit[i].closed == true){
									exit[i].closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation == NORTH){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = false;
												printf("The door is opened.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}
		}

		void World::Close(char *direction)
		{

			int i, j;
			if (strcmp(direction, "close north") == 0 || strcmp(direction, "close n") == 0 || strcmp(direction, "north") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == NORTH){
							if (exit[i].door == true){
								if (exit[i].closed == false){
									exit[i].closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation = SOUTH){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed == true;
												printf("The door is closed.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}


			if (strcmp(direction, "close west") == 0 || strcmp(direction, "close west") == 0 || strcmp(direction, "west") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == WEST){
							if (exit[i].door == true){
								if (exit[i].closed == false){
									exit[i].closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation == EAST){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = true;
												printf("The door is closed.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}


			if (strcmp(direction, "close east") == 0 || strcmp(direction, "close e") == 0 || strcmp(direction, "east") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == EAST){
							if (exit[i].door == true){
								if (exit[i].closed == false){
									exit[i].closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation = WEST){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = true;
												printf("The door is closed.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}


			if (strcmp(direction, "close south") == 0 || strcmp(direction, "close s") == 0 || strcmp(direction, "south") == 0)
			{
				for (i = 0; i < EXITNUM; i++){
					if (strcmp(exit[i].origin->name, player->playerposit->name) == 0){
						if (exit[i].orientation == SOUTH){
							if (exit[i].door == true){
								if (exit[i].closed == false){
									exit[i].closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j].orientation = NORTH){
											if (exit[j].destiny->name == exit[i].origin->name){
												exit[j].closed = true;
												printf("The door is closed.\n");
												return;
											}
										}
									}
								}
								else{
									printf("The door was already opened.\n");
									break;
								}
							}
							else{
								printf("There is not a door here.\n");
								break;
							}
						}
					}
				}
			}
		}