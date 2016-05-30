#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"MyString.h"
#include"Vector.h"
#include"Entity.h"
#include <Windows.h>
#include"Thug.h"



World::World(){
	
}
World::~World(){/*
	for (int i = 0; i < EXITNUM; i++){
		delete exit[i];
	}
	for (int i = 0; i < ROOMNUM; i++){
		delete room[i];
	}
	for (int i = 0; i < NUM_ITEM; i++){
		delete items[i];
	}*/
	//delete player;//free memory
}

void World::createworld(){
	//room 0
	entities.pushback(new Room("Entrance of the city", "You are in the entrance of the city and you have to find your house.", ROOM));
	//--------------------------------------------------------------------
	//room 1
	entities.pushback(new Room("House 1", "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.", ROOM));
	//room 2
	entities.pushback(new Room("School", "There's a girl and she want to talk with you. Here you have a box.", ROOM));
	//room 3
	entities.pushback(new Room("House 2", "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.", ROOM));
	//room 4
	entities.pushback(new Room("Shop", " ", ROOM));
	//room 5
	entities.pushback(new Room("Cinema", "If you buy my ticket i will tell you where is the house 3 where you can find the key to enter to your house.", ROOM));
	//room 6
	entities.pushback(new Room("Park", "Oh no! There is a thug take care!", ROOM));
	//room 7
	entities.pushback(new Room("House 3", "Its seems that there is something important...", ROOM));
	//room 8
	entities.pushback(new Room("Finish", "You end the game", ROOM));






	
	//exit 0 9
	entities.pushback(new Exit("Main street", "In the east there is the house 1", EAST, (Room*)entities[0], (Room*)entities[1], false, false, EXIT));
	//exit 1 10
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[0], (Room*)entities[0], false, false, EXIT));
	//exit 2 11
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[0], (Room*)entities[0], false, false, EXIT));
	//exit 3 12
	entities.pushback(new Exit("There's a wall", "There's a wall", WEST, (Room*)entities[0], (Room*)entities[0], false, false, EXIT));
	//--------------------------------------------------------------------
	//exit 4 13
	entities.pushback(new Exit("Student Street", "In the east there is the school", EAST, (Room*)entities[1], (Room*)entities[2], false, false, EXIT));
	//exit 5 14
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[1], (Room*)entities[1], false, false, EXIT));
	//exit 6 15
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[1], (Room*)entities[1], false, false, EXIT));
	//exit 7 16 
	entities.pushback(new Exit("Main street", "In the west there is the entrance of the city", WEST, (Room*)entities[1], (Room*)entities[0], false, false, EXIT));


	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	
	//exit 8 17 
	entities.pushback(new Exit("There's a wall", "There's a wall", EAST, (Room*)entities[2], (Room*)entities[2], false, false, EXIT));
	//exit 9 18 
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[2], (Room*)entities[2], false, false, EXIT));
	//exit 10 19
	entities.pushback(new Exit("Joan Oliver street", "In the south there is the house 2", SOUTH, (Room*)entities[2], (Room*)entities[3], true, true, EXIT));
	//exit 11 20
	entities.pushback(new Exit("Student Street", "In the west there is the house 1", WEST, (Room*)entities[2], (Room*)entities[1], false, false, EXIT));
	
	//----------------------------------------------
	//--------------------------------------------------------------------
	//exit 12 21
	entities.pushback(new Exit("Verdi street", "In the east there is the shop", EAST, (Room*)entities[3], (Room*)entities[4], false, false, EXIT));
	//exit 13 22
	entities.pushback(new Exit("Joan Oliver street", "In the north there is the school", NORTH, (Room*)entities[3], (Room*)entities[2], true, true, EXIT));
	//exit 14 23
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[3], (Room*)entities[3], false, false, EXIT));
	//exit 15 24
	entities.pushback(new Exit("There's a wall", "There's a wall", WEST, (Room*)entities[3], (Room*)entities[3], false, false, EXIT));
	
	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 16 25
	entities.pushback(new Exit("Elisenda street", "In the east there is the cinema", EAST, (Room*)entities[4], (Room*)entities[5], false, false, EXIT));
	//exit 17 26
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[4], (Room*)entities[4], false, false, EXIT));
	//exit 18 27
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[4], (Room*)entities[4], false, false, EXIT));
	//exit 19 28
	entities.pushback(new Exit("Verdi street", "In the east there is the house 2", WEST, (Room*)entities[4], (Room*)entities[3], false, false, EXIT));
	
	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 20 29
	entities.pushback(new Exit("There's a wall", "There's a wall", EAST, (Room*)entities[5], (Room*)entities[5], false, false, EXIT));
	//exit 21 30
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[5], (Room*)entities[5], false, false, EXIT));
	//exit 22 31
	entities.pushback(new Exit("Hobby street", "In the south there is the park", SOUTH, (Room*)entities[5], (Room*)entities[6], false, false, EXIT));
	//exit 23 32
	entities.pushback(new Exit("Elisenda street", "In the south there is the shop", WEST, (Room*)entities[5], (Room*)entities[4], false, false, EXIT));

	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 24 33
	entities.pushback(new Exit("Residencial Street", "In the east there is the house 3", EAST, (Room*)entities[6], (Room*)entities[7], false, false, EXIT));
	//exit 25 34
	entities.pushback(new Exit("Hobby street", "In the north there is the cinema", NORTH, (Room*)entities[6], (Room*)entities[5], false, false, EXIT));
	//exit 26 35
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[6], (Room*)entities[6], false, false, EXIT));
	//exit 27 36
	entities.pushback(new Exit("There's a wall", "There's a wall", WEST, (Room*)entities[6], (Room*)entities[6], false, false, EXIT));
	
	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 28 37
	entities.pushback(new Exit("Residencial Street", "In the east there is the goal", EAST, (Room*)entities[7], (Room*)entities[8], true, true, EXIT));
	//exit 29 38
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[7], (Room*)entities[7], false, false, EXIT));
	//exit 30 39
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[7], (Room*)entities[7], false, false, EXIT));
	//exit 31 40
	entities.pushback(new Exit("Residencial Street", "In the east there is the park", WEST, (Room*)entities[7], (Room*)entities[6], false, false, EXIT));

	//--------------------------------------------------------------------
	//--------------------------------------------------------------------
	//exit 32 41
	entities.pushback(new Exit("There's a wall", "There's a wall", EAST, (Room*)entities[8], (Room*)entities[8], false, false, EXIT));
	//exit 33 42
	entities.pushback(new Exit("There's a wall", "There's a wall", NORTH, (Room*)entities[8], (Room*)entities[8], false, false, EXIT));
	//exit 34 43
	entities.pushback(new Exit("There's a wall", "There's a wall", SOUTH, (Room*)entities[8], (Room*)entities[8], false, false, EXIT));
	//exit 35 44
	entities.pushback(new Exit("Residencial Street", "In the west there's house 3", WEST, (Room*)entities[8], (Room*)entities[7], true, true, EXIT));

	//ITEMS---------------------------------------------
	//item 45 (1)
	entities.pushback(new Item("ladder", "A ladder that you can use it to pass walls", (Room*)entities[1], false, false, false, ITEM));
	entities[1]->list.pushback(entities[45]);
	//-------
	//item 46 (2)
	entities.pushback(new Item("wrench", "You can use the wrench to fight if you have problems", (Room*)entities[3], false, false, false, ITEM));
	entities[3]->list.pushback(entities[46]);
	//-------
	//item 47 (3)
	entities.pushback(new Item("money", "With this money you can buy somthing", (Room*)entities[4], false, false, false, ITEM));
	entities[4]->list.pushback(entities[47]);
	//-------
	//item 48 (4)
	entities.pushback(new Item("ticket", "If you have this ticket means that you have some information about house 3", (Room*)entities[5], false, false, false, ITEM));
	entities[5]->list.pushback(entities[48]);
	//-------
	//item 49 (5)
	entities.pushback(new Item("key", "With this key you can enter to your house!!", (Room*)entities[7], false, false, false, ITEM));
	entities[7]->list.pushback(entities[49]);
	//-------
	//item 50 (6)
	entities.pushback(new Item("map", "With this special feature if you press you can see the map of the city", (Room*)entities[2], false, false, false, ITEM));
	entities[2]->list.pushback(entities[50]);
	//-------
	//item 51 (7)
	entities.pushback(new Item("box", "A box that you find in school and you can put and get things", (Room*)entities[2], false, false, false, ITEM));
	entities[2]->list.pushback(entities[51]);
	box = (Item*)entities[51];
	entities.pushback(new Player("player", "Don't need description", 100, 20, 80, (Room*)entities[0]));
	player = (Player*)entities[52];

	entities.pushback(new Thug("thug", "A guy that wants to kick you", 100, 30, 90, (Room*)entities[6]));
	thug =(Thug*)entities[53];


	entities.pushback(new Item("potion", "With this you can recover 20 of live. YOU ONLY CAN USE IT WHEN YOU ARE FIGHTING", (Room*)entities[4], false, false, false, ITEM));
	entities[4]->list.pushback(entities[54]);
}

void World::movement(const Vector<mystring>& move){
	int roompos = 0;
	int i = 0, j = 0;
	int x = 0;
	


		//update();
		
		if (player->position == (Room*)entities[8]){
			return;
		}
		if (thug->state != FIGHT){
		printf("\nWhere do you want to go?\n");

		char direction1[50];
		
		
			system("cls");
			//-------------------------------------------------------------------------------------------------------------North
			if (move.size() == 2 && move[0] == "go" && move[1] == "north" || move.size() == 2 && move[0] == "go" && move[1] == "n" || move.size() == 1 && move[0] == "n" || move.size() == 1 && move[0] == "north"){
				for (i = 0; i < entities.size(); i++){
					if (entities[i]->Typeobj == EXIT && player->position == ((Exit*)entities[i])->origin && ((Exit*)entities[i])->orientation == NORTH){ //if the origin is the same position as the origin, also look the orientation
						if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny){//if the origin and the destiny are the same there's a wall
							printf("\nThere's a wall");
							item->itemsroom();
							break;
						}
						for (j = 0; j < entities.size(); j++){
							if (((Exit*)entities[i])->destiny == (Room*)entities[j]){//if the destiny is the same position of the room
								if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny){
									printf("%s", ((Exit*)entities[i])->descrip);
									item->itemsroom();
									break;
								}
								else{
									if (((Exit*)entities[i])->door == true && ((Exit*)entities[i])->closed == true){//if there's a door and if its closed
										printf("There's a door");
										item->itemsroom();
										break;
									}
									else{
										printf("%s\n", ((Exit*)entities[i])->name.C_Str());//print the exit
										printf("%s\n", (Room*)entities[j]->name.C_Str());//print the room
										printf("%s\n", (Room*)entities[j]->descrip.C_Str());//print the description of the room
										player->position = ((Room*)entities[j]);
										item->itemsroom();
										break;


									}
								}
							}
						}break;
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------West
			else if (move.size() == 2 && move[0] == "go" && move[1] == "west" || move.size() == 2 && move[0] == "go" && move[1] == "w" || move.size() == 1 && move[0] == "w" || move.size() == 1 && move[0] == "west"){
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->Typeobj == EXIT && player->position == ((Exit*)entities[i])->origin && ((Exit*)entities[i])->orientation == WEST){//if the origin is the same position as the origin, also look the orientation
						if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny){//if the origin and the destiny are the same there's a wall
							printf("There's a wall");
							item->itemsroom();
							break;
						}
						for (j = 0; j < entities.size(); j++){
							if (((Exit*)entities[i])->destiny == (Room*)entities[j]){//if the destiny is the same position of the room
								if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny){
									printf("%s", ((Exit*)entities[i])->descrip);
									item->itemsroom();
									break;
								}
								else{
									if (((Exit*)entities[i])->door == true && ((Exit*)entities[i])->closed == true){//if there's a door and if its closed
										printf("There's a door");
										item->itemsroom();
										item->itemsroom();
										break;
									}
									else{
										printf("%s\n", ((Exit*)entities[i])->name.C_Str());//print the exit
										printf("%s\n", (Room*)entities[j]->name.C_Str());//print the room
										printf("%s\n", (Room*)entities[j]->descrip.C_Str());//print the description of the room
										player->position = ((Room*)entities[j]);
										item->itemsroom();
										break;

									}
								}
							}
						}break;
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------South
			else if (move.size() == 2 && move[0] == "go" && move[1] == "south" || move.size() == 2 && move[0] == "go" && move[1] == "s" || move.size() == 1 && move[0] == "s" || move.size() == 1 && move[0] == "south")
			{
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->Typeobj == EXIT && player->position == ((Exit*)entities[i])->origin && ((Exit*)entities[i])->orientation == SOUTH){//if the origin is the same position as the origin, also look the orientation
						if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny){//if the origin and the destiny are the same there's a wall
							printf("There's a wall");
							item->itemsroom();
							break;
						}
						for (j = 0; j < entities.size(); j++){
							if (((Exit*)entities[i])->destiny == (Room*)entities[j]){//if the destiny is the same position of the room
								if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny){
									printf("%s", ((Exit*)entities[i])->descrip);
									item->itemsroom();
									break;
								}
								else{
									if (((Exit*)entities[i])->door == true && ((Exit*)entities[i])->closed == true){//if there's a door and if its closed
										if (player->position == (Room*)entities[2]){
											printf("There's a wall you have to pass");
											item->itemsroom();
										}
										else{
											printf("There's a door");
											item->itemsroom();
										}
										break;
									}
									else{
										printf("%s\n", ((Exit*)entities[i])->name.C_Str());//print the exit
										printf("%s\n", (Room*)entities[j]->name.C_Str());//print the room
										printf("%s\n", (Room*)entities[j]->descrip.C_Str());//print the description of the room
										player->position = ((Room*)entities[j]);
										item->itemsroom();
										break;

									}
								}
							}
						}break;
					}
				}
			}
			//-----------------------------------------------------------------------------------------------------------------East
			else if (move.size() == 2 && move[0] == "go" && move[1] == "east" || move.size() == 2 && move[0] == "go" && move[1] == "e" || move.size() == 1 && move[0] == "e" || move.size() == 1 && move[0] == "east")
			{
				for (i = 0; i < entities.size(); i++)
				{
					if (((Exit*)entities[i])->Typeobj == EXIT &&player->position == ((Exit*)entities[i])->origin && ((Exit*)entities[i])->orientation == EAST)//if the origin is the same position as the origin, also look the orientation
					{
						if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny)//if the origin and the destiny are the same there's a wall
						{
							printf("%s", ((Exit*)entities[i])->descrip);
							item->itemsroom();
							break;
						}
						for (j = 0; j < entities.size(); j++)
						{
							if (((Exit*)entities[i])->destiny == (Room*)entities[j])//if the destiny is the same position of the room
							{
								if (((Exit*)entities[i])->origin == ((Exit*)entities[i])->destiny)
								{
									printf("%s", ((Exit*)entities[i])->descrip.C_Str());
									item->itemsroom();
									break;
								}
								else
								{
									if (((Exit*)entities[i])->door == true && ((Exit*)entities[i])->closed == true)//if there's a door and if its closed
									{
										printf("There's a door");
										item->itemsroom();
										break;
									}
									else
									{
										printf("%s\n", ((Exit*)entities[i])->name.C_Str());//print the exit
										printf("%s\n", (Room*)entities[j]->name.C_Str());//print the room
										printf("%s\n", (Room*)entities[j]->descrip.C_Str());//print the description of the room
										player->position = ((Room*)entities[j]);
										item->itemsroom();

										break;
									}
								}
							}
						}break;
					}
				}
			}

			else if (move.size() == 1 && (move[0] == "h" || move[0] == "help")){//help
				help();
			}
			else if (move.size() == 1 && (move[0] == "map" || move[0] == "m")){//Map, special feature
				item->map();
			}

			else if (move.size() == 1 && move[0] == "q" || move[0] == "quit"){//if the player wants to quit
				q++;
			}
			else if (move.size() == 1 && (move[0] == "inventory" || move[0] == "inv" || move[0] == "i")){//inventory of the player
				inventory();
			}

			else if (move.size() >= 2 && (move[0] == "look" && move[1] == "north" || move[0] == "look" && move[1] == "east" || move[0] == "look" && move[1] == "west" || move[0] == "look" && move[1] == "south" || move[0] == "look" && move[1] == "ladder" || move[0] == "look" && move[1] == "wrench" || move[0] == "look" && move[1] == "money" || move[0] == "look" && move[1] == "ticket" || move[0] == "look" && move[1] == "ticket" || move[0] == "look" && move[1] == "key" || move[0] == "look" && move[1] == "map" || move[0] == "look" && move[1] == "box")){
				look(move, roompos);//to look the objects and the directions
			}


			else if (move.size() >= 2 && (move[0] == "open" && move[1] == "north" || move[0] == "open" && move[1] == "east" || move[0] == "open" && move[1] == "west" || move[0] == "open" && move[1] == "south" || move[0] == "pass" && move[1] == "south" || move[0] == "pass" && move[1] == "s")){
				Open(move);//to open the doors of the game
			}

			else if (move.size() >= 2 && (move[0] == "close" && move[1] == "north" || move[0] == "close" && move[1] == "east" || move[0] == "close" && move[1] == "west" || move[0] == "close" && move[1] == "south")){
				Close(move);////to close the doors of the game
			}

			else if (move.size() >= 2 && (move[0] == "pick" && move[1] == "ladder" || move[0] == "pick" && move[1] == "wrench" || move[0] == "pick" && move[1] == "money" || move[0] == "pick" && move[1] == "ticket" || move[0] == "pick" && move[1] == "key" || move[0] == "pick" && move[1] == "map" || move[0] == "pick" && move[1] == "box")){

				player->pick(move);//if the user wants to pick items
			}

			else if (move.size() >= 2 && (move[0] == "drop" && move[1] == "ladder" || move[0] == "drop" && move[1] == "wrench" || move[0] == "drop" && move[1] == "money" || move[0] == "drop" && move[1] == "ticket" || move[0] == "drop" && move[1] == "key" || move[0] == "drop" && move[1] == "map" || move[0] == "drop" && move[1] == "box")){

				player->drop(move);//if the user wants to drop items
			}

			else if (move.size() >= 2 && (move[0] == "equip" && move[1] == "ladder" || move[0] == "equip" && move[1] == "wrench" || move[0] == "equip" && move[1] == "money" || move[0] == "equip" && move[1] == "ticket" || move[0] == "equip" && move[1] == "key" || move[0] == "equip" && move[1] == "map")){

				player->equip(move);//if the user wants to equip an item to use it
			}

			else if (move.size() >= 2 && (move[0] == "unequip" && move[1] == "ladder" || move[0] == "unequip" && move[1] == "wrench" || move[0] == "unequip" && move[1] == "money" || move[0] == "unequip" && move[1] == "ticket" || move[0] == "unequip" && move[1] == "key" || move[0] == "unequip" && move[1] == "map")){

				player->unequip(move);//if the user wants to unequip an item
			}

			else if (move.size() >= 2 && (move[0] == "put" && move[1] == "ladder" || move[0] == "put" && move[1] == "wrench" || move[0] == "put" && move[1] == "money" || move[0] == "put" && move[1] == "ticket" || move[0] == "put" && move[1] == "key" || move[0] == "put" && move[1] == "map" || move[0] == "put" && move[1] == "box")){

				player->put(move);//if the user wants to put an item in the box
			}

			else if (move.size() >= 2 && (move[0] == "get" && move[1] == "ladder" || move[0] == "get" && move[1] == "wrench" || move[0] == "get" && move[1] == "money" || move[0] == "get" && move[1] == "ticket" || move[0] == "get" && move[1] == "key" || move[0] == "get" && move[1] == "map" || move[0] == "get" && move[1] == "box")){
				player->get(move);//if the user wants to get something from the box

			}
			else if (move.size() >= 2 && (move[0] == "buy" || move[1] == "potion")){//if the player wants to quit
				player->buy(move);
			}
			else{
				printf("What?\n");//unknown command
				if (thug->state != FIGHT){
					item->itemsroom();
				}
			}
		}
		else if (move.size() >= 2 && (move[0] == "attack" || move[1] == "thug")){
			player->attack(move);
		}
			
			

	
}


		void World::help()const{//help description

			printf("You are lost in the city and you have to find your new house.\n You can move arround the map using ONLY lowercase.\n\n You can use to move: n, e, s, w or north, east, south, west, also go north, go south, go west, go east.\n\n There will be doors in the map you can open and close some them using open and to close use the word close.\n You can look what is in the room you are and in his directions, also you can look items\n\n Now the user can use this commands \n\n pick and drop items \n\n equip and unequip to use some items \n\n put and get to put or get items from the box that is in the school\n\n some door you will need a key to pass and in a wall you will need to take the ladder\n\n if the user puts inventory it will print the items that are there\n\n if you find the map you will be able to see the map of the city, you have to put m or map\n\n you don't need to look your room because there is a function that is printing all time the objects that are there\n\n to pass the wall you have to say pass and the direction");


		}
		
		void World::look(const Vector<mystring>& options, int numroom)const{
			int exitnum=0;//count
			if (options[0] == "look" && options[1] == "north"){//if the user says look north
				for (exitnum = 0; exitnum < entities.size(); exitnum++)
				{
					if (((Exit*)entities[exitnum])->orientation == NORTH )//exits with north orientation
					{
						if (((Exit*)entities[exitnum])->origin == player->position)//if origin and the player have the same direction
						{
							printf("%s\n", ((Exit*)entities[exitnum])->descrip.C_Str());
						}

					}
				}
			}
			if (options[0] == "look" && options[1] == "west"){//if the user says look west
				for (exitnum = 0; exitnum < entities.size(); exitnum++)
				{
					if (((Exit*)entities[exitnum])->orientation == WEST )//exits with west orientation
					{
						if (((Exit*)entities[exitnum])->origin == player->position)//if origin and the player have the same direction
						{
							printf("%s\n", ((Exit*)entities[exitnum])->descrip.C_Str());
						}
					}
				}
			}

			if (options[0] == "look" && options[1] == "south"){//if the user says look south
				for (exitnum = 0; exitnum < entities.size(); exitnum++)
				{
					if (((Exit*)entities[exitnum])->orientation == SOUTH )//exits with south orientation
					{
						if (((Exit*)entities[exitnum])->origin == player->position)//if origin and the player have the same direction
						{
							printf("%s\n", ((Exit*)entities[exitnum])->descrip.C_Str());
						}
					}
				}
			}

			if (options[0] == "look" && options[1] == "east"){//if the user says look east
				for (exitnum = 0; exitnum < entities.size(); exitnum++)
				{
					if (((Exit*)entities[exitnum])->orientation == EAST )//exits with east orientation
					{
						if (((Exit*)entities[exitnum])->origin == player->position)//if origin and the player have the same direction
						{
							printf("%s", ((Exit*)entities[exitnum])->descrip.C_Str());
						}
					}
				}
			}
			for (int x = 0; x < entities.size(); x++){
				if (options[0] == "look" && options[1] == ((Item*)entities[x])->name && ((Item*)entities[x])->itempos == player->position){//what object did the user said and if its in the same position of the player
					printf("%s\n", ((Item*)entities[x])->name.C_Str());//name
					printf("%s\n", ((Item*)entities[x])->descrip.C_Str());//description
					if (options[1] == ((Item*)entities[BOX])->name){//if its look box
						printf("And the items that are inside the box are:\n");
						for (x = 0; x < entities.size(); x++){
							if (((Item*)entities[x])->inbox == true){//print the objects that ar inside the box
								printf("%s\n", ((Item*)entities[x])->name.C_Str());//name
								printf("%s\n", ((Item*)entities[x])->descrip.C_Str());//description
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin->name == player->position->name){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == NORTH){//looks the orientation
							if (((Exit*)entities[i])->door == true){//if it has door
								if (((Exit*)entities[i])->closed == true){// if its closed 
									((Exit*)entities[i])->closed = false;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation == SOUTH && ((Exit*)entities[j])->door == true){//what direcction looks the door of the other side and if it has door
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name){//if destiny in the second for is the same as origin 
												((Exit*)entities[j])->closed = false;
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin->name == player->position->name){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == WEST){//looks the orientation
							if (((Exit*)entities[i])->door == true){// if it has door 
								if (((Exit*)entities[i])->closed == true){// if its closed 
									((Exit*)entities[i])->closed = false;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation == EAST && ((Exit*)entities[j])->door == true){//what direcction looks the door of the other side and if it has door
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name){//if destiny in the second for is the same as origin 
												((Exit*)entities[j])->closed = false;
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin == player->position){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == EAST){//looks the orientation
							if (((Exit*)entities[i])->door == true){// if it has door 
								if (((Exit*)entities[i])->closed == true){// if its closed 
									if (player->position == (Room*)entities[7] && ((Item*)entities[KEY])->equipped != true){//if its the last room you need the key to pass
										printf("YOU CAN'T PASS");
										break;
									}
									//printf("The door is open\n");
									((Exit*)entities[i])->closed = false;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation == WEST && ((Exit*)entities[j])->door == true){//to open the door of the other side 
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name){
												((Exit*)entities[j])->closed = false;
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin == player->position){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == SOUTH){//looks the orientation
							if (((Exit*)entities[i])->door == true){// if it has door 
								if (((Exit*)entities[i])->closed == true){// if its closed 
									if (player->position == (Room*)entities[2] && ((Item*)entities[LADDER])->equipped == false){//if its the room 2 you will need a ladder to pass
										printf("YOU CAN'T PASS\n");
										break;
									}
									((Exit*)entities[i])->closed = false;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation == NORTH && ((Exit*)entities[j])->door == true){//to open the door of the other side 
											if (((Exit*)entities[j])->destiny == player->position){
												((Exit*)entities[j])->closed = false;
												if (player->position == (Room*)entities[2]){//if its room 2 have to print you passed the wall
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin->name == player->position->name){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == NORTH){//looks the orientation
							if (((Exit*)entities[i])->door == true){//if it has door
								if (((Exit*)entities[i])->closed == false){//if its closed
									if (player->position == (Room*)entities[3]){//in the room 2 you have to pass a wall then you can't close north
										printf("You can't do this\n");
										break;
									}
									((Exit*)entities[i])->closed = true;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation == SOUTH && ((Exit*)entities[j])->door == true && ((Exit*)entities[j])->closed == false){//to close the door of the other side
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name){
												((Exit*)entities[j])->closed == true;
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin->name == player->position->name){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == WEST){//looks the orientation
							if (((Exit*)entities[i])->door == true){//if it has door
								if (((Exit*)entities[i])->closed == false){//if its closed
									((Exit*)entities[i])->closed = true;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation == EAST){//to close the door of the other side
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name && ((Exit*)entities[j])->door == true && ((Exit*)entities[j])->closed == false){
												((Exit*)entities[j])->closed = true;
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin->name == player->position->name){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == EAST){//looks the orientation
							if (((Exit*)entities[i])->door == true){//if it has door
								if (((Exit*)entities[i])->closed == false){//if its closed
									((Exit*)entities[i])->closed = true;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation = WEST){//to close the door of the other side
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name && ((Exit*)entities[j])->door == true && ((Exit*)entities[j])->closed == false){
												((Exit*)entities[j])->closed = true;
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
				for (i = 0; i < entities.size(); i++){
					if (((Exit*)entities[i])->origin->name == player->position->name){//if the origin is the same as the player position
						if (((Exit*)entities[i])->orientation == SOUTH){//looks the orientation
							if (((Exit*)entities[i])->door == true){//if it has door
								if (((Exit*)entities[i])->closed == false){//if its closed
									((Exit*)entities[i])->closed = true;
									for (j = 0; j < entities.size(); j++){
										if (((Exit*)entities[j])->orientation = NORTH){//to close the door of the other side
											if (((Exit*)entities[j])->destiny->name == ((Exit*)entities[i])->origin->name && ((Exit*)entities[j])->door == true && ((Exit*)entities[j])->closed == false){
												((Exit*)entities[j])->closed = true;
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

		

		

		



		

		/*void World::update(){//this function updates the directions of the items
			for (int i = 0; i < entities.size(); i++){
				if (((Item*)entities[i])->inventory == true && ((Item*)entities[i])->Typeobj == ITEM){//if the item is in the inventory the dicrection will be the same of the player
					((Item*)entities[i])->itempos = player->position;
				}
				if (((Item*)entities[i])->inbox == true && ((Item*)entities[i])->Typeobj == ITEM){//if the item is in the box the tirection will be the same as the box
					((Item*)entities[i])->itempos = ((Item*)entities[BOX])->itempos;
				}
			}
		}*/
		

		

	
		void World::inventory(){
			int i=0;
			int temp = 0;
			Dlist<Entity*>::DNode* tempor = nullptr;
			for (tempor = player->list.first; tempor != nullptr; tempor = tempor->next){
				printf("You have %s\n", tempor->data->name);
				i++;
			}
			printf("You have %i$", player->money);
			if (i ==0){
				printf("You don't have nothing in the inventary\n");
				printf("You have: %i$", player->money);
			}

		}