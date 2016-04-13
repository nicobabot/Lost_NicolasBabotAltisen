#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
#include"MyString.h"
#include"Vector.h"
#include"Entity.h"


World::World(){
	player = new Player;//player
	//room = new Room[ROOMNUM];//9 rooms
	//exit = new Exit[EXITNUM];//33 exits
	direction = new mystring;
	//items = new Item[NUM_ITEM];
}
World::~World(){
	//delete[] room;//free memory
	//delete[] exit;//free memory
	delete player;//free memory
	delete direction;
//	delete[] items;
}

void World::createworld(){
	//room 0
	room.pushback(new Room("Entrance of the city", "You are in the entrance of the city and you have to find your house."));
	//--------------------------------------------------------------------
	//room 1
	room.pushback(new Room("House 1", "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house."));
	//room 2
	room.pushback(new Room("School", "There's a girl and she want to talk with you."));
	//room 3
	room.pushback(new Room("House 2", "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone."));
	//room 4
	room.pushback(new Room("Shop", "The seller gives you money because he is sad because you are lost."));
	//room 5
	room.pushback(new Room("Cinema", "If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house."));
	//room 6
	room.pushback(new Room("Park", "Oh no! There is a thug take care!"));
	//room 7
	room.pushback(new Room("House 3", "Its seems that there is something important..."));
	//room 8
	room.pushback(new Room("Finish", "You finish the game"));






	
	//exit 0
	exit.pushback(new Exit("Main street", "In the east there is the house 1", EAST, room[0], room[1], false, false));
	//exit 1
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[0], room[0], false, false));
	//exit 2
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[0], room[0], false, false));
	//exit 3
	exit.pushback(new Exit("There's a wall", "There's a wall", WEST, room[0], room[0], false, false));
	//--------------------------------------------------------------------
	//exit 4
	exit.pushback(new Exit("Studiant Street", "In the east there is the school", EAST, room[1], room[2], false, false));
	//exit 5
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[1], room[1], false, false));
	//exit 6
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[1], room[1], false, false));
	//exit 7
	exit.pushback(new Exit("Main street", "In the west there is the entrance of the city", WEST, room[1], room[0], false, false));


	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	
	//exit 8
	exit.pushback(new Exit("There's a wall", "There's a wall", EAST, room[2], room[2], false, false));
	//exit 9
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[2], room[2], false, false));
	//exit 10
	exit.pushback(new Exit("Joan Oliver street", "In the south there is the house 2", SOUTH, room[2], room[3], false, false));
	//exit 11
	exit.pushback(new Exit("Student Street", "In the west there is the house 1", WEST, room[2], room[1], false, false));
	
	//----------------------------------------------
	//--------------------------------------------------------------------
	//exit 12
	exit.pushback(new Exit("Verdi street", "In the east there is the shop", EAST, room[3], room[4], false, false));
	//exit 13
	exit.pushback(new Exit("Joan Oliver street", "In the north there is the school", NORTH, room[3], room[2], false, false));
	//exit 14
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[3], room[3], false, false));
	//exit 15
	exit.pushback(new Exit("There's a wall", "There's a wall", WEST, room[3], room[3], false, false));
	
	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 16
	exit.pushback(new Exit("Elisenda street", "In the east there is the cinema", EAST, room[4], room[5], false, false));
	//exit 17
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[4], room[4], false, false));
	//exit 18
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[4], room[4], false, false));
	//exit 19
	exit.pushback(new Exit("Verdi street", "In the east there is the house 2", WEST, room[4], room[3], false, false));
	
	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 20
	exit.pushback(new Exit("There's a wall", "There's a wall", EAST, room[5], room[5], false, false));
	//exit 21
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[5], room[5], false, false));
	//exit 22
	exit.pushback(new Exit("Hobby street", "In the south there is the park", SOUTH, room[5], room[6], false, false));
	//exit 23
	exit.pushback(new Exit("Elisenda street", "In the south there is the shop", WEST, room[5], room[4], false, false));

	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 24
	exit.pushback(new Exit("Residencial Street", "In the east there is the house 3", EAST, room[6], room[7], false, false));
	//exit 25
	exit.pushback(new Exit("Hobby street", "In the north there is the cinema", NORTH, room[6], room[5], false, false));
	//exit 26
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[6], room[6], false, false));
	//exit 27
	exit.pushback(new Exit("There's a wall", "There's a wall", WEST, room[6], room[6], false, false));
	
	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 28
	exit.pushback(new Exit("Residencial Street", "In the east there is the goal", EAST, room[7], room[8], true, true));
	//exit 29
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[7], room[7], false, false));
	//exit 30
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[7], room[7], false, false));
	//exit 31
	exit.pushback(new Exit("Residencial Street", "In the east there is the park", WEST, room[7], room[6], false, false));

	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 32
	exit.pushback(new Exit("There's a wall", "There's a wall", EAST, room[8], room[8], false, false));
	//exit 33
	exit.pushback(new Exit("There's a wall", "There's a wall", NORTH, room[8], room[8], false, false));
	//exit 34
	exit.pushback(new Exit("There's a wall", "There's a wall", SOUTH, room[8], room[8], false, false));
	//exit 32
	exit.pushback(new Exit("Residencial Street", "In the west there's house 3", WEST, room[8], room[7], true, true));

	//ITEMS---------------------------------------------
	//item 1
	items.pushback(new Item("Ladder", "A ladder that you can use it to pass walls", room[1], false, false));

	//-------
	//item 2
	items.pushback(new Item("Wrench", "You can use the wrench to fight if you have problems", room[3], false, false));
	
	//-------
	//item 3
	items.pushback(new Item("Money", "With this money you can buy somthing", room[4], false, false));
	
	//-------
	//item 4
	items.pushback(new Item("Ticket", "If you have this ticket means that you have some information about house 3", room[5], false, false));

	//-------
	//item 5
	items.pushback(new Item("Key", "With this key you can enter to your house!!", room[7], false, false));
	
	//-------
	//item 6
	items.pushback(new Item("Map", "With this special feature if you press you can see the map of the city", room[2], false, false));
	
}

void World::movement(){
	int roompos = 0;
	int i = 0, j = 0;
	int x = 0;
	//Vector<Player*> player;
	char direction1[30];
	help();
	for (i = 0; i < ROOMNUM; i++){
		printf("%s\n", room[i]->name.C_Str());
	}
	//for (i = 0; i < EXITNUM; i++){
		printf("%s\n", exit[0]->destiny->name.C_Str());
	//}
		
	
	do{
		player->playerposit = room[roompos];
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
				if (player->playerposit == exit[i]->origin && exit[i]->orientation == NORTH){
					if (exit[i]->origin == exit[i]->destiny){
						printf("There's a wall");
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i]->destiny == room[j]){
							if (exit[i]->origin == exit[i]->destiny){
								printf("%s", exit[i]->descrip);
								break;
							}
							else{
								if (exit[i]->door == true && exit[i]->closed == true){
									printf("There's a door");

									break;
								}
								else{
									printf("%s\n", exit[i]->name.C_Str());
									printf("%s\n", room[j]->name.C_Str());
									printf("%s\n", room[j]->descrip.C_Str());
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
				if (player->playerposit == exit[i]->origin && exit[i]->orientation == WEST){
					if (exit[i]->origin == exit[i]->destiny){
						printf("There's a wall");
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i]->destiny == room[j]){
							if (exit[i]->origin == exit[i]->destiny){
								printf("%s", exit[i]->descrip);
								break;
							}
							else{
								if (exit[i]->door == true && exit[i]->closed == true){
									printf("There's a door");
									break;
								}
								else{
									printf("%s\n", exit[i]->name.C_Str());
									printf("%s\n", room[j]->name.C_Str());
									printf("%s\n", room[j]->descrip.C_Str());
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
				if (player->playerposit == exit[i]->origin && exit[i]->orientation == SOUTH){
					if (exit[i]->origin == exit[i]->destiny){
						printf("There's a wall");
						break;
					}
					for (j = 0; j< ROOMNUM; j++){
						if (exit[i]->destiny == room[j]){
							if (exit[i]->origin == exit[i]->destiny){
								printf("%s", exit[i]->descrip);
								break;
							}
							else{
								if (exit[i]->door == true && exit[i]->closed == true){
									printf("There's a door");
									break;
								}
								else{
									printf("%s\n", exit[i]->name.C_Str());
									printf("%s\n", room[j]->name.C_Str());
									printf("%s\n", room[j]->descrip.C_Str());
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
		if (*direction == "e" || *direction == "east" || *direction == "go east")
		{
			for (i = 0; i < EXITNUM; i++)
			{
				if (player->playerposit == exit[i]->origin && exit[i]->orientation == EAST)
				{
					if (exit[i]->origin == exit[i]->destiny)
					{
						printf("%s", exit[i]->descrip);
						break;
					}
					for (j = 0; j< ROOMNUM; j++)
					{
						if (exit[i]->destiny == room[j])
						{
							if (exit[i]->origin == exit[i]->destiny)
							{
								printf("%s", exit[i]->descrip.C_Str());
								break;
							}
							else
							{
								if (exit[i]->door == true && exit[i]->closed == true)
								{
									printf("There's a door");
									break;
								}
								else
								{
									printf("%s\n", exit[i]->name.C_Str());
									printf("%s\n", room[j]->name.C_Str());
									printf("%s\n", room[j]->descrip.C_Str());
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

		/*if (*direction == "look" || *direction == "look north" || *direction == "look east" || *direction == "look west" || *direction == "look south"){
			look(direction, roompos);
		}*/


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

		if (*direction == "equip" || *direction == "equip ladder" || *direction == "equip wrench" || *direction == "equip money" || *direction == "equip ticket" || *direction == "equip key" || *direction == "equip map"){

			equip(direction);
		}

		if (*direction == "unequip" || *direction == "unequip ladder" || *direction == "unequip wrench" || *direction == "unequip money" || *direction == "unequip ticket" || *direction == "unequip key" || *direction == "unequip map"){

			unequip(direction);
		}

	} while (*direction != "q");
}


		void World::help()const{

			printf("You are lost in the city and you have to find your new house.\n You can move arround the map using ONLY lowercase.\n You can use to move: n, e, s, w or north, east, south, west, also go north, go south, go west, go east.\n There will be doors in the map you can open and close some them using open and to close use the word close.\n You can look what is in the room you are and int his directions\n There is only a door you have to open and close that now you can but in nexts Zorks you will need a key\n");


		}
		
		void World::look(const mystring *looks, int numroom){
			int exitnum=0;//count
			if (*looks=="look"){//if the user only says look
				printf("%s\n", room[numroom]->descrip.C_Str());
			}

			if (*looks=="look north"){//if the user says look north
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum]->orientation == NORTH)//exits with north orientation
					{
						if (exit[exitnum]->origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum]->descrip.C_Str());
						}

					}
				}
			}
			if (*looks == "look west"){//if the user says look west
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum]->orientation == WEST)//exits with west orientation
					{
						if (exit[exitnum]->origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum]->descrip.C_Str());
						}
					}
				}
				//printf("%s\n", exit[numexit].descrip);
			}

			if (*looks == "look south"){//if the user says look south
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum]->orientation == SOUTH)//exits with south orientation
					{
						if (exit[exitnum]->origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s\n", exit[exitnum]->descrip.C_Str());
						}
					}
				}
			}

			if (*looks == "look east"){//if the user says look east
				for (exitnum = 0; exitnum < EXITNUM; exitnum++)
				{
					if (exit[exitnum]->orientation == EAST)//exits with east orientation
					{
						if (exit[exitnum]->origin == player->playerposit)//if origin and the player have the same direction
						{
							printf("%s", exit[exitnum]->descrip.C_Str());
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == NORTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == SOUTH){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = false;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == WEST){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == EAST){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = false;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == EAST){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == WEST){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = false;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == SOUTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == NORTH){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = false;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == NORTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = SOUTH){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed == true;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == WEST){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == EAST){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = true;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == EAST){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = WEST){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = true;
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
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == SOUTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = NORTH){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = true;
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

		void World::pick(mystring* string){
			int maximum = 0;
			if (*string == "pick"){
				printf("what do you want to pick?\n");
				string->set();
			}
			if (*string == "pick ladder" || *string == "ladder"){
				if (items[LADDER]->itempos != player->playerposit){
					printf("This object isn't in this room\n");
				}
				if (items[LADDER]->itempos == player->playerposit){
					if (items[LADDER]->inventory == false && items[LADDER]->maximum<items[LADDER]->maxinventory){
						items[LADDER]->inventory = true;
						printf("%s\n %s\n", items[LADDER]->name.C_Str(), items[LADDER]->descrip.C_Str());
						items[LADDER]->maximum++;
					}
					else{
						if (items[LADDER]->maximum == 3){
							printf("You have full inventory, you should drop some object\n");
						}
						if (items[LADDER]->inventory == true){
							printf("You already have it in your inventory\n");
						}
					}
				}

			}
			if (*string == "pick wrench" || *string == "wrench"){
				if (items[WRENCH]->itempos != player->playerposit){
					printf("This object isn't in this room\n");
				}
				if (items[WRENCH]->itempos == player->playerposit){
					if (items[WRENCH]->inventory == false && items[WRENCH]->maximum<items[WRENCH]->maxinventory){
						items[WRENCH]->inventory = true;
						printf("%s\n %s\n", items[WRENCH]->name.C_Str(), items[WRENCH]->descrip.C_Str());
						items[WRENCH]->maximum++;
					}
					else{
						if (items[WRENCH]->maximum == 3){
							printf("You have full inventory, you should drop some object\n");
						}
						if (items[WRENCH]->inventory == true){
							printf("You already have it in your inventory\n");
						}
					}
				}
			}
			if (*string == "pick money" || *string == "money"){
				if (items[MONEY]->itempos != player->playerposit){
					printf("This object isn't in this room\n");
				}
				if (items[MONEY]->itempos == player->playerposit){
					if (items[MONEY]->inventory == false && items[MONEY]->maximum<items[MONEY]->maxinventory){
						items[MONEY]->inventory = true;
						printf("%s\n %s\n", items[MONEY]->name.C_Str(), items[MONEY]->descrip.C_Str());
						items[MONEY]->maximum++;
					}
					else{
						if (items[MONEY]->maximum == 3){
							printf("You have full inventory, you should drop some object\n");
						}
						if (items[MONEY]->inventory == true){
							printf("You already have it in your inventory\n");
						}
					}
				}
			}

			if (*string == "pick ticket" || *string == "ticket"){
				if (items[TICKET]->itempos != player->playerposit){
					printf("This object isn't in this room\n");
				}
				if (items[TICKET]->itempos == player->playerposit){
					if (items[TICKET]->inventory == false && items[TICKET]->maximum<items[TICKET]->maxinventory){
						items[TICKET]->inventory = true;
						printf("%s\n %s\n", items[TICKET]->name.C_Str(), items[TICKET]->descrip.C_Str());
						items[TICKET]->maximum++;
					}
					else{
						if (items[TICKET]->maximum == 3){
							printf("You have full inventory, you should drop some object\n");
						}
						if (items[TICKET]->inventory == true){
							printf("You already have it in your inventory\n");
						}
					}
				}
			}


			if (*string == "pick key" || *string == "key"){
				if (items[KEY]->itempos != player->playerposit){
					printf("This object isn't in this room\n");
				}
				if (items[KEY]->itempos == player->playerposit){
					if (items[KEY]->inventory == false && items[KEY]->maximum<items[KEY]->maxinventory){
						items[KEY]->inventory = true;
						printf("%s\n %s\n", items[KEY]->name.C_Str(), items[KEY]->descrip.C_Str());
						items[KEY]->maximum++;
					}
					else{
						if (items[KEY]->maximum == 3){
							printf("You have full inventory, you should drop some object\n");
						}
						if (items[KEY]->inventory == true){
							printf("You already have it in your inventory\n");
						}
					}
				}
			}


			if (*string == "pick map" || *string == "map"){
				if (items[MAP]->itempos != player->playerposit){
					printf("This object isn't in this room\n");
				}
				if (items[MAP]->itempos == player->playerposit){
					if (items[MAP]->inventory == false && items[MAP]->maximum<items[MAP]->maxinventory){
						items[MAP]->inventory = true;
						printf("%s\n %s\n", items[MAP]->name.C_Str(), items[MAP]->descrip.C_Str());
						items[MAP]->maximum++;
					}
					else{
						if (items[MAP]->maximum == 3){
							printf("You have full inventory, you should drop some object\n");
						}
						if (items[MAP]->inventory == true){
							printf("You already have it in your inventory\n");
						}
					}
				}
			}
		}

		void World::inventory(){
			int i;
			for (i = 0; i < NUM_ITEM; i++){
				if (items[i]->inventory == true){
					printf("You have in the inventory:");
					printf("%s\n", items[i]->name.C_Str());
				}
			}

		}

		void World::drop(mystring *string){

			int maximum = 0;
			if (*string == "drop"){
				printf("what do you want to drop?\n");
				string->set();
			}
			if (*string == "drop ladder" || *string == "ladder"){
				if (items[LADDER]->inventory == true){
					items[LADDER]->inventory = false;
					items[LADDER]->itempos = player->playerposit;
					printf("You have dropped the %s", items[LADDER]->name.C_Str());
					items[LADDER]->maximum--;
				}
				else{
					printf("You don't have this item in the inventary");
				}
			}

			if (*string == "drop wrench" || *string == "wrench"){
				if (items[WRENCH]->inventory == true){
					items[WRENCH]->inventory = false;
					items[WRENCH]->itempos = player->playerposit;
					printf("You have dropped the %s", items[WRENCH]->name.C_Str());
					items[WRENCH]->maximum--;
				}
				else{
					printf("You don't have this item in the inventary");
				}
			}

			if (*string == "drop money" || *string == "money"){
				if (items[MONEY]->inventory == true){
					items[MONEY]->inventory = false;
					items[MONEY]->itempos = player->playerposit;
					printf("You have dropped the %s", items[MONEY]->name.C_Str());
					items[MONEY]->maximum--;
				}
				else{
					printf("You don't have this item in the inventary");
				}
			}
			if (*string == "drop ticket" || *string == "ticket"){
				if (items[TICKET]->inventory == true){
					items[TICKET]->inventory = false;
					items[TICKET]->itempos = player->playerposit;
					printf("You have dropped the %s", items[TICKET]->name.C_Str());
					items[TICKET]->maximum--;
				}
				else{
					printf("You don't have this item in the inventary");
				}
			}

			if (*string == "drop key" || *string == "key"){
				if (items[KEY]->inventory == true){
					items[KEY]->inventory = false;
					items[KEY]->itempos = player->playerposit;
					printf("You have dropped the %s", items[KEY]->name.C_Str());
					items[KEY]->maximum--;
				}
				else{
					printf("You don't have this item in the inventary");
				}
			}
			if (*string == "drop map" || *string == "map"){
				if (items[MAP]->inventory == true){
					items[MAP]->inventory = false;
					items[MAP]->itempos = player->playerposit;
					printf("You have dropped the %s", items[MAP]->name.C_Str());
					items[MAP]->maximum--;
				}
				else{
					printf("You don't have this item in the inventary");
				}

			}
		}

		void World::equip(mystring *string){

			if (*string == "equip"){
				printf("what do you want to equip?\n");
				string->set();
			}

			if (*string == "equip ladder" || *string == "ladder"){

				if (items[LADDER]->inventory == false){
					printf("You don't have this item in the inventary");
				}

				if (items[LADDER]->equipped == true || items[LADDER]->nequip >= items[LADDER]->maxequipped){
					printf("You already have one object equipped");
				}

				if (items[LADDER]->equipped == false && items[LADDER]->nequip < items[LADDER]->maxequipped && items[LADDER]->inventory == true){
					items[LADDER]->equipped = true;
					items[LADDER]->nequip++;
					printf("You have equiped the %s", items[LADDER]->name.C_Str());
				}
			}
			if (*string == "equip wrench" || *string == "wrench"){

				if (items[WRENCH]->inventory == false){
					printf("You don't have this item in the inventary");
				}

				if (items[WRENCH]->equipped == true || items[WRENCH]->nequip >= items[WRENCH]->maxequipped){
					printf("You already have one object equipped");
				}

				if (items[WRENCH]->equipped == false && items[WRENCH]->nequip < items[WRENCH]->maxequipped && items[WRENCH]->inventory == true){
					items[WRENCH]->equipped = true;
					items[WRENCH]->nequip++;
					printf("You have equiped the %s", items[WRENCH]->name.C_Str());
				}
			}

			if (*string == "equip money" || *string == "money"){

				if (items[MONEY]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[MONEY]->equipped == true || items[MONEY]->nequip >= items[MONEY]->maxequipped){
					printf("You already have one object equipped");
				}
				if (items[MONEY]->equipped == false && items[MONEY]->nequip < items[MONEY]->maxequipped && items[MONEY]->inventory == true){
					items[MONEY]->equipped = true;
					items[MONEY]->nequip++;
					printf("You have equiped the %s", items[MONEY]->name.C_Str());
				}
			}


			if (*string == "equip ticket" || *string == "ticket"){

				if (items[TICKET]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[TICKET]->equipped == true || items[TICKET]->nequip >= items[TICKET]->maxequipped){
					printf("You already have one object equipped");
				}
				if (items[TICKET]->equipped == false && items[TICKET]->nequip < items[TICKET]->maxequipped && items[TICKET]->inventory == true){
					items[TICKET]->equipped = true;
					items[TICKET]->nequip++;
					printf("You have equiped the %s", items[TICKET]->name.C_Str());
				}
			}


			if (*string == "equip key" || *string == "key"){

				if (items[KEY]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[KEY]->equipped == true || items[KEY]->nequip >= items[KEY]->maxequipped){
					printf("You already have one object equipped");
				}
				if (items[KEY]->equipped == false && items[KEY]->nequip < items[KEY]->maxequipped && items[KEY]->inventory == true){
					items[KEY]->equipped = true;
					items[KEY]->nequip++;
					printf("You have equiped the %s", items[KEY]->name.C_Str());
				}
			}


			if (*string == "equip map" || *string == "map"){

				if (items[MAP]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[MAP]->equipped == true || items[MAP]->nequip >= items[MAP]->maxequipped){
					printf("You already have one object equipped");
				}
				if (items[MAP]->equipped == false && items[MAP]->nequip < items[MAP]->maxequipped && items[MAP]->inventory == true){
					items[MAP]->equipped = true;
					items[MAP]->nequip++;
					printf("You have equiped the %s", items[MAP]->name.C_Str());
				}
			}

		}

		void World::unequip(mystring *string){
			if (*string == "unequip"){
				printf("what do you want to unequip?\n");
				string->set();
			}

			if (*string == "unequip ladder" || *string == "ladder"){

				if (items[LADDER]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[LADDER]->equipped == false || items[LADDER]->nequip == 0){
					printf("You don't have any object equipped");
				}
				if (items[LADDER]->equipped == true && items[LADDER]->nequip >= items[LADDER]->maxequipped && items[LADDER]->inventory == true){
					items[LADDER]->equipped = false;
					items[LADDER]->nequip--;
					printf("You have unequiped the %s", items[LADDER]->name.C_Str());
				}
			}

			if (*string == "unequip wrench" || *string == "wrench"){

				if (items[WRENCH]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[WRENCH]->equipped == false || items[WRENCH]->nequip == 0){
					printf("You don't have any object equipped");
				}
				if (items[WRENCH]->equipped == true && items[WRENCH]->nequip >= items[WRENCH]->maxequipped && items[WRENCH]->inventory == true){
					items[WRENCH]->equipped = false;
					items[WRENCH]->nequip--;
					printf("You have unequiped the %s", items[WRENCH]->name.C_Str());
				}
			}

			if (*string == "unequip money" || *string == "money"){

				if (items[MONEY]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[MONEY]->equipped == false || items[MONEY]->nequip == 0){
					printf("You don't have any object equipped");
				}
				if (items[MONEY]->equipped == true && items[MONEY]->nequip >= items[MONEY]->maxequipped && items[MONEY]->inventory == true){
					items[MONEY]->equipped = false;
					items[MONEY]->nequip--;
					printf("You have unequiped the %s", items[MONEY]->name.C_Str());
				}
			}

			if (*string == "unequip ticket" || *string == "ticket"){

				if (items[TICKET]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[TICKET]->equipped == false || items[TICKET]->nequip == 0){
					printf("You don't have any object equipped");
				}
				if (items[TICKET]->equipped == true && items[TICKET]->nequip >= items[TICKET]->maxequipped && items[TICKET]->inventory == true){
					items[TICKET]->equipped = false;
					items[TICKET]->nequip--;
					printf("You have unequiped the %s", items[TICKET]->name.C_Str());
				}
			}

			if (*string == "unequip key" || *string == "key"){

				if (items[KEY]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[KEY]->equipped == false || items[KEY]->nequip == 0){
					printf("You don't have any object equipped");
				}
				if (items[KEY]->equipped == true && items[KEY]->nequip >= items[KEY]->maxequipped && items[KEY]->inventory == true){
					items[KEY]->equipped = false;
					items[KEY]->nequip--;
					printf("You have unequiped the %s", items[KEY]->name.C_Str());
				}
			}

			if (*string == "unequip map" || *string == "map"){

				if (items[MAP]->inventory == false){
					printf("You don't have this item in the inventary");
				}
				if (items[MAP]->equipped == false || items[MAP]->nequip == 0){
					printf("You don't have any object equipped");
				}
				if (items[MAP]->equipped == true && items[MAP]->nequip >= items[MAP]->maxequipped && items[MAP]->inventory == true){
					items[MAP]->equipped = false;
					items[MAP]->nequip--;
					printf("You have unequiped the %s", items[MAP]->name.C_Str());
				}
			}
		}

		