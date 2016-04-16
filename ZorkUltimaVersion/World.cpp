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
	room.pushback(new Room("School", "There's a girl and she want to talk with you. Here you have a box."));
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
	exit.pushback(new Exit("Joan Oliver street", "In the south there is the house 2", SOUTH, room[2], room[3], true, true));
	//exit 11
	exit.pushback(new Exit("Student Street", "In the west there is the house 1", WEST, room[2], room[1], false, false));
	
	//----------------------------------------------
	//--------------------------------------------------------------------
	//exit 12
	exit.pushback(new Exit("Verdi street", "In the east there is the shop", EAST, room[3], room[4], false, false));
	//exit 13
	exit.pushback(new Exit("Joan Oliver street", "In the north there is the school", NORTH, room[3], room[2], true, true));
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
	//exit 35
	exit.pushback(new Exit("Residencial Street", "In the west there's house 3", WEST, room[8], room[7], true, true));

	//ITEMS---------------------------------------------
	//item 0
	items.pushback(new Item("ladder", "A ladder that you can use it to pass walls", room[1], false, false, false));

	//-------
	//item 1
	items.pushback(new Item("wrench", "You can use the wrench to fight if you have problems", room[3], false, false, false));
	
	//-------
	//item 2
	items.pushback(new Item("money", "With this money you can buy somthing", room[4], false, false, false));
	
	//-------
	//item 3
	items.pushback(new Item("ticket", "If you have this ticket means that you have some information about house 3", room[5], false, false, false));

	//-------
	//item 4
	items.pushback(new Item("key", "With this key you can enter to your house!!", room[7], false, false, false));
	
	//-------
	//item 5
	items.pushback(new Item("map", "With this special feature if you press you can see the map of the city", room[2], false, false, false));
	
	//-------
	//item 6
	items.pushback(new Item("box", "A box that you find in school and you can put and get things", room[2], false, false, false));

}

void World::movement(){
	int roompos = 0;
	int i = 0, j = 0;
	int x = 0;
	//Vector<Player*> player;
	/*char direction1[50];
	gets_s(direction1, 50);
	//printf("%s", direction1);
	mystring command;

	Vector<mystring> option = command.Tokenize(" ", direction1);
	for (uint t = 0; t < option.size(); t++){
		printf("%s\n", option[t].C_Str());
	}*/

	help();
	
	//}
		
	
	do{
		player->playerposit = room[roompos];
		update();
		itemsroom();
		printf("Where do you want to go?\n");
		char direction1[50];
		gets_s(direction1, 50);
		mystring command;

		Vector<mystring> option = command.Tokenize(" ", direction1);

	
		system("cls");
		//-------------------------------------------------------------------------------------------------------------North
		if (option[0] == "go" && option[1] == "north" || option[0] == "go" && option[1] == "n" || option[0] == "n" || option[0] == "north"){
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
		if (option[0] == "go" && option[1] == "west" || option[0] == "go" && option[1] == "w" || option[0] == "w" || option[0] == "west"){
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
		if (option[0] == "go" && option[1] == "south" || option[0] == "go" && option[1] == "s" || option[0] == "s" || option[0] == "south")
			{
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
									if (player->playerposit == room[2]){
										printf("There's a wall you have to pas");
									}
									else{
										printf("There's a door");
									}
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
		if (option[0] == "go" && option[1] == "east" || option[0] == "go" && option[1] == "e" || option[0] == "e" || option[0] == "east")
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
		if (option[0] == "h" || option[0] == "help"){
			help();
		}

		if (option[0] == "look" && option[1] == "north" || option[0] == "look" && option[1] == "east" || option[0] == "look" && option[1] == "west" || option[0] == "look" && option[1] == "south"){
			look(option, roompos);
		}


		if (option[0] == "open" && option[1] == "north" || option[0] == "open" && option[1] == "east" || option[0] == "open" && option[1] == "west" || option[0] == "open" && option[1] == "south"){
			Open(option);
		}

		if (option[0] == "close" && option[1] == "north" || option[0] == "close" && option[1] == "east" || option[0] == "close" && option[1] == "west" || option[0] == "close" && option[1] == "south"){
			Close(option);
		}
		if (option[0] == "inventory" || option[0] == "look" && option[1] == "inventory"){
			inventory();
		}
		if (option.size() > 1){
			if (option[0] == "pick" && option[1] == "ladder" || option[0] == "pick" && option[1] == "wrench" || option[0] == "pick" && option[1] == "money" || option[0] == "pick" && option[1] == "ticket" || option[0] == "pick" && option[1] == "key" || option[0] == "pick" && option[1] == "map" || option[0] == "pick" && option[1] == "box"){

				pick(option);
			}

			if (option[0] == "drop" && option[1] == "ladder" || option[0] == "drop" && option[1] == "wrench" || option[0] == "drop" && option[1] == "money" || option[0] == "drop" && option[1] == "ticket" || option[0] == "drop" && option[1] == "key" || option[0] == "drop" && option[1] == "map" || option[0] == "pick" && option[1] == "box"){

				drop(option);
			}

			if (option[0] == "equip" && option[1] == "ladder" || option[0] == "equip" && option[1] == "wrench" || option[0] == "equip" && option[1] == "money" || option[0] == "equip" && option[1] == "ticket" || option[0] == "equip" && option[1] == "key" || option[0] == "equip" && option[1] == "map"){

				equip(option);
			}

			if (option[0] == "unequip" && option[1] == "ladder" || option[0] == "unequip" && option[1] == "wrench" || option[0] == "unequip" && option[1] == "money" || option[0] == "unequip" && option[1] == "ticket" || option[0] == "unequip" && option[1] == "key" || option[0] == "unequip" && option[1] == "map"){

				unequip(option);
			}

			if (option[0] == "put" && option[1] == "ladder" || option[0] == "put" && option[1] == "wrench" || option[0] == "put" && option[1] == "money" || option[0] == "put" && option[1] == "ticket" || option[0] == "put" && option[1] == "key" || option[0] == "put" && option[1] == "map" || option[0] == "put" && option[1] == "box"){

				put(option);
			}

			if (option[0] == "get" && option[1] == "ladder" || option[0] == "get" && option[1] == "wrench" || option[0] == "get" && option[1] == "money" || option[0] == "get" && option[1] == "ticket" || option[0] == "get" && option[1] == "key" || option[0] == "get" && option[1] == "map" || option[0] == "get" && option[1] == "box"){

				get(option);
			}
		}

	} while (*direction != "q");
}


		void World::help()const{

			printf("You are lost in the city and you have to find your new house.\n You can move arround the map using ONLY lowercase.\n You can use to move: n, e, s, w or north, east, south, west, also go north, go south, go west, go east.\n There will be doors in the map you can open and close some them using open and to close use the word close.\n You can look what is in the room you are and int his directions\n There is only a door you have to open and close that now you can but in nexts Zorks you will need a key\n");


		}
		
		void World::look(Vector<mystring>& options, int numroom){
			int exitnum=0;//count

			if (options[0] == "look" && options[1] == "north"){//if the user says look north
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
			if (options[0] == "look" && options[1] == "west"){//if the user says look west
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

			if (options[0] == "look" && options[1] == "south"){//if the user says look south
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

			if (options[0] == "look" && options[1] == "east"){//if the user says look east
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

		

		void World::Open(Vector<mystring>& options)
		{

			int i, j;
			if (options[0] == "open" && options[1] == "north" || options[0] == "open" && options[1] == "n" || options[0] == "n" || options[0] == "north")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == NORTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == SOUTH && exit[j]->door == true){
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


			if (options[0] == "open" && options[1] == "west" || options[0] == "open" && options[1] == "w" || options[0] == "w" || options[0] == "west")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == WEST){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == EAST && exit[j]->door == true){
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


			if (options[0] == "open" && options[1] == "east" || options[0] == "open" && options[1] == "e" || options[0] == "e" || options[0] == "east")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == EAST){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == WEST && exit[j]->door == true){
											if (exit[j]->destiny->name == exit[i]->origin->name){
												exit[j]->closed = false;
												printf("The door is opened.\n");
												break;
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


			if (options[0] == "open" && options[1] == "south" || options[0] == "open" && options[1] == "s" || options[0] == "s" || options[0] == "south")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin == player->playerposit){
						if (exit[i]->orientation == SOUTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == true){
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == NORTH && exit[j]->door== true){
 											if (exit[j]->destiny == player->playerposit){
												exit[j]->closed = false;
												printf("The door is opened.\n");
												break;
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

		void World::Close(Vector<mystring>& options)
		{

			int i, j;
			if (options[0] == "close" && options[1] == "north" || options[0] == "close" && options[1] == "n" || options[0] == "n" || options[0] == "north")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == NORTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == SOUTH && exit[j]->door == true && exit[j]->closed == false){
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

			if (options[0] == "close" && options[1] == "west" || options[0] == "close" && options[1] == "w" || options[0] == "w" || options[0] == "west")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == WEST){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == EAST){
											if (exit[j]->destiny->name == exit[i]->origin->name && exit[j]->door == true && exit[j]->closed == false){
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


			if (options[0] == "close" && options[1] == "east" || options[0] == "close" && options[1] == "e" || options[0] == "e" || options[0] == "east")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == EAST){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = WEST){
											if (exit[j]->destiny->name == exit[i]->origin->name && exit[j]->door == true && exit[j]->closed == false){
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


			if (options[0] == "close" && options[1] == "south" || options[0] == "close" && options[1] == "s" || options[0] == "s" || options[0] == "south")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){
						if (exit[i]->orientation == SOUTH){
							if (exit[i]->door == true){
								if (exit[i]->closed == false){
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = NORTH){
											if (exit[j]->destiny->name == exit[i]->origin->name && exit[j]->door == true && exit[j]->closed == false){
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

		void World::pick(Vector<mystring>& options){
			int maximum = 0;
			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[i]->name && items[i]->itempos == player->playerposit && items[i]->inventory == false && items[i]->equipped == false && items[i]->inbox == false){
						items[i]->inventory = true;
						printf("%s\n %s\n", items[i]->name.C_Str(), items[i]->descrip.C_Str());
						//items[i]->maximum++;
						break;
					}
				/*if (items[i]->itempos != player->playerposit){
					printf("This item isn't here");
				}*/
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

		void World::drop(Vector<mystring>& options){

			int maximum = 0;
		if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[i]->name && items[i]->itempos == player->playerposit && items[i]->inventory == true){
						items[i]->inventory = false;

						printf("You have droped %s\n", items[i]->name.C_Str());
						break;
					}
				/*if (items[i]->itempos != player->playerposit){
					printf("This item isn't here");
				}*/
				}
			}
		}

		void World::equip(Vector<mystring>& options){

			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (items[i]->equipped == false /*&& items[i]->nequip < items[i]->maxequipped*/ && items[i]->inventory == true){
						items[i]->equipped = true;
						printf("You have equiped %s\n", items[i]->name.C_Str());
						break;
					}
				/*if (items[i]->inventory != true){
					printf("You don't have this item in the inventary");
				}*/
				}
			}
		}		

		void World::unequip(Vector<mystring>& options){
			
			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (items[i]->equipped == true /*&& items[i]->nequip < items[i]->maxequipped*/ && items[i]->inventory == true){
						items[i]->equipped = false;
						printf("You have unequiped %s\n", items[i]->name.C_Str());
						//items[i]->maximum++;
						break;
					}
				
				/*if (items[i]->inventory != true){
					printf("You don't have this item in the inventary");
				}*/
				}
			}
		}

		

		void World::update(){
			for (int i = 0; i < NUM_ITEM; i++){
				if (items[i]->inventory == true){
					items[i]->itempos = player->playerposit;
				}
				if (items[i]->inbox == true){
					items[i]->itempos = items[BOX]->itempos;
				}
			}
		}
	
		void World::itemsroom(){
			int j = 0, i = 0;
			for (j = 0; j < NUM_ITEM; j++){
				if ((items[j]->itempos == player->playerposit) && items[j]->inventory == false){
					i++;
				}
			}
			if (i != 0){
				for (j = 0; j < NUM_ITEM; j++){
					if ((items[j]->itempos == player->playerposit) && items[j]->inventory == false){
						printf("\nIn this room there is: %s\n", items[j]->name.C_Str());
					}
				}
			}
		}

		void World::put(Vector<mystring>& options){
			int maximum = 0;
			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[i]->name && items[i]->itempos == player->playerposit && items[i]->itempos == items[BOX]->itempos && items[i]->inbox == false){
						items[i]->inventory = false;
						items[i]->inbox = true;
						items[i]->itempos = items[BOX]->itempos;
						printf("You have put %s into the box", items[i]->name.C_Str());
						//items[i]->maximum++;
						break;
					}
					/*if (items[i]->itempos != player->playerposit){
					printf("This item isn't here");
					}*/
				}
			}

		
		}

		void World::get(Vector<mystring>& options){
			int maximum = 0;
			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[i]->name && items[i]->itempos == items[BOX]->itempos && items[i]->inbox == true){
						items[i]->inbox = false;
						items[i]->inventory = true;
						printf("You have get %s of the box", items[i]->name.C_Str());
						//items[i]->maximum++;
						break;
					}
					/*if (items[i]->itempos != player->playerposit){
					printf("This item isn't here");
					}*/
				}
			}


		}

