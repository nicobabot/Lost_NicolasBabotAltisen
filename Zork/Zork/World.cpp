#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
void World::createworld(){
	Rooms *room = new Rooms[8];//Memory for the rooms created
	Exits *exit = new Exits[12];//Memory for the rooms created
	//House 1 inside House[0]
	strcpy_s(room[0].name, "House 1");
	strcpy_s(room[0].descriptions, "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.");
	strcpy_s(room[0].north, "Exit");
	strcpy_s(room[0].west, "There's a wall");
	strcpy_s(room[0].south, "There's a wall");
	strcpy_s(room[0].east, "There's a wall");
	strcpy_s(room[0].up, "You can't go up");
	strcpy_s(room[0].down, "You can't go down");
	room[0].changeroom = 0;
	//House 1 Exit exit[0]
	strcpy_s(exit[0].name, "Street");
	strcpy_s(exit[0].north, "There's a wall");
	strcpy_s(exit[0].west, "Street");
	strcpy_s(exit[0].south, "House 1");
	strcpy_s(exit[0].east, "School");
	//School room[1]
	strcpy_s(room[1].name, "School");
	strcpy_s(room[1].descriptions, "There's a girl and she want to talk with you.");
	strcpy_s(room[1].north, "Exit");
	strcpy_s(room[1].west, "There's a wall");
	strcpy_s(room[1].south, "There's a wall");
	strcpy_s(room[1].east, "There's a wall");
	strcpy_s(room[1].up, "First floor");
	strcpy_s(room[1].down, "You can't go down");
	room[1].changeroom = 1;
	//School Exit exit[1]
	strcpy_s(exit[1].name, "Street");
	strcpy_s(exit[1].north, "There's a wall");
	strcpy_s(exit[1].west, "House 1");
	strcpy_s(exit[1].south, "School");
	strcpy_s(exit[1].east, "Street");
	//House 2 room[2]
	strcpy_s(room[2].name, "House 2,");
	strcpy_s(room[2].descriptions, "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.");
	strcpy_s(room[2].north, "Exit");
	strcpy_s(room[2].west, "There's a wall");
	strcpy_s(room[2].south, "There's a wall");
	strcpy_s(room[2].east, "There's a wall");
	strcpy_s(room[2].up, "You can't go up");
	strcpy_s(room[2].down, "You can't go down");
	room[2].changeroom = 2;
	//House 2 Exit exit[2]
	strcpy_s(exit[2].name, "Street");
	strcpy_s(exit[2].north, "There's a wall");
	strcpy_s(exit[2].west, "Shop / Park");
	strcpy_s(exit[2].south, "House 2");
	strcpy_s(exit[2].east, "Street");
	//Park room[3]
	strcpy_s(room[3].name, "Park,");
	strcpy_s(room[3].descriptions, "Oh no! There is a thug take care!.");
	strcpy_s(room[3].north, "Exit");
	strcpy_s(room[3].west, "There's a wall");
	strcpy_s(room[3].south, "There's a wall");
	strcpy_s(room[3].east, "There's a wall");
	strcpy_s(room[3].up, "You can't go up");
	strcpy_s(room[3].down, "You can't go down");
	room[3].changeroom = 3;
	//Park Exit exit[3]
	strcpy_s(exit[3].name, "Street");
	strcpy_s(exit[3].north, "Shop");
	strcpy_s(exit[3].west, "A door closed");
	strcpy_s(exit[3].south, "Park");
	strcpy_s(exit[3].east, "Street");
	//cinema room[4]
	strcpy_s(room[4].name, "Cinesa");
	strcpy_s(room[4].descriptions, "If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house.");
	strcpy_s(room[4].north, "There's a wall");
	strcpy_s(room[4].west, "There's a wall");
	strcpy_s(room[4].south, "Exit");
	strcpy_s(room[4].east, "There's a wall");
	strcpy_s(room[4].up, "You can't go up");
	strcpy_s(room[4].down, "You can't go down");
	room[4].changeroom = 4;
	//cinema Exit exit[4]
	strcpy_s(exit[4].name, "Street");
	strcpy_s(exit[4].north, "Cinema");
	strcpy_s(exit[4].west, "House 3");
	strcpy_s(exit[4].south, "There is a wall");
	strcpy_s(exit[4].east, "Park 2");
	//House 3 room[5]
	strcpy_s(room[5].name, "House 3");
	strcpy_s(room[5].descriptions, "Its seems that there is something important...");
	strcpy_s(room[5].north, "Exit");
	strcpy_s(room[5].west, "There's a wall");
	strcpy_s(room[5].south, "The key");
	strcpy_s(room[5].east, "There's a wall");
	strcpy_s(room[5].up, "You can't go up");
	strcpy_s(room[5].down, "You can't go down");
	room[5].changeroom = 5;
	//House 3 Exit exit[5]
	strcpy_s(exit[5].name, "Street");
	strcpy_s(exit[5].north, "Street");
	strcpy_s(exit[5].west, "There's a door closed");
	strcpy_s(exit[5].south, "House 3");
	strcpy_s(exit[5].east, "Cinema");
	//Park 2 room[6]
	strcpy_s(room[6].name, "Park 2");
	strcpy_s(room[6].descriptions, "Oh no! There is a thug take care!");
	strcpy_s(room[6].north, "There's a wall");
	strcpy_s(room[6].west, "Exit");
	strcpy_s(room[6].south, "There's a wall");
	strcpy_s(room[6].east, "There's a wall");
	strcpy_s(room[6].up, "You can't go up");
	strcpy_s(room[6].down, "You can't go down");
	room[1].changeroom = 1;
	//Park 2 Exit exit[6]
	strcpy_s(exit[6].name, "Street");
	strcpy_s(exit[6].north, "Street");
	strcpy_s(exit[6].west, "Cinema");
	strcpy_s(exit[6].south, "There's a wall");
	strcpy_s(exit[6].east, "Park 2");
	//Shop room[7]
	strcpy_s(room[7].name, "Park,");
	strcpy_s(room[7].descriptions, "The seller gives you money because he is sad because you are lost.");
	strcpy_s(room[7].north, "There's a wall");
	strcpy_s(room[7].west, "There's a wall");
	strcpy_s(room[7].south, "Exit");
	strcpy_s(room[7].east, "There's a wall");
	strcpy_s(room[7].up, "You can't go up");
	strcpy_s(room[7].down, "You can't go down");
	//Park Exit exit[7]
	strcpy_s(exit[7].name, "Street");
	strcpy_s(exit[7].north, "Shop");
	strcpy_s(exit[7].west, "A door closed");
	strcpy_s(exit[7].south, "Park");
	strcpy_s(exit[7].east, "Street");

	//We need 5 "exits" that are streets because in the maps there are points where the user will have to choose direction

	//Exit near to Hospital exit[8]
	strcpy_s(exit[8].name, "Street");
	strcpy_s(exit[8].north, "Hospital");
	strcpy_s(exit[8].west, "Nothing");
	strcpy_s(exit[8].south, "There's a wall");
	strcpy_s(exit[8].east, "Street");
	//Exit near to house 1 exit[9]
	strcpy_s(exit[9].name, "Street");
	strcpy_s(exit[9].north, "There's a wall");
	strcpy_s(exit[9].west, "Street");
	strcpy_s(exit[9].south, "There's a wall");
	strcpy_s(exit[9].east, "House 1");
	//Exit near to the school exit[9]
	strcpy_s(exit[10].name, "Street");
	strcpy_s(exit[10].north, "There's a wall");
	strcpy_s(exit[10].west, "School");
	strcpy_s(exit[10].south, "There's a wall That you have to pass trough");
	strcpy_s(exit[10].east, "There's a wall");
	//Exit near to the wall you have to pass 1 exit[11]
	strcpy_s(exit[11].name, "Street");
	strcpy_s(exit[11].north, "There's a wall");
	strcpy_s(exit[11].west, "Street");
	strcpy_s(exit[11].south, "There's a wall");
	strcpy_s(exit[11].east, "House 1");
	//Exit near to house 2, shop exit[12]
	strcpy_s(exit[12].name, "Street");
	strcpy_s(exit[12].north, "There's a wall");
	strcpy_s(exit[12].west, "Shop or Park");
	strcpy_s(exit[12].south, "House 3");
	strcpy_s(exit[12].east, "House 2");


}
