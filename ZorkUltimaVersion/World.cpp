#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
#include"MyString.h"

World::World(){
	player = new Player;//player
	room = new Room[ROOMNUM];//9 rooms
	exit = new Exit[EXITNUM];//33 exits
	direction = new mystring;
	items = new Item[6];

}
World::~World(){
	delete[] room;//free memory
	delete[] exit;//free memory
	delete player;//free memory
	delete direction;
	delete[] items;
}

void World::createworld()const{

	room[0].name  = "Entrance of the city";
	room[0].descrip = "You are in the entrance of the city and you have to find your house.";
	
	exit[0].name= "Main street";
	exit[0].descrip="In the east there is the house 1";
	exit[0].origin = &room[0];
	exit[0].destiny = &room[1];
	exit[0].orientation = EAST;
	
	
	exit[1].descrip = "There's a wall";
	exit[1].orientation = NORTH;
	exit[1].origin = &room[0];
	exit[1].destiny = &room[0];

	exit[2].orientation = SOUTH;
	exit[2].descrip="There's a wall";
	exit[2].origin = &room[0];
	exit[2].destiny = &room[0];

	exit[3].orientation = WEST;
	exit[3].descrip = "There's a wall";
	exit[3].origin = &room[0];
	exit[3].destiny = &room[0];


	//--------------------------------------------------------------------
	room[1].name ="House 1";
	room[1].descrip = "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.";
	//--------------------------------------------------------------------
	exit[4].name="Studiant Street";
	exit[4].descrip = "In the east there is the school";
	exit[4].origin = &room[1];
	exit[4].destiny = &room[2];
	exit[4].orientation = EAST;

	exit[5].descrip="There's a wall";
	exit[5].orientation = NORTH;
	exit[5].origin = &room[1];
	exit[5].destiny = &room[1];

	exit[6].orientation = SOUTH;
	exit[6].descrip="There's a wall";
	exit[6].origin = &room[1];
	exit[6].destiny = &room[1];

	exit[7].name="Main street";
	exit[7].descrip ="In the west there is the entrance of the city";
	exit[7].orientation = WEST;
	exit[7].origin = &room[1];
	exit[7].destiny = &room[0];

	//--------------------------------------------------------------------
	room[2].name="School";
	room[2].descrip="There's a girl and she want to talk with you.";
	//--------------------------------------------------------------------
	

	exit[8].descrip="There's a wall";
	exit[8].origin = &room[2];
	exit[8].destiny = &room[2];
	exit[8].orientation = EAST;


	exit[9].descrip="There's a wall";
	exit[9].orientation = NORTH;
	exit[9].origin = &room[2];
	exit[9].destiny = &room[2];

	exit[10].name="Joan Oliver street";
	exit[10].descrip="In the south there is the house 2";
	exit[10].orientation = SOUTH;
	exit[10].origin = &room[2];
	exit[10].destiny = &room[3];
	
	exit[11].name="Student Street";
	exit[11].descrip="In the west there is the house 1";
	exit[11].orientation = WEST;
	exit[11].origin = &room[2];
	exit[11].destiny = &room[1];
	
	//----------------------------------------------
	room[3].name= "House 2";
	room[3].descrip= "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.";
	//--------------------------------------------------------------------
	exit[12].name="Verdi street";
	exit[12].descrip="In the east there is the shop";
	exit[12].origin = &room[3];
	exit[12].destiny = &room[4];
	exit[12].orientation = EAST;

	exit[13].name="Joan Oliver street";
	exit[13].descrip="In the north there is the school";
	exit[13].orientation = NORTH;
	exit[13].origin = &room[3];
	exit[13].destiny = &room[2];

	exit[14].descrip="There's a wall";
	exit[14].orientation = SOUTH;
	exit[14].origin = &room[3];
	exit[14].destiny = &room[3];

	exit[15].descrip="There's a wall";
	exit[15].orientation = WEST;
	exit[15].origin = &room[3];
	exit[15].destiny = &room[3];
	
	//--------------------------------------------------------------------
	room[4].name="Shop";
	room[4].descrip="The seller gives you money because he is sad because you are lost.";
	//--------------------------------------------------------------------
	exit[16].name="Elisenda street";
	exit[16].descrip="In the east there is the cinema";
	exit[16].origin = &room[4];
	exit[16].destiny = &room[5];
	exit[16].orientation = EAST;


	exit[17].descrip="There's a wall";
	exit[17].orientation = NORTH;
	exit[17].origin = &room[4];
	exit[17].destiny = &room[4];

	exit[18].descrip="There's a wall";
	exit[18].orientation = SOUTH;
	exit[18].origin = &room[4];
	exit[18].destiny = &room[4];

	exit[19].name="Verdi street";
	exit[19].descrip="In the east there is the house 2";
	exit[19].orientation = WEST;
	exit[19].origin = &room[4];
	exit[19].destiny = &room[3];
	//--------------------------------------------------------------------
	room[5].name="Cinema";
	room[5].descrip="If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house.";
	//--------------------------------------------------------------------
	exit[20].descrip="There's a wall";
	exit[20].origin = &room[5];
	exit[20].destiny = &room[5];
	exit[20].orientation = EAST;

	exit[21].descrip="There's a wall";
	exit[21].orientation = NORTH;
	exit[21].origin = &room[5];
	exit[21].destiny = &room[5];

	exit[22].name="Hobby street";
	exit[22].descrip="In the south there is the park";
	exit[22].orientation = SOUTH;
	exit[22].origin = &room[5];
	exit[22].destiny = &room[6];

	exit[23].name="Elisenda street";
	exit[23].descrip="In the south there is the shop";
	exit[23].orientation = WEST;
	exit[23].origin = &room[5];
	exit[23].destiny = &room[4];

	//--------------------------------------------------------------------
	room[6].name="Park";
	room[6].descrip="Oh no! There is a thug take care!";
	//--------------------------------------------------------------------
	exit[24].name="Residencial Street";
	exit[24].descrip, "In the east there is the house 3";
	exit[24].origin = &room[6];
	exit[24].destiny = &room[7];
	exit[24].orientation = EAST;
	
	exit[25].name="Hobby street";
	exit[25].descrip="In the north there is the cinema";
	exit[25].orientation = NORTH;
	exit[25].origin = &room[6];
	exit[25].destiny = &room[5];
	
	exit[26].descrip="There's a wall";

	exit[26].orientation = SOUTH;
	exit[26].origin = &room[6];
	exit[26].destiny = &room[6];


	exit[27].descrip="There's a wall";
	exit[27].orientation = WEST;
	exit[27].origin = &room[6];
	exit[27].destiny = &room[6];
	
	//--------------------------------------------------------------------
	room[7].name="House 3";
	room[7].descrip="Its seems that there is something important...";
	//--------------------------------------------------------------------
	exit[28].name="Residencial Street";
	exit[28].descrip="In the east there is the goal";
	exit[28].origin = &room[7];
	exit[28].destiny = &room[8];
	exit[28].orientation = EAST;
	exit[28].door = true;
	exit[28].closed = true;

	exit[29].descrip="There's a wall";
	exit[29].orientation = NORTH;
	exit[29].origin = &room[7];
	exit[29].destiny = &room[7];

	exit[30].descrip="There's a wall";
	exit[30].orientation = SOUTH;
	exit[30].origin = &room[7];
	exit[30].destiny = &room[7];

	exit[31].name="Residencial Street";
	exit[31].descrip="In the east there is the park";
	exit[31].orientation = WEST;
	exit[31].origin = &room[7];
	exit[31].destiny = &room[6];
	//--------------------------------------------------------------------
	room[8].name= "Finish";
	room[8].descrip="You finish the game";
	//--------------------------------------------------------------------
	exit[32].descrip="There's a wall";
	exit[32].origin = &room[8];
	exit[32].destiny = &room[8];
	exit[32].orientation = EAST;

	exit[33].descrip="There's a wall";
	exit[33].orientation = NORTH;
	exit[33].origin = &room[8];
	exit[33].destiny = &room[8];

	exit[34].descrip="There's a wall";
	exit[34].orientation = SOUTH;
	exit[34].origin = &room[8];
	exit[34].destiny = &room[8];

	exit[35].name="Residencial Street";
	exit[35].descrip="In the west there's house 3";
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
	char direction1[30];
	help();
	do{
		player->playerposit = &room[roompos];
		printf("Where do you want to go?\n");
		fflush(stdin);
		direction->set();

		fflush(stdin);
		if (*direction == "go"){
			printf("Which direction?");
			direction->set();
			fflush(stdin);
		}
		system("cls");
		//-------------------------------------------------------------------------------------------------------------North
		if (*direction == "n" || *direction == "north" || *direction == "go north"){
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
									printf("%s\n", exit[i].name.C_Str());
									printf("%s\n", room[j].name.C_Str());
									printf("%s\n", room[j].descrip.C_Str());
									//player->playerposit = &room[j]
									roompos = j;
									break;
								

								}
							}
						}
					}break;
				}
			}
		}
		//----------------------------------------------------------------------------------------------------------------West
		if (*direction == "w" || *direction == "west" || *direction == "go west"){
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
									printf("%s\n", exit[i].name.C_Str());
									printf("%s\n", room[j].name.C_Str());
									printf("%s\n", room[j].descrip.C_Str());
									//player->playerposit = &room[j]
									roompos = j;
									//break;
									
								}
							}
						}
					}break;
				}
			}
		}
		//----------------------------------------------------------------------------------------------------------------South
		if (*direction == "s" || *direction == "south" || *direction == "go south"){
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
									printf("%s\n", exit[i].name.C_Str());
									printf("%s\n", room[j].name.C_Str());
									printf("%s\n", room[j].descrip.C_Str());
									//player->playerposit = &room[j]
									roompos = j;
									break;
					
								}
							}
						}
					}break;
				}
			}
		}
		//-----------------------------------------------------------------------------------------------------------------East
		if (*direction == "e" || *direction == "east" || *direction == "go east"){
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
									printf("%s\n", exit[i].name.C_Str());
									printf("%s\n", room[j].name.C_Str());
									printf("%s\n", room[j].descrip.C_Str());
									//player->playerposit = &room[j]
									roompos = j;
									break;
								}
							}
						}
					}break;
				}
			}
		}
		if (*direction == "h" || *direction == "help"){
			help();
		}

		if (*direction == "look" || *direction == "look north" || *direction == "look east" || *direction == "look west" || *direction == "look south"){
			look(direction, roompos);
		}


		if (*direction == "open" || *direction == "open north" || *direction == "open east" || *direction == "open west" || *direction == "open south"){
			if (*direction == "open"){
				printf("Which direction?\n");
				direction->set();
			}
			Open(direction);
		}

		if (*direction == "close" || *direction == "close north" || *direction == "close east" || *direction == "close west" || *direction == "close south"){
			if (*direction == "close"){
				printf("Which direction?\n");
				direction->set();
			}
			Close(direction);
		}

		if (*direction == "pick" || *direction == "pick ladder" || *direction == "pick wrench" || *direction == "pick money" || *direction == "pick ticket" || *direction == "pick key" || *direction == "pick map"){
			
			pick(direction);
		}

		if (*direction == "inventory" || *direction == "look inventory"){
			inventory();
		}

		if (*direction == "drop" || *direction == "drop ladder" || *direction == "drop wrench" || *direction == "drop money" || *direction == "drop ticket" || *direction == "drop key" || *direction == "drop map"){

			drop(direction);
		}

	} while (*direction != "q");
}


		void World::help()const{

			printf("You are lost in the city and you have to find your new house.\n You can move arround the map using ONLY lowercase.\n You can use to move: n, e, s, w or north, east, south, west, also go north, go south, go west, go east.\n There will be doors in the map you can open and close some them using open and to close use the word close.\n You can look what is in the room you are and int his directions\n There is only a door you have to open and close that now you can but in nexts Zorks you will need a key\n");


		}
		void World::look(const mystring *looks, int numroom)const{
			int exitnum=0;//count
			if (*looks=="look"){//if the user only says look
				printf("%s\n", room[numroom].descrip.C_Str());
			}

			if (*looks=="look north"){//if the user says look north
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum].orientation == NORTH)//exits with north orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum].descrip.C_Str());
						}

					}
				}
			}
			if (*looks == "look west"){//if the user says look west
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum].orientation == WEST)//exits with west orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum].descrip.C_Str());
						}
					}
				}
				//printf("%s\n", exit[numexit].descrip);
			}

			if (*looks == "look south"){//if the user says look south
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum].orientation == SOUTH)//exits with south orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum].descrip.C_Str());
						}
					}
				}
			}

			if (*looks == "look east"){//if the user says look east
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum].orientation == EAST)//exits with east orientation
					{
						if (exit[exitnum].origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s", exit[exitnum].descrip.C_Str());
						}
					}
				}
			}


		}

		

		void World::Open(mystring *direction)
		{

			int i, j;
			if (*direction == "open north" || *direction == "open n" || *direction == "north")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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


			if (*direction == "open west" || *direction == "w" || *direction == "west")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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


			if (*direction == "open east" || *direction == "open e" || *direction == "east")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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


			if (*direction == "open south" || *direction == "open s" || *direction == "south")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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

		void World::Close(mystring* direction)
		{

			int i, j;
			if (*direction == "close north" || *direction == "close n" || *direction == "north")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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

			if (*direction == "close west" || *direction == "close w" || *direction == "west")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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


			if (*direction == "close east" || *direction == "close e" || *direction == "east")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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


			if (*direction == "close south" || *direction == "close s" || *direction == "south")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i].origin->name==player->playerposit->name){
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