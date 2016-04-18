#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
#include"MyString.h"
#include"Vector.h"
#include"Entity.h"


World::World(){
	player = new Player;//player
}
World::~World(){
	for (int i = 0; i < EXITNUM; i++){
		delete exit[i];
	}
	for (int i = 0; i < ROOMNUM; i++){
		delete room[i];
	}
	for (int i = 0; i < NUM_ITEM; i++){
		delete items[i];
	}
	delete player;//free memory
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
	room.pushback(new Room("Finish", "You end the game"));






	
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

	help();	
	
	do{
		player->playerposit = room[roompos];
		update();
		itemsroom();
		if (player->playerposit == room[8]){
			//system("pause");
			return;
		}
		printf("\nWhere do you want to go?\n");
		char direction1[50];
		gets_s(direction1, 50);
		mystring command;

		Vector<mystring> option = command.Tokenize(" ", direction1);
		

			system("cls");
			//-------------------------------------------------------------------------------------------------------------North
			if (option.size() == 2 && option[0] == "go" && option[1] == "north" || option.size() == 2 && option[0] == "go" && option[1] == "n" || option.size() == 1 && option[0] == "n" || option.size() == 1 && option[0] == "north"){
				for (i = 0; i < EXITNUM; i++){
					if (player->playerposit == exit[i]->origin && exit[i]->orientation == NORTH){ //if the origin is the same position as the origin, also look the orientation
						if (exit[i]->origin == exit[i]->destiny){//if the origin and the destiny are the same there's a wall
							printf("\nThere's a wall");
							break;
						}
						for (j = 0; j < ROOMNUM; j++){
							if (exit[i]->destiny == room[j]){//if the destiny is the same position of the room
								if (exit[i]->origin == exit[i]->destiny){
									printf("%s", exit[i]->descrip);
									break;
								}
								else{
									if (exit[i]->door == true && exit[i]->closed == true){//if there's a door and if its closed
										printf("There's a door");

										break;
									}
									else{
										printf("%s\n", exit[i]->name.C_Str());//print the exit
										printf("%s\n", room[j]->name.C_Str());//print the room
										printf("%s\n", room[j]->descrip.C_Str());//print the description of the room
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
			else if (option.size() == 2 && option[0] == "go" && option[1] == "west" || option.size() == 2 && option[0] == "go" && option[1] == "w" || option.size() == 1 && option[0] == "w" || option.size() == 1 && option[0] == "west"){
				for (i = 0; i < EXITNUM; i++){
					if (player->playerposit == exit[i]->origin && exit[i]->orientation == WEST){//if the origin is the same position as the origin, also look the orientation
						if (exit[i]->origin == exit[i]->destiny){//if the origin and the destiny are the same there's a wall
							printf("There's a wall");
							break;
						}
						for (j = 0; j < ROOMNUM; j++){
							if (exit[i]->destiny == room[j]){//if the destiny is the same position of the room
								if (exit[i]->origin == exit[i]->destiny){
									printf("%s", exit[i]->descrip);
									break;
								}
								else{
									if (exit[i]->door == true && exit[i]->closed == true){//if there's a door and if its closed
										printf("There's a door");
										break;
									}
									else{
										printf("%s\n", exit[i]->name.C_Str());//print the exit
										printf("%s\n", room[j]->name.C_Str());//print the room
										printf("%s\n", room[j]->descrip.C_Str());//print the description of the room
										roompos = j;
										break;

									}
								}
							}
						}break;
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------South
			else if (option.size() == 2 && option[0] == "go" && option[1] == "south" || option.size() == 2 && option[0] == "go" && option[1] == "s" || option.size() == 1 && option[0] == "s" || option.size() == 1 && option[0] == "south")
			{
				for (i = 0; i < EXITNUM; i++){
					if (player->playerposit == exit[i]->origin && exit[i]->orientation == SOUTH){//if the origin is the same position as the origin, also look the orientation
						if (exit[i]->origin == exit[i]->destiny){//if the origin and the destiny are the same there's a wall
							printf("There's a wall");
							break;
						}
						for (j = 0; j < ROOMNUM; j++){
							if (exit[i]->destiny == room[j]){//if the destiny is the same position of the room
								if (exit[i]->origin == exit[i]->destiny){
									printf("%s", exit[i]->descrip);
									break;
								}
								else{
									if (exit[i]->door == true && exit[i]->closed == true){//if there's a door and if its closed
										if (player->playerposit == room[2]){
											printf("There's a wall you have to pass");
										}
										else{
											printf("There's a door");
										}
										break;
									}
									else{
										printf("%s\n", exit[i]->name.C_Str());//print the exit
										printf("%s\n", room[j]->name.C_Str());//print the room
										printf("%s\n", room[j]->descrip.C_Str());//print the description of the room
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
			else if (option.size() == 2 && option[0] == "go" && option[1] == "east" || option.size() == 2 && option[0] == "go" && option[1] == "e" || option.size() == 1 && option[0] == "e" || option.size() == 1 && option[0] == "east")
			{
				for (i = 0; i < EXITNUM; i++)
				{
					if (player->playerposit == exit[i]->origin && exit[i]->orientation == EAST)//if the origin is the same position as the origin, also look the orientation
					{
						if (exit[i]->origin == exit[i]->destiny)//if the origin and the destiny are the same there's a wall
						{
							printf("%s", exit[i]->descrip);
							break;
						}
						for (j = 0; j < ROOMNUM; j++)
						{
							if (exit[i]->destiny == room[j])//if the destiny is the same position of the room
							{
								if (exit[i]->origin == exit[i]->destiny)
								{
									printf("%s", exit[i]->descrip.C_Str());
									break;
								}
								else
								{
									if (exit[i]->door == true && exit[i]->closed == true)//if there's a door and if its closed
									{
										printf("There's a door");
										break;
									}
									else
									{
										printf("%s\n", exit[i]->name.C_Str());//print the exit
										printf("%s\n", room[j]->name.C_Str());//print the room
										printf("%s\n", room[j]->descrip.C_Str());//print the description of the room
										roompos = j;
										break;
									}
								}
							}
						}break;
					}
				}
			}
		
			else if (option.size() == 1 && (option[0] == "h" || option[0] == "help")){//help
				help();
			}
			else if (option.size() == 1 && (option[0] == "map" || option[0] == "m")){//Map, special feature
				map();
			}

			else if (option.size() == 1 && (option[0] == "q" || option[0] == "quit")){//if the player wants to quit
				q++;
			}
			else if (option.size() == 1 && (option[0] == "inventory" || option[0] == "inv" || option[0] == "i")){//inventory of the player
				inventory();
			}

			else if (option.size() >= 2 && (option[0] == "look" && option[1] == "north" || option[0] == "look" && option[1] == "east" || option[0] == "look" && option[1] == "west" || option[0] == "look" && option[1] == "south" || option[0] == "look" && option[1] == "ladder" || option[0] == "look" && option[1] == "wrench" || option[0] == "look" && option[1] == "money" || option[0] == "look" && option[1] == "ticket" || option[0] == "look" && option[1] == "ticket" || option[0] == "look" && option[1] == "key" || option[0] == "look" && option[1] == "map" || option[0] == "look" && option[1] == "box")){
				look(option, roompos);//to look the objects and the directions
			}


			else if (option.size() >= 2 && (option[0] == "open" && option[1] == "north" || option[0] == "open" && option[1] == "east" || option[0] == "open" && option[1] == "west" || option[0] == "open" && option[1] == "south" || option[0] == "pass" && option[1] == "south" || option[0] == "pass" && option[1] == "s")){
				Open(option);//to open the doors of the game
			}

			else if (option.size() >= 2 && (option[0] == "close" && option[1] == "north" || option[0] == "close" && option[1] == "east" || option[0] == "close" && option[1] == "west" || option[0] == "close" && option[1] == "south")){
				Close(option);////to close the doors of the game
			}

			else if (option.size() >= 2 && (option[0] == "pick" && option[1] == "ladder" || option[0] == "pick" && option[1] == "wrench" || option[0] == "pick" && option[1] == "money" || option[0] == "pick" && option[1] == "ticket" || option[0] == "pick" && option[1] == "key" || option[0] == "pick" && option[1] == "map" || option[0] == "pick" && option[1] == "box")){

				pick(option);//if the user wants to pick items
			}

			else if (option.size() >= 2 && (option[0] == "drop" && option[1] == "ladder" || option[0] == "drop" && option[1] == "wrench" || option[0] == "drop" && option[1] == "money" || option[0] == "drop" && option[1] == "ticket" || option[0] == "drop" && option[1] == "key" || option[0] == "drop" && option[1] == "map" || option[0] == "drop" && option[1] == "box")){

				drop(option);//if the user wants to drop items
			}

			else if (option.size() >= 2 && (option[0] == "equip" && option[1] == "ladder" || option[0] == "equip" && option[1] == "wrench" || option[0] == "equip" && option[1] == "money" || option[0] == "equip" && option[1] == "ticket" || option[0] == "equip" && option[1] == "key" || option[0] == "equip" && option[1] == "map")){

				equip(option);//if the user wants to equip an item to use it
			}

			else if (option.size() >= 2 && (option[0] == "unequip" && option[1] == "ladder" || option[0] == "unequip" && option[1] == "wrench" || option[0] == "unequip" && option[1] == "money" || option[0] == "unequip" && option[1] == "ticket" || option[0] == "unequip" && option[1] == "key" || option[0] == "unequip" && option[1] == "map")){

				unequip(option);//if the user wants to unequip an item
			}

			else if (option.size() >= 2 && (option[0] == "put" && option[1] == "ladder" || option[0] == "put" && option[1] == "wrench" || option[0] == "put" && option[1] == "money" || option[0] == "put" && option[1] == "ticket" || option[0] == "put" && option[1] == "key" || option[0] == "put" && option[1] == "map" || option[0] == "put" && option[1] == "box")){

				put(option);//if the user wants to put an item in the box
			}

			else if (option.size() >= 2 && (option[0] == "get" && option[1] == "ladder" || option[0] == "get" && option[1] == "wrench" || option[0] == "get" && option[1] == "money" || option[0] == "get" && option[1] == "ticket" || option[0] == "get" && option[1] == "key" || option[0] == "get" && option[1] == "map" || option[0] == "get" && option[1] == "box")){
				get(option);//if the user wants to get something from the box

			}
			
			else{
				printf("What?");//unknown command
			}
			
	

	} while (q==0);
}


		void World::help()const{//help description

			printf("You are lost in the city and you have to find your new house.\n You can move arround the map using ONLY lowercase.\n\n You can use to move: n, e, s, w or north, east, south, west, also go north, go south, go west, go east.\n\n There will be doors in the map you can open and close some them using open and to close use the word close.\n You can look what is in the room you are and in his directions, also you can look items\n\n Now the user can use this commands \n\n pick and drop items \n\n equip and unequip to use some items \n\n put and get to put or get items from the box that is in the school\n\n some door you will need a key to pass and in a wall you will need to take the ladder\n\n if the user puts inventory it will print the items that are there\n\n if you find the map you will be able to see the map of the city, you have to put m or map\n\n you don't need to look your room because there is a function that is printing all time the objects that are there\n\n");


		}
		
		void World::look(const Vector<mystring>& options, int numroom)const{
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
			for (int x = 0; x < NUM_ITEM; x++){
				if (options[0] == "look" && options[1] == items[x]->name && items[x]->itempos == player->playerposit){//what object did the user said and if its in the same position of the player
					printf("%s\n", items[x]->name.C_Str());//name
					printf("%s\n", items[x]->descrip.C_Str());//description
					if (options[1] == items[BOX]->name){//if its look box
						printf("And the items that are inside the box are:\n");
						for (x = 0; x < NUM_ITEM; x++){
							if (items[x]->inbox == true){//print the objects that ar inside the box
								printf("%s\n", items[x]->name.C_Str());//name
								printf("%s\n", items[x]->descrip.C_Str());//description
							}
						}
					}
					}
				}
			}



		

		void World::Open(const Vector<mystring>& options)
		{


			int i, j;
			if (options[0] == "open" && options[1] == "north" || options[0] == "open" && options[1] == "n" || options[0] == "n" || options[0] == "north")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == NORTH){//looks the orientation
							if (exit[i]->door == true){//if it has door
								if (exit[i]->closed == true){// if its closed 
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == SOUTH && exit[j]->door == true){//what direcction looks the door of the other side and if it has door
											if (exit[j]->destiny->name == exit[i]->origin->name){//if destiny in the second for is the same as origin 
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
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == WEST){//looks the orientation
							if (exit[i]->door == true){// if it has door 
								if (exit[i]->closed == true){// if its closed 
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == EAST && exit[j]->door == true){//what direcction looks the door of the other side and if it has door
											if (exit[j]->destiny->name == exit[i]->origin->name){//if destiny in the second for is the same as origin 
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
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == EAST){//looks the orientation
							if (exit[i]->door == true){// if it has door 
								if (exit[i]->closed == true){// if its closed 
									if (player->playerposit == room[7] && items[KEY]->equipped != true){//if its the last room you need the key to pass
										printf("YOU CAN'T PASS");
										break;
									}
									printf("The door is open\n");
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == WEST && exit[j]->door == true){//to open the door of the other side 
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


			if (options[0] == "open" && options[1] == "south" || options[0] == "open" && options[1] == "s" || options[0] == "s" || options[0] == "south" || options[0] == "pass" && options[1] == "south" || options[0] == "pass" && options[1] == "s")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin == player->playerposit){//if the origin is the same as the player position
						if (exit[i]->orientation == SOUTH){//looks the orientation
							if (exit[i]->door == true){// if it has door 
								if (exit[i]->closed == true){// if its closed 
									if (player->playerposit == room[2] && items[LADDER]->equipped == false){//if its the room 2 you will need a ladder to pass
										printf("YOU CAN'T PASS\n");
										break;
									}
									exit[i]->closed = false;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == NORTH && exit[j]->door== true){//to open the door of the other side 
 											if (exit[j]->destiny == player->playerposit){
												exit[j]->closed = false;
												if (player->playerposit == room[2]){//if its room 2 have to print you passed the wall
													printf("You passed the wall\n");
													break;
												}
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

		void World::Close(const Vector<mystring>& options)
		{

			int i, j;
			if (options[0] == "close" && options[1] == "north" || options[0] == "close" && options[1] == "n" || options[0] == "n" || options[0] == "north")
			{
				for (i = 0; i < EXITNUM; i++){
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == NORTH){//looks the orientation
							if (exit[i]->door == true){//if it has door
								if (exit[i]->closed == false){//if its closed
									if (player->playerposit == room[3]){//in the room 2 you have to pass a wall then you can't close north
										printf("You can't do this\n");
										break;
									}
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == SOUTH && exit[j]->door == true && exit[j]->closed == false){//to close the door of the other side
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
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == WEST){//looks the orientation
							if (exit[i]->door == true){//if it has door
								if (exit[i]->closed == false){//if its closed
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation == EAST){//to close the door of the other side
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
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == EAST){//looks the orientation
							if (exit[i]->door == true){//if it has door
								if (exit[i]->closed == false){//if its closed
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = WEST){//to close the door of the other side
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
					if (exit[i]->origin->name == player->playerposit->name){//if the origin is the same as the player position
						if (exit[i]->orientation == SOUTH){//looks the orientation
							if (exit[i]->door == true){//if it has door
								if (exit[i]->closed == false){//if its closed
									exit[i]->closed = true;
									for (j = 0; j < EXITNUM; j++){
										if (exit[j]->orientation = NORTH){//to close the door of the other side
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
					if (options[1] == items[i]->name && items[i]->itempos == player->playerposit && items[i]->inventory == false && items[i]->equipped == false && items[i]->inbox == false && maxinventory<4){//look name and position, look inventory, look if its equipped and if its the maximum
						if (options[1] == items[TICKET]->name){//if the user wants to take the ticket they will have to have money 
							if (items[MONEY]->inventory == false){//false
								printf("You don't have money\n");
								return;
							}
							else{//true, if its true user loses the money
								items[MONEY]->inventory == false;
									printf("You have given the mony to have some information\n");
									printf("If you go south you will find the park and near you will find House 3");
									maxinventory--;
									return;
							}
						}
						items[i]->inventory = true;//pick the object
						printf("%s\n %s\n", items[i]->name.C_Str(), items[i]->descrip.C_Str());
						maxinventory++;//the maximum of the inventory
						return;
					}
					else if (options[1] == items[i]->name && items[i]->itempos != player->playerposit){//if the object isn't there
						printf("The item isn't here");
						return;
					}
					else if (maxinventory > 3){//if the inventary is full
						printf("You have full inventary you should drop an item");
						return;
					}
				}
			}

		}

		void World::inventory(){
			int i;

			for (i = 0; i < NUM_ITEM; i++){
				if (items[i]->inventory == true){//print the items that are in the inventary
					printf("You have in the inventory:");
					printf("%s\n", items[i]->name.C_Str());
				}
			}

		}

		void World::drop(Vector<mystring>& options){

		if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){

					if (options[1] == items[i]->name && items[i]->inventory == false){//it the item isn't in the inventary
			printf("You don't have the item in the inventary");
			return;
		}
					else if (options[1] == items[i]->name && items[i]->itempos == player->playerposit && items[i]->inventory == true){//drop the item
						if (items[i]->inventory == true){//item of the inventary droped
							items[i]->inventory = false;
						}
						else if (items[i]->equipped == true){//item equipped droped
							items[i]->equipped == false;
							maxequiped--;
						}
						printf("You have droped %s\n", items[i]->name.C_Str());
						maxinventory--;//one less in the inventory
						return;
					}

				}
			}
		}

		void World::equip(const Vector<mystring>& options){

		
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[i]->name && items[i]->inventory == false){//if user don't have the item in the inventary
						printf("You don't have this item in the inventary");
						return;
					}
					else if (options[1] == items[i]->name && items[i]->equipped == false && items[i]->inventory == true && maxequiped==0){//if the item isn't equipped and is in the inventory
						items[i]->equipped = true;//if its equipped its not in the inventory
						items[i]->inventory = false;
						printf("You have equiped %s\n", items[i]->name.C_Str());
						maxinventory--;
						maxequiped++;//maximum equiped
						return;
					}
					else if (options[1] == items[i]->name && items[i]->equipped == false && items[i]->inventory == true && maxequiped > 0){//if there is one item equipped
						printf("You already have one item equiped");
						return;
					}
				}
		}		

		void World::unequip(Vector<mystring>& options){
			
			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[i]->name && items[i]->equipped == false && items[i]->inventory == false){//if the item isn't in the inventary
						printf("You don't have this item in the inventary");
						return;
					}

					else if (options[1] == items[i]->name && items[i]->equipped == true && items[i]->inventory == false){//if the item is in the inventory and equipped
						items[i]->equipped = false;
						items[i]->inventory = true;
						printf("You have unequiped %s\n", items[i]->name.C_Str());
						maxequiped--;
						maxinventory++;
						return;
					}

				}
			}
		}

		

		void World::update(){//this function updates the directions of the items
			for (int i = 0; i < NUM_ITEM; i++){
				if (items[i]->inventory == true){//if the item is in the inventary the dicrection will be the same of the player
					items[i]->itempos = player->playerposit;
				}
				if (items[i]->inbox == true){//if the item is in the box the tirection will be the same as the box
					items[i]->itempos = items[BOX]->itempos;
				}
			}
		}
	
		void World::itemsroom(){//this is a function that in all moment is printing what objects ar in the room and then the user don't have to say look
			int j = 0, i = 0;
			for (j = 0; j < NUM_ITEM; j++){
				if ((items[j]->itempos == player->playerposit) && items[j]->inventory == false ){//if there aren't objects
					i++;
				}
			}
			if (i != 0){
				for (j = 0; j < NUM_ITEM; j++){
					if ((items[j]->itempos == player->playerposit) && items[j]->inventory == false && items[j]->inbox == false && items[j]->equipped==false){
						printf("\nIn this room there is: %s\n", items[j]->name.C_Str());
					}
					if ((items[j]->itempos == player->playerposit) && items[j]->inventory == false && items[j]->inbox==true){//if the object is in the box
						printf("\nIn the box there is: %s\n", items[j]->name.C_Str());
					}
				}
			}
		}

		void World::put(const Vector<mystring>& options){//
			int maximum = 0;

				for (int i = 0; i < NUM_ITEM; i++){
					
					if (maxbox == 2){//the box only can have two items
						printf("In the box you only can put two items");
						return;
					}
					else if (options[1] == items[BOX]->name && items[BOX]->itempos == player->playerposit){//if the player try to put the box into the box
						printf("You can't do this");
						return;
					}
					else if (options[1] == items[i]->name && options[3] == items[BOX]->name && items[i]->itempos == player->playerposit && items[i]->itempos == items[BOX]->itempos && items[i]->inbox == false && maxbox <3){//puts an item iside the box
						if (items[i]->inventory == true){
							items[i]->inventory = false;
							maxinventory--;
						}
						if (items[i]->equipped == true){
							items[i]->equipped == false;
							maxequiped--;
						}
						
						items[i]->inbox = true;//puts the item in the box
						items[i]->itempos = items[BOX]->itempos;//change the position of the object to the box direction
						printf("You have put %s into the box", items[i]->name.C_Str());
						maxbox++;//maximum of items
						return;
					}

					else if (options[1] == items[i]->name && options[3] == items[BOX]->name && items[i]->itempos != items[BOX]->itempos && items[i]->inbox == false){//if the object isn't there
						printf("This item isn't here");
						return;
					}
					else if (options[1] == items[i]->name && options[3] == items[BOX]->name && items[i]->inbox == true && items[i]->itempos == items[BOX]->itempos){//if this item its in the box
						printf("This item is in the box you should get it from there");
						return;
					}
				
						
				}
		
		}

		void World::get(Vector<mystring>& options){
			int maximum = 0;
			if (options.size() > 1){
				for (int i = 0; i < NUM_ITEM; i++){
					if (options[1] == items[BOX]->name && items[BOX]->itempos == player->playerposit){//if you try to get the box from the box
						printf("You can't do this");
						return;
					}
					else if (options[1] == items[i]->name && options[3] == items[BOX]->name && items[i]->itempos == items[BOX]->itempos && player->playerposit == items[BOX]->itempos  && items[i]->inbox == true){//to get some item from the box
						items[i]->inbox = false;//out of the box
						items[i]->inventory = true;//to the inventory
						printf("You have get %s of the box", items[i]->name.C_Str());
						maxinventory++;//maximum of inventory
						maxbox--;//maximum inside the box
						return;
					}
					else if (items[i]->itempos != player->playerposit){//if the item isn't there
					printf("This item isn't here");
					return;
					}
				}
			}


		}

		void World::map()const{//This function is the special feature, prints the map if you pick the map and tells you where are you

			if (items[MAP]->inventory == true){//if you have the map
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c                                          %c\n", 177, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 187, 177);
				printf("%c%c ENTRANCE %c %c         %c %c        %c                                          %c\n", 177, 186, 186, 186, 186, 186, 186, 177);
				printf("%c%c  OF THE  %c%c%c HOUSE 1 %c%c%c SCHOOL %c                                          %c\n", 177, 186, 186, 196, 186, 186, 196, 186, 186, 177);
				printf("%c%c   CITY   %c %c         %c %c        %c                                          %c\n", 177, 186, 186, 186, 186, 186, 186, 177);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c                                          %c\n", 177, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 188, 177);
				printf("%c                             %c                                               %c\n", 177, 179, 177);
				printf("%c                        %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c                      %c\n", 177, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 187, 177);
				printf("%c                        %c         %c %c      %c %c        %c                      %c\n", 177, 186, 186, 186, 186, 186, 186, 177);
				printf("%c                        %c HOUSE 2 %c%c%c SHOP %c%c%c CINEMA %c                      %c\n", 177, 186, 186, 196, 186, 186, 196, 186, 186, 177);
				printf("%c                        %c         %c %c      %c %c        %c                      %c\n", 177, 186, 186, 186, 186, 186, 186, 177);
				printf("%c                        %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c                      %c\n", 177, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 188, 177);
				printf("%c                                                 %c                           %c\n", 177, 179, 177);
				printf("%c                                              %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c\n", 177, 201, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 205, 205, 205, 187, 177);
				printf("%c                                              %c      %c %c         %c %c        %c%c\n", 177, 186, 186, 186, 186, 186, 186, 177);
				printf("%c                                              %c PARK %c%c%c HOUSE 3 %c%c%c FINISH %c%c\n", 177, 186, 186, 196, 186, 186, 196, 186, 186, 177);
				printf("%c                                              %c      %c %c         %c %c        %c%c\n", 177, 186, 186, 186, 186, 186, 186, 177);
				printf("%c                                              %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c\n", 177, 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 205, 205, 188, 177);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177);
				printf("YOU ARE IN %s", player->playerposit->name);
			}

			else{//if you don't have the map
				printf("You can't do this");
			}
		}
