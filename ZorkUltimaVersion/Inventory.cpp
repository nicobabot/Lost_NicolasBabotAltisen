#include"Inventory.h"
#include"item.h"
#include"World.h"
#include"Inventory.h"
inventory::inventory(){
}
inventory::~inventory(){
	
}

void World::pick(mystring* string){
	char object[10];
	int maximum = 0;
	if (*string == "pick"){
		printf("what do you want to pick?\n");
		string->set();
	}
	else if (*string == "pick ladder"){
		if (maximum == 3){
			printf("You have full inventary");
		}
		else{
			invent->tfladder = true;
			maximum++;
		}
	}
	else if (*string == "pick wrench"){
		if (maximum == 3){
			printf("You have full inventary");
		}
		else{
			invent->tfwrench = true;
			maximum++;
		}
	}
	else if (*string == "pick money"){
		if (maximum == 3){
			printf("You have full inventary");
		}
		else{
			invent->tfmoney = true;
			maximum++;
		}
	}
	else if (*string == "pick tickets"){
		if (maximum == 3){
			printf("You have full inventary");
		}
		else{
			invent->tftickets = true;
			maximum++;
		}
	}
	else if (*string == "pick key"){
		if (maximum == 3){
			printf("You have full inventary");
		}
		else{
			invent->tfkey = true;
			maximum++;
		}
	}
	else if (*string == "pick map"){
		if (maximum == 3){
			printf("You have full inventary");
		}
		else{
			invent->tfmap = true;
			maximum++;
		}
	}
	else{
		printf("What?\n");
	}
}