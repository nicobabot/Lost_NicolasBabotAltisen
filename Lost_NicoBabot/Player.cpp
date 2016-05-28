#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"Creature.h"
#include"item.h"
#include "conio.h"
#include <Windows.h>
#define COMMANDBUFFER 50



void Player::pick(const Vector<mystring>& options){
	int maximum = 0;
if (options.size() > 1){

		if (world->player->position->list.first != nullptr){
			Dlist<Entity*>::DNode* temp = world->player->position->list.first;
			for (; temp != nullptr; temp = temp->next){
				if (options[1] == temp->data->name && temp->data->Typeobj== ITEM){
					if (options[1] == "money"){
						printf("You can't!");
						return;
					}
					printf("%s\n %s\n", temp->data->name.C_Str(), temp->data->descrip.C_Str());
					world->player->list.pushback(temp->data);
					//temp->data->list.erase(temp);
					world->player->position->list.erase(temp);
					return;
				}
			}
		}
			printf("This item isn't here");
	}

}




void Player::drop(const Vector<mystring>& options){

	if (options.size() > 1){

		if (world->player->list.first != nullptr){
			Dlist<Entity*>::DNode* temp = world->player->list.first;
			for (; temp != nullptr; temp = temp->next){
				if (options[1] == temp->data->name && temp->data->Typeobj == ITEM){
					printf("You dropped: %s\n", temp->data->name.C_Str());
					world->player->position->list.pushback(temp->data);
					world->player->list.erase(temp);
					break;
				}
			}
		}
		else{
			printf("You don't have this item");
		}
	}

}

void Player::equip(const Vector<mystring>& options){

	if (world->player->list.first != nullptr){
		Dlist<Entity*>::DNode* temp = world->player->list.first;
		for (; temp != nullptr; temp = temp->next){
			if (options[1] == world->player->list.first->data->name && ((Item*)temp->data)->equipped == false && world->maxequiped == 0){//if the item isn't equipped and is in the inventory
				((Item*)temp->data)->equipped = true;
				printf("You have equiped %s\n", temp->data->name.C_Str());
				world->maxinventory--;
				world->maxequiped++;//maximum equiped
				if ((temp->data->name.C_Str() == (world->entities[46]->name.C_Str()))){
					world->player->damage += 30;
					printf("You have %i of damage", world->player->damage);
				}
				equipedlist.pushback(temp->data);
				world->player->list.erase(temp);
				break;

			}
		}
	}
	else{
		printf("You don't have this item");
	}
	}

void Player::unequip(const Vector<mystring>& options){
	if (equipedlist.first != nullptr){
		Dlist<Entity*>::DNode* temp = equipedlist.first;
		for (; temp != nullptr; temp = temp->next){
			if (((Item*)temp->data)->equipped == true && world->maxequiped == 1){
				((Item*)temp->data)->equipped == false;
				world->maxinventory++;
				world->maxequiped--;//maximum equiped
				world->player->list.pushback(temp->data);
				printf("You unequip: %s", temp->data->name.C_Str());
				equipedlist.erase(temp);
				break;
			}
			else{
				printf("You have one item already equipped");
			}
		}
	}
}


	void Player::put(const Vector<mystring>& options){//
		if (options.size() > 3){
			Dlist<Entity*>::DNode* temp = world->box->list.first;
			Dlist<Entity*>::DNode* temp2 = world->player->list.first;
			if (temp == nullptr){
				for (int i = 0; i < world->entities.size(); i++){
					if (options[1] == (world->entities[i])->name && options[3] == "box"){
						for (; temp2 != nullptr; temp2 = temp2->next){
							if (((Item*)world->entities[i])->name.C_Str() == temp2->data->name.C_Str()){
								world->box->list.pushback(temp2->data);
								world->maxinventory--;
								printf("you put %s into box", temp2->data->name.C_Str());
								world->player->list.erase(temp2);
								return;
							}
						}
					}
				}
			}
			printf("You need to have the item in the inventory");
		}
		else{
			printf("What?\n");
		}
		
		
		/*int maximum = 0;

	for (int i = 0; i < world->entities.size(); i++){

		if (world->maxbox == 2){//the box only can have two items
			printf("In the box you only can put two items");
			return;
		}
		else if (options[1] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[BOX])->itempos == world->player->position){//if the player try to put the box into the box
			printf("You can't do this");
			return;
		}
		else if (options[1] == ((Item*)world->entities[i])->name && options[3] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[i])->itempos == world->player->position && ((Item*)world->entities[i])->itempos == ((Item*)world->entities[BOX])->itempos && ((Item*)world->entities[i])->inbox == false && world->maxbox <3){//puts an item iside the box
			if (((Item*)world->entities[i])->inventory == true){
				((Item*)world->entities[i])->inventory = false;
				world->maxinventory--;
			}
			if (((Item*)world->entities[i])->equipped == true){
				((Item*)world->entities[i])->equipped == false;
				world->maxequiped--;
			}

			((Item*)world->entities[i])->inbox = true;//puts the item in the box
			((Item*)world->entities[i])->itempos = ((Item*)world->entities[BOX])->itempos;//change the position of the object to the box direction
			printf("You have put %s into the box", ((Item*)world->entities[i])->name.C_Str());
			world->maxbox++;//maximum of items
			return;
		}

		else if (options[1] == ((Item*)world->entities[i])->name && options[3] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[i])->itempos != ((Item*)world->entities[BOX])->itempos && ((Item*)world->entities[i])->inbox == false){//if the object isn't there
			printf("This item isn't here");
			return;
		}
		else if (options[1] == ((Item*)world->entities[i])->name && options[3] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[i])->inbox == true && ((Item*)world->entities[i])->itempos == ((Item*)world->entities[BOX])->itempos){//if this item its in the box
			printf("This item is in the box you should get it from there");
			return;
		}


	}*/

}


void Player::get(const Vector<mystring>& options){

	if (options.size() > 3){
		Dlist<Entity*>::DNode* temp = world->box->list.first;
		Dlist<Entity*>::DNode* temp2 = world->player->list.first;
		if (temp != nullptr){
			for (int i = 0; i < world->entities.size(); i++){
				if (options[1] == (world->entities[i])->name && options[3] == "box"){
					for (; temp != nullptr; temp = temp->next){
						if (((Item*)world->entities[i])->name.C_Str() == temp->data->name.C_Str()){
							world->player->list.pushback(temp->data);
							world->maxinventory++;
							printf("you get %s from box", temp->data->name.C_Str());
							world->box->list.erase(temp);
							return;
						}
					}
				}
			}
		}
		printf("The item is not in the box");
	}
	else{
		printf("What?\n");
	}







	/*int maximum = 0;
	if (options.size() > 1){
		for (int i = 0; i < NUM_ITEM; i++){
			if (options[1] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[BOX])->itempos == world->player->position){//if you try to get the box from the box
				printf("You can't do this");
				return;
			}
			else if (options[1] == ((Item*)world->entities[i])->name && options[3] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[i])->itempos == ((Item*)world->entities[BOX])->itempos && world->player->position == ((Item*)world->entities[BOX])->itempos && ((Item*)world->entities[i])->inbox == true){//to get some item from the box
				((Item*)world->entities[i])->inbox = false;//out of the box
				((Item*)world->entities[i])->inventory = true;//to the inventory
				printf("You have get %s of the box", ((Item*)world->entities[i])->name.C_Str());
				world->maxinventory++;//maximum of inventory
				world->maxbox--;//maximum inside the box
				return;
			}
			else if (((Item*)world->entities[i])->itempos != world->player->position){//if the item isn't there
				printf("This item isn't here");
				return;
			}
		}
	}*/
}



void Player::buy(const Vector<mystring>& options){
	do{
		if (count == 0){
			printf("Hi what do you want to buy?\n");
			printf("You can buy:\n potion\n");
			if (options[0] == "buy" && options[1] == "potion"){
				if (world->player->money < 15){
					printf("you don't have money");
					printf("I think you are lost, don't worry here is some money for you: 30$");
					money += 30;
					Dlist<Entity*>::DNode* temp = world->player->position->list.first;
					for (; temp != nullptr; temp = temp->next){
						if (temp->data->name == "money"){
							world->player->list.pushback(temp->data);
						}
					}

				}
			}





		}
		else{

		}
		count++;
	} while (other == 0);
}