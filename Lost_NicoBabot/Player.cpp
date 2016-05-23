#include<stdio.h>
#include<stdlib.h>
#include"World.h"

Player::Player(const char* name, const char* descrip, TYPE Typeobj, Room* pos): Entity(name, descrip, Typeobj), playerposit(pos){

}


void Player::pick(const Vector<mystring>& options){
	int maximum = 0;
	if (options.size() > 1){
		for (int i = 0; i < world->entities.size(); i++){
			if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->itempos == world->player->playerposit && ((Item*)world->entities[i])->inventory == false && ((Item*)world->entities[i])->equipped == false && ((Item*)world->entities[i])->inbox == false && world->maxinventory<4){//look name and position, look inventory, look if its equipped and if its the maximum
				if (options[1] == ((Item*)world->entities[TICKET])->name){//if the user wants to take the ticket they will have to have money 
					if (((Item*)world->entities[MONEY])->inventory == false){//false
						printf("You don't have money\n");
						return;
					}
					else{//true, if its true user loses the money
						((Item*)world->entities[MONEY])->inventory == false;
						printf("You have given the money to have some information\n");
						printf("If you go south you will find the park and near you will find House 3");
						world->maxinventory--;
						return;
					}
				}
				((Item*)world->entities[i])->inventory = true;//pick the object
				printf("%s\n %s\n", ((Item*)world->entities[i])->name.C_Str(), ((Item*)world->entities[i])->descrip.C_Str());
				world->maxinventory++;//the maximum of the inventory
				return;
			}
			else if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->itempos != world->player->playerposit){//if the object isn't there
				printf("The item isn't here");
				return;
			}
			else if (world->maxinventory > 3){//if the inventory is full
				printf("You have full inventory you should drop an item");
				return;
			}
		}
	}

}

void Player::inventory(){
	int i;
	int temp=0;
	for (i = 0; i < world->entities.size(); i++){
		if (((Item*)world->entities[i])->inventory == true){//print the items that are in the inventory
			printf("You have in the inventory:");
			printf("%s\n", ((Item*)world->entities[i])->name.C_Str());
		}
		else{
			temp++;
		}
	}
	if (temp == world->entities.size()){
		printf("You have nothing");
	}

}


void Player::drop(const Vector<mystring>& options){

	if (options.size() > 1){
		for (int i = 0; i < world->entities.size(); i++){

			if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->inventory == false){//it the item isn't in the inventory
				printf("You don't have the item in the inventory");
				return;
			}
			else if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->itempos == world->player->playerposit && ((Item*)world->entities[i])->inventory == true){//drop the item
				if (((Item*)world->entities[i])->inventory == true){//item of the inventory droped
					((Item*)world->entities[i])->inventory = false;
				}
				else if (((Item*)world->entities[i])->equipped == true){//item equipped droped
					((Item*)world->entities[i])->equipped == false;
					world->maxequiped--;
				}
				printf("You have droped %s\n", ((Item*)world->entities[i])->name.C_Str());
				world->maxinventory--;//one less in the inventory
				return;
			}

		}
	}
}

void Player::equip(const Vector<mystring>& options){


	for (int i = 0; i < world->entities.size(); i++){
		if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->inventory == false){//if user don't have the item in the inventory
			printf("You don't have this item in the inventory");
			return;
		}
		else if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->equipped == false && ((Item*)world->entities[i])->inventory == true && world->maxequiped == 0){//if the item isn't equipped and is in the inventory
			((Item*)world->entities[i])->equipped = true;//if its equipped its not in the inventory
			((Item*)world->entities[i])->inventory = false;
			printf("You have equiped %s\n", ((Item*)world->entities[i])->name.C_Str());
			world->maxinventory--;
			world->maxequiped++;//maximum equiped
			return;
		}
		else if (options[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->equipped == false && ((Item*)world->entities[i])->inventory == true && world->maxequiped > 0){//if there is one item equipped
			printf("You already have one item equiped");
			return;
		}
	}
}

void Player::put(const Vector<mystring>& options){//
	int maximum = 0;

	for (int i = 0; i < world->entities.size(); i++){

		if (world->maxbox == 2){//the box only can have two items
			printf("In the box you only can put two items");
			return;
		}
		else if (options[1] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[BOX])->itempos == world->player->playerposit){//if the player try to put the box into the box
			printf("You can't do this");
			return;
		}
		else if (options[1] == ((Item*)world->entities[i])->name && options[3] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[i])->itempos == world->player->playerposit && ((Item*)world->entities[i])->itempos == ((Item*)world->entities[BOX])->itempos && ((Item*)world->entities[i])->inbox == false && world->maxbox <3){//puts an item iside the box
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

void Player::unequip(const Vector<mystring>& options){

	if (options.size() > 1){
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
	}
}

void Player::get(const Vector<mystring>& options){
	int maximum = 0;
	if (options.size() > 1){
		for (int i = 0; i < NUM_ITEM; i++){
			if (options[1] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[BOX])->itempos == world->player->playerposit){//if you try to get the box from the box
				printf("You can't do this");
				return;
			}
			else if (options[1] == ((Item*)world->entities[i])->name && options[3] == ((Item*)world->entities[BOX])->name && ((Item*)world->entities[i])->itempos == ((Item*)world->entities[BOX])->itempos && world->player->playerposit == ((Item*)world->entities[BOX])->itempos && ((Item*)world->entities[i])->inbox == true){//to get some item from the box
				((Item*)world->entities[i])->inbox = false;//out of the box
				((Item*)world->entities[i])->inventory = true;//to the inventory
				printf("You have get %s of the box", ((Item*)world->entities[i])->name.C_Str());
				world->maxinventory++;//maximum of inventory
				world->maxbox--;//maximum inside the box
				return;
			}
			else if (((Item*)world->entities[i])->itempos != world->player->playerposit){//if the item isn't there
				printf("This item isn't here");
				return;
			}
		}
	}


}



