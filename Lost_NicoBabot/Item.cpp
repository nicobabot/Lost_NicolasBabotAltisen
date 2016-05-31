#include"item.h"
#include"World.h"

Item::Item(char* name, char* description, Room* position, bool invent, bool equiped, bool inbox, TYPE type) : Entity(name, description, type)
{
	this->itempos = position;
	this->inventory = invent;
	this->equipped = equiped;
	this->inbox = inbox;
}
Item::~Item(){
	
}
void Item::itemsroom(){//this is a function that in all moment is printing what objects ar in the room and then the user don't have to say look
	int j = 0, i = 0;
	if (world->player->position->list.first != nullptr){
		Dlist<Entity*>::DNode* temp = world->player->position->list.first;
		printf("\nIn this room there is:\n");
		for (; temp != nullptr; temp = temp->next){
			printf("%s\n", temp->data->name.C_Str());

			if (world->box->list.first != nullptr && temp->data->list.first){
				Dlist<Entity*>::DNode* temp2 = world->box->list.first;
				printf("\nIn the box there is:\n");
				for (; temp2 != nullptr; temp2 = temp2->next){
					printf("%s\n", temp2->data->name.C_Str());
				}
			}
		}
	}
	else{
		printf("In this room there aren't any items");
	}

}
void Item::map()const{//This function is the special feature, prints the map if you pick the map and tells you where are you
	Dlist<Entity*>::DNode* temp = world->player->list.first;
	for (; temp != nullptr; temp = temp->next){

		if (temp->data->name == "map"){//if you have the map
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
			printf("YOU ARE IN %s", world->player->position->name);
			return;
		}

		
	}
	printf("You can't do this");
}
