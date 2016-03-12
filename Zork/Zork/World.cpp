#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>

World::World(){
	room = new Rooms[7];
	exit = new Exits[13];
}
World::~World(){
	delete[] room;
	delete[] exit;
}

void World::createworld(){
	//House 1 inside House[0]
	strcpy_s((room+0)->name, "House 1");
	strcpy_s((room + 0)->descriptions, "In this house there is only a woman tell you that near her house there's a school, and also she that she has a ladder. If you want to continue serching go out of the house.");
	strcpy_s(room[0].north, "Exit");
	strcpy_s(room[0].west, "There's a wall");
	strcpy_s(room[0].south, "There's a wall");
	strcpy_s(room[0].east, "There's a wall");
	strcpy_s(room[0].up, "You can't go up");
	strcpy_s(room[0].down, "You can't go down");
	//House 1 Exit exit[0]
	strcpy_s(exit[0].name, "Street");
	strcpy_s(exit[0].north, "There's a wall");
	strcpy_s(exit[0].west, "Street");
	strcpy_s(exit[0].south, "House 1");
	strcpy_s(exit[0].east, "School");
	exit[0].changeroomnorth = '-';
	exit[0].changeroomwest = 9;
	exit[0].changeroomsouth = '-';//house 1
	exit[0].changeroomeast = 1;
	
	//School room[1]
	strcpy_s(room[1].name, "School");
	strcpy_s(room[1].descriptions, "There's a girl and she want to talk with you.");
	strcpy_s(room[1].north, "Exit");
	strcpy_s(room[1].west, "There's a wall");
	strcpy_s(room[1].south, "There's a wall");
	strcpy_s(room[1].east, "There's a wall");
	strcpy_s(room[1].up, "First floor");
	strcpy_s(room[1].down, "You can't go down");
	//School Exit exit[1]
	strcpy_s(exit[1].name, "Street");
	strcpy_s(exit[1].north, "There's a wall");
	strcpy_s(exit[1].west, "House 1");
	strcpy_s(exit[1].south, "School");
	strcpy_s(exit[1].east, "Street");
	exit[1].changeroomnorth = '-';
	exit[1].changeroomwest = 0;
	exit[1].changeroomsouth = '-';//school
	exit[1].changeroomeast = 10;
	//House 2 room[2]
	strcpy_s(room[2].name, "House 2,");
	strcpy_s(room[2].descriptions, "An old man explain information about the family of the house three.The family three controls the city and may have the key to unlock the doors that are next to his house. And the old man will offer to the boy a wrench and he will say : the streets are dangerous if a young boy goes alone.");
	strcpy_s(room[2].north, "Exit");
	strcpy_s(room[2].west, "There's a wall");
	strcpy_s(room[2].south, "There's a wall");
	strcpy_s(room[2].east, "There's a wall");
	strcpy_s(room[2].up, "You can't go up");
	strcpy_s(room[2].down, "You can't go down");
	
	//House 2 Exit exit[2]
	strcpy_s(exit[2].name, "Street");
	strcpy_s(exit[2].north, "There's a wall");
	strcpy_s(exit[2].west, "Shop / Park");
	strcpy_s(exit[2].south, "House 2");
	strcpy_s(exit[2].east, "Street");
	exit[4].changeroomnorth = '-';//cinema
	exit[4].changeroomwest = 12;
	exit[4].changeroomsouth = 2;//house 2
	exit[4].changeroomeast = 10;
	//Shop room[3]
	strcpy_s(room[3].name, "Shop,");
	strcpy_s(room[3].descriptions, "The seller gives you money because he is sad because you are lost.");
	strcpy_s(room[3].north, "There's a wall");
	strcpy_s(room[3].west, "There's a wall");
	strcpy_s(room[3].south, "Exit");
	strcpy_s(room[3].east, "There's a wall");
	strcpy_s(room[3].up, "You can't go up");
	strcpy_s(room[3].down, "You can't go down");
	//shop Exit exit[3]
	strcpy_s(exit[3].name, "Street");
	strcpy_s(exit[3].north, "Shop");
	strcpy_s(exit[3].west, "A door closed");
	strcpy_s(exit[3].south, "Park");
	strcpy_s(exit[3].east, "Street");
	exit[7].changeroomnorth = '-';//shop
	exit[7].changeroomwest = 100;
	exit[7].changeroomsouth = '-';
	exit[7].changeroomeast = 12;
	//cinema room[4]
	strcpy_s(room[4].name, "Cinesa");
	strcpy_s(room[4].descriptions, "If you buy my ticket i will tell you where is the house 3 where you cand find the key to enter to your house.");
	strcpy_s(room[4].north, "There's a wall");
	strcpy_s(room[4].west, "There's a wall");
	strcpy_s(room[4].south, "Exit");
	strcpy_s(room[4].east, "There's a wall");
	strcpy_s(room[4].up, "You can't go up");
	strcpy_s(room[4].down, "You can't go down");
	
	//cinema Exit exit[4]
	strcpy_s(exit[4].name, "Street");
	strcpy_s(exit[4].north, "Cinema");
	strcpy_s(exit[4].west, "House 3");
	strcpy_s(exit[4].south, "There is a wall");
	strcpy_s(exit[4].east, "Park 2");
	exit[4].changeroomnorth = '-';//cinema
	exit[4].changeroomwest = 5;
	exit[4].changeroomsouth = '-';
	exit[4].changeroomeast = 6;
	//House 3 room[5]
	strcpy_s(room[5].name, "House 3");
	strcpy_s(room[5].descriptions, "Its seems that there is something important...");
	strcpy_s(room[5].north, "Exit");
	strcpy_s(room[5].west, "There's a wall");
	strcpy_s(room[5].south, "The key");
	strcpy_s(room[5].east, "There's a wall");
	strcpy_s(room[5].up, "You can't go up");
	strcpy_s(room[5].down, "You can't go down");
	
	//House 3 Exit exit[5]
	strcpy_s(exit[5].name, "Street");
	strcpy_s(exit[5].north, "Street");
	strcpy_s(exit[5].west, "There's a door closed");
	strcpy_s(exit[5].south, "House 3");
	strcpy_s(exit[5].east, "Cinema");
	exit[5].changeroomnorth = 12;
	exit[5].changeroomwest = 100;//door
	exit[5].changeroomsouth = '-';//house 3
	exit[5].changeroomeast = 4;
	//Park 2 room[6]
	strcpy_s(room[6].name, "Park 2");
	strcpy_s(room[6].descriptions, "Oh no! There is a thug take care!");
	strcpy_s(room[6].north, "There's a wall");
	strcpy_s(room[6].west, "Exit");
	strcpy_s(room[6].south, "There's a wall");
	strcpy_s(room[6].east, "There's a wall");
	strcpy_s(room[6].up, "You can't go up");
	strcpy_s(room[6].down, "You can't go down");
	
	//Park 2 Exit exit[6]
	strcpy_s(exit[6].name, "Street");
	strcpy_s(exit[6].north, "Street");
	strcpy_s(exit[6].west, "Cinema");
	strcpy_s(exit[6].south, "There's a wall");
	strcpy_s(exit[6].east, "Park 2");
	exit[6].changeroomnorth = 11;
	exit[6].changeroomwest = 5;//house 3
	exit[6].changeroomsouth = '-';
	exit[6].changeroomeast = '-';//park 2
	

	//We need 5 "exits" that are streets because in the maps there are points where the user will have to choose direction
	
	//Exit near to Hospital exit[8]
	strcpy_s(exit[8].name, "Street");
	strcpy_s(exit[8].north, "Hospital, you can't enter");
	strcpy_s(exit[8].west, "Nothing");
	strcpy_s(exit[8].south, "There's a wall");
	strcpy_s(exit[8].east, "Street");
	exit[8].changeroomnorth = '-';
	exit[8].changeroomwest = '-';
	exit[8].changeroomsouth = '-';
	exit[8].changeroomeast = 9;
	//Exit near to house 1 exit[9]
	strcpy_s(exit[9].name, "Street");
	strcpy_s(exit[9].north, "There's a wall");
	strcpy_s(exit[9].west, "Street");
	strcpy_s(exit[9].south, "There's a wall");
	strcpy_s(exit[9].east, "House 1");
	exit[9].changeroomnorth = '-';
	exit[9].changeroomwest = 8;
	exit[9].changeroomsouth = '-';
	exit[9].changeroomeast = 0;
	//Exit near to the school exit[10]
	strcpy_s(exit[10].name, "Street");
	strcpy_s(exit[10].north, "There's a wall");
	strcpy_s(exit[10].west, "School");
	strcpy_s(exit[10].south, "There's a wall That you have to pass trough");
	strcpy_s(exit[10].east, "There's a wall");
	exit[10].changeroomnorth = '-';
	exit[10].changeroomwest = 1;//school
	exit[10].changeroomsouth = 11;
	exit[10].changeroomeast = '-';
	//Exit near to the wall you have to pass 1 exit[11]
	strcpy_s(exit[11].name, "Street");
	strcpy_s(exit[11].north, "There's a wall");
	strcpy_s(exit[11].west, "Street");
	strcpy_s(exit[11].south, "There's a wall");
	strcpy_s(exit[11].east, "House 1");
	exit[11].changeroomnorth = 10;
	exit[11].changeroomwest = 2;//house 2
	exit[11].changeroomsouth = 6;//park 2
	exit[11].changeroomeast = '-';
	//Exit near to house 2, shop exit[12]
	strcpy_s(exit[12].name, "Street");
	strcpy_s(exit[12].north, "There's a wall");
	strcpy_s(exit[12].west, "Shop or Park");
	strcpy_s(exit[12].south, "House 3");
	strcpy_s(exit[12].east, "House 2");
	exit[12].changeroomnorth = '-';
	exit[12].changeroomwest = 7;// 3 and 7
	exit[12].changeroomsouth = 5;//house 3
	exit[12].changeroomeast = 2;


}
