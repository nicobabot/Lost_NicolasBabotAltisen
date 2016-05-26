#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"Creature.h"
#include"item.h"



void Player::pick(const Vector<mystring>& options){
	int maximum = 0;
if (options.size() > 1){

		if (world->player->position->list.first != nullptr){
			Dlist<Entity*>::DNode* temp = world->player->position->list.first;
			for (; temp != nullptr; temp = temp->next){
				if (options[1] == temp->data->name && temp->data->Typeobj== ITEM){
					printf("%s\n %s\n", temp->data->name.C_Str(), temp->data->descrip.C_Str());
					world->player->list.pushback(temp->data);
					//temp->data->list.erase(temp);
					world->player->position->list.erase(temp);
					break;
				}
			}
		}
		else{
			printf("This item isn't here");
		}
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
				((Item*)temp->data)->equipped == true;
				printf("You have equiped %s\n", temp->data->name.C_Str());
				world->maxinventory--;
				world->maxequiped++;//maximum equiped
				if ((temp->data->name.C_Str() == (world->entities[46]->name.C_Str()))){
					world->player->damage += 30;
					printf("You have %i of damage", world->player->damage);
				}
			//	world->item->equip.pushback(temp->data);
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
	if (world->item->equip.first != nullptr){
		Dlist<Entity*>::DNode* temp = world->item->equip.first;
		for (; temp != nullptr; temp = temp->next){
			if (options[1] == world->player->list.first->data->name && ((Item*)temp->data)->equipped == true && world->maxequiped == 1){//if the item isn't equipped and is in the inventory
				((Item*)temp->data)->equipped == false;
				printf("You have unequip: %s\n", temp->data->name.C_Str());
				world->maxinventory++;
				world->maxequiped--;//maximum equiped
				if ((temp->data->name.C_Str() == (world->entities[46]->name.C_Str()))){
					world->player->damage -= 30;
					printf("You have %i of damage", world->player->damage);
				}
				world->player->list.pushback(temp->data);
				//world->item->equip.erase(temp);
				break;

			}
		}
	}
	
	
	
	
	
	
	
	
	
	/*if (options.size() > 1){
		for (int i = 0; i < world->entities.size(); i++){
			if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->equipped == false && ((Item*)world->entities[i])->inventory == false){//if the item isn't in the inventory
				printf("You don't have this item in the inventory");
				return;
			}

			else if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->equipped == true && ((Item*)world->entities[i])->inventory == false){//if the item is in the inventory and equipped
				((Item*)world->entities[i])->equipped = false;
				((Item*)world->entities[i])->inventory = true;
				printf("You have unequiped %s\n", ((Item*)world->entities[i])->name.C_Str());
				world->maxequiped--;
				world->maxinventory++;
				return;
			}

		}
	}*/
}






	void Player::put(const Vector<mystring>& options){//
	int maximum = 0;

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


	}

}


void Player::get(const Vector<mystring>& options){
	int maximum = 0;
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
	}
}



