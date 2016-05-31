#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"Creature.h"
#include"item.h"
#include "conio.h"
#include <Windows.h>
#define COMMANDBUFFER 50
#define DELAY 5000


void Player::pick(const Vector<mystring>& options){
	int maximum = 0;
if (options.size() > 1){

		if (world->player->position->list.first != nullptr){//if there aren't any items in the room
			Dlist<Entity*>::DNode* temp = world->player->position->list.first;// to iterate the list
			for (; temp != nullptr; temp = temp->next){
				if (options[1] == temp->data->name && temp->data->Typeobj== ITEM){// if the item that said the user is in the room
					if (options[1] == "ticket"){
						Dlist<Entity*>::DNode* temp3 = world->player->list.first;
						for (; temp3 != nullptr; temp3 = temp3->next){
							if (temp3->data->name == "money"){
								printf("I give you the ticket but i get your money");
								printf("If you go south you will find a park, then at the east there is a house. There you can pick one key that will let you enter to your house");
								world->player->money = 0;
								world->player->list.erase(temp3);
								world->player->list.pushback(temp->data);
								return;
							}
						}
						printf("you don't have money, you can't pick the ticket");
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
			if (options[1] == temp->data->name && ((Item*)temp->data)->equipped == false && world->player->maxequiped == 0){//if the item isn't equipped and is in the inventory
				((Item*)temp->data)->equipped = true;
				printf("You have equiped %s\n", temp->data->name.C_Str());
				world->maxinventory--;
				world->player->maxequiped++;//maximum equiped
				if ((temp->data->name.C_Str() == (world->entities[46]->name.C_Str()))){
					world->player->damage += 15;
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
			if (((Item*)temp->data)->equipped == true && world->player->maxequiped == 1 && options[1] == temp->data->name){
				((Item*)temp->data)->equipped == false;
				world->maxinventory++;
				world->player->maxequiped--;//maximum equiped
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
	else{
		printf("You don't have any item");
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


}



void Player::buy(const Vector<mystring>& options){
	bool havemoney = false;
	if (options.size() >= 2){
		if (position == (Room*)world->entities[4]){
			Dlist<Entity*>::DNode* temp = world->player->list.first;
			Dlist<Entity*>::DNode* temp2 = world->seller->list.first;
			Dlist<Entity*>::DNode* temp3 = world->seller->list.first;

			for (; temp != nullptr; temp = temp->next){
				if (temp->data->name == "money"){
					havemoney = true;
				}
			}
			for (; temp3 != nullptr; temp3 = temp3->next){
				if (temp3->data->name == "money"){
					break;
				}
			}
			if (havemoney){
				printf("All costs 10 $");
				for (; temp2 != nullptr; temp2 = temp2->next){
					
				
				if (options[0] == "buy" && options[1] == temp2->data->name){
					if (options[1] == "money"){
						printf("You can't buy money");
						return;
					}
					if (money > 10){
						money -= 10;
						printf("You bought %s", temp2->data->name.C_Str());

						for (; temp2 != nullptr; temp2 = temp2->next){
							if (temp2->data->name == options[1]){
								world->player->list.pushback(temp2->data);
								world->seller->list.erase(temp2);
								world->maxinventory++;
								return;
							}
						}
							
						}
					}
				}
			}
			else{
				printf("You don't have money\n");
				printf("I am sad for you, have this money\n");
				printf("You get 20$\n");
				money += 20;
				world->maxinventory++;
				world->player->list.pushback(temp3->data);
				return;
			}
		}
	}
}
		

void Player::attack(const Vector<mystring>& options){
	Actualtime = GetTickCount();
	if (options.size() >= 2){
		if (options[1] == world->thug->name && options[0] == "attack"){
				printf("You hit the thug for %i", damage);
				world->thug->health -= damage;
				return;
			}
			else if (options[0] == "kick" && options[1] == world->thug->name && Actualtime >= SpecialAttackTimer+DELAY){
				SpecialAttackTimer = Actualtime;
				world->thug->health -= damage+15;
				printf("You use special attack,you do %i of damage and now you have %i s of cooldown", damage + 20, (DELAY / 1000) - ((Actualtime - SpecialAttackTimer)/1000));
				return;
			}
			else if (options[0] == "kick" && options[1] == world->thug->name && Actualtime < SpecialAttackTimer + DELAY){
				printf("THIS ATTACK IS IN COOLDOWN");
			
			}
			
			else{
				printf("The character isn't here");
			}
	}

}

void Player::use(const Vector<mystring>& options){
	if (options.size() >= 2){
		if (world->thug->state == FIGHT){
			Dlist<Entity*>::DNode* temp = world->player->list.first;
			for (; temp != nullptr; temp = temp->next){
				if (options[1]=="potion" && temp->data->name == "potion" && temp->data->Typeobj == ITEM){
					if (health += 20 < 100){
						health += 20;
					}
					else{
						health = 100;
					}
					printf("You use potion and heal 20 hp, now you have %i", health);
					world->player->list.erase(temp);
					break;
				}
			}
		}
	}
}

void Player::sell(const Vector<mystring>& options){

	bool havemoney = false;
	if (options.size() >= 2){
		if (position == (Room*)world->entities[4]){
			Dlist<Entity*>::DNode* temp = world->player->list.first;
			Dlist<Entity*>::DNode* temp2 = world->seller->list.first;
			for (; temp != nullptr; temp = temp->next){
				if (temp->data->name == options[1]){
					printf("You sell %s for 10$", temp->data->name.C_Str());
					money += 10;
					world->seller->list.pushback(temp->data);
					world->player->list.erase(temp);
					return;
				}

			}
		}
	}
}
	






