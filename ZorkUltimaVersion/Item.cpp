#include"item.h"
#include"World.h"

Item::Item(){
	
}
Item::~Item(){
	
}
void World::createitems(){
	items[LADDER].itempos = &room[1];
	items[LADDER].name = "Ladder";
	items[LADDER].descrip = "A ladder that you can use it to pass walls";
	//-------
	items[WRENCH].itempos = &room[3];
	items[WRENCH].name = "Wrench";
	items[WRENCH].descrip = "You can use the wrench to fight if you have problems";
	//-------
	items[MONEY].itempos = &room[4];
	items[MONEY].name = "Money";
	items[MONEY].descrip = "With this money you can buy somthing";
	//-------
	items[TICKET].itempos = &room[5];
	items[TICKET].name = "Ticket";
	items[TICKET].descrip = "If you have this ticket means that you have some information about house 3";
	//-------
	items[KEY].itempos = &room[7];
	items[KEY].name = "Key";
	items[KEY].descrip = "With this key you can enter to your house!!";
	//-------
	items[MAP].itempos = &room[2];
	items[MAP].name = "Map";
	items[MAP].descrip = "With this special feature if you press you can see the map of the city";
}

void World::pick(mystring* string){
	char object[10];
	int maximum=0;
	if (*string == "pick"){
		printf("what do you want to pick?\n");
		string->set();
	}
	if (*string == "pick ladder" || *string == "ladder"){
		if (items[LADDER].itempos == player->playerposit){
			if (items[LADDER].inventory == false && items->maximum<items->maxequiped){
				items[LADDER].inventory = true;
				printf("%s\n %s\n", items[LADDER].name.C_Str(), items[LADDER].descrip.C_Str());
				items->maximum++;
			}
			else{
				if (items->maximum == 3){
					printf("You have full inventory, you should drop some object\n");
				}
				if (items[LADDER].inventory == true){
					printf("You already have it in your inventory\n");
				}
			}
		
		}

	}
	if (*string == "pick wrench" || *string == "wrench"){
		if (items[WRENCH].itempos == player->playerposit){
			if (items[WRENCH].inventory == false && items->maximum<items->maxequiped){
				items[WRENCH].inventory = true;
				printf("%s\n %s\n", items[WRENCH].name.C_Str(), items[WRENCH].descrip.C_Str());
				items->maximum++;
			}
			else{
				if (items->maxequiped == 3){
					printf("You have full inventory, you should drop some object\n");
				}
				if (items[WRENCH].inventory == true){
					printf("You already have it in your inventory\n");
				}
			}
		}
	}
	if (*string == "pick money" || *string == "money"){
		if (items[MONEY].itempos == player->playerposit){
			if (items[MONEY].inventory == false && items->maximum<items->maxequiped){
				items[MONEY].inventory = true;
				printf("%s\n %s\n", items[MONEY].name.C_Str(), items[MONEY].descrip.C_Str());
				items->maximum++;
			}
			else{
				if (items->maxequiped == 3){
					printf("You have full inventory, you should drop some object\n");
				}
				if (items[MONEY].inventory == true){
					printf("You already have it in your inventory\n");
				}
			}
		}
	}

	if (*string == "pick ticket" || *string == "ticket"){
		if (items[TICKET].itempos == player->playerposit && items->maximum<items->maxequiped){
			if (items[TICKET].inventory == false){
				items[TICKET].inventory = true;
				printf("%s\n %s\n", items[TICKET].name.C_Str(), items[TICKET].descrip.C_Str());
				items->maximum++;
			}
			else{
				if (items->maxequiped == 3){
					printf("You have full inventory, you should drop some object\n");
				}
				if (items[TICKET].inventory == true){
					printf("You already have it in your inventory\n");
				}
			}
		}
	}
	if (*string == "pick key" || *string == "key"){
		if (items[KEY].itempos == player->playerposit && items->maximum<items->maxequiped){
			if (items[KEY].inventory == false){
				items[KEY].inventory = true;
				printf("%s\n %s\n", items[KEY].name.C_Str(), items[KEY].descrip.C_Str());
				items->maximum++;
			}
			else{
				if (items->maxequiped == 3){
					printf("You have full inventory, you should drop some object\n");
				}
				if (items[KEY].inventory == true){
					printf("You already have it in your inventory\n");
				}
			}
		}
	}

	if (*string == "pick map" || *string == "map"){
		if (items[MAP].itempos == player->playerposit && items->maximum<items->maxequiped){
			if (items[MAP].inventory == false){
				items[MAP].inventory = true;
				printf("%s\n %s\n", items[MAP].name.C_Str(), items[MAP].descrip.C_Str());
				items->maximum++;
			}
			else{
				if (items->maxequiped == 3){
					printf("You have full inventory, you should drop some object\n");
				}
				if (items[MAP].inventory == true){
					printf("You already have it in your inventory\n");
				}
			}
		}
	}
}

void World::inventory(){
	int i;
	for (i = 0; i < NUM_ITEM; i++){
		if (items[i].inventory == true){
			printf("You have in the inventory:");
			printf("%s\n", items[i].name.C_Str());
		}
	}

}

void World::drop(mystring *string){

	char object[10];
	int maximum = 0;
	if (*string == "drop"){
		printf("what do you want to drop?\n");
		string->set();
	}
	if (*string == "drop ladder" || *string == "ladder"){
		if (items[LADDER].inventory == true){
			items[LADDER].inventory = false;
			items[LADDER].itempos = player->playerposit;
			printf("You have dropped the %s", items[LADDER].name.C_Str());
			items->maximum++;
		}
		else{
			printf("You don't have this item in the inventary");
		}
	}

	if (*string == "drop wrench" || *string == "wrench"){
		if (items[WRENCH].inventory == true){
			items[WRENCH].inventory = false;
			items[WRENCH].itempos = player->playerposit;
			printf("You have dropped the %s", items[WRENCH].name.C_Str());
			items->maximum++;
		}
		else{
			printf("You don't have this item in the inventary");
		}
	}

	if (*string == "drop money" || *string == "money"){
		if (items[MONEY].inventory == true){
			items[MONEY].inventory = false;
			items[MONEY].itempos = player->playerposit;
			printf("You have dropped the %s", items[MONEY].name.C_Str());
			items->maximum++;
		}
		else{
			printf("You don't have this item in the inventary");
		}
	}
	if (*string == "drop ticket" || *string == "ticket"){
		if (items[TICKET].inventory == true){
			items[TICKET].inventory = false;
			items[TICKET].itempos = player->playerposit;
			printf("You have dropped the %s", items[TICKET].name.C_Str());
			items->maximum++;
		}
		else{
			printf("You don't have this item in the inventary");
		}
	}

	if (*string == "drop key" || *string == "key"){
		if (items[KEY].inventory == true){
			items[KEY].inventory = false;
			items[KEY].itempos = player->playerposit;
			printf("You have dropped the %s", items[KEY].name.C_Str());
			items->maximum++;
		}
		else{
			printf("You don't have this item in the inventary");
		}
	}
	if (*string == "drop map" || *string == "map"){
		if (items[MAP].inventory == true){
			items[MAP].inventory = false;
			items[MAP].itempos = player->playerposit;
			printf("You have dropped the %s", items[MAP].name.C_Str());
			items->maximum++;
		}
		else{
			printf("You don't have this item in the inventary");
		}

	}
}