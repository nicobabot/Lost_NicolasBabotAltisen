#include<stdio.h>
#include<stdlib.h>
#include"World.h"
int main(){
	World world;
	
	world.createworld();
	int r;
	char direc;
	int f;
	r = 8;

	do{
		printf("Where do you want to go (n/s/e/w/q)?\n");
		fflush(stdin);
		scanf_s("%c", &direc);//direcction

		switch (direc){
		case 'n'://North
			printf("%s\n", (((world.exit)+r)->north));
			if (((world.exit) + r)->changeroomnorth != '-' && ((world.exit) + r)->changeroomnorth != 100){
				r = ((world.exit) + r)->changeroomnorth;//change room
			}
			else{
				printf("There's a door closed");
			}
			break;

		case 'e'://East
			printf("%s\n", (((world.exit) + r)->east));
			if (((world.exit) + r)->changeroomeast != '-' && ((world.exit) + r)->changeroomeast != 100){
				r = ((world.exit) + r)->changeroomeast;//change room
			}
			else{
				printf("There's a door closed");
			}
			break;

		case 's'://South
			printf("%s\n", (((world.exit) + r)->south));
			if (((world.exit) + r)->changeroomsouth!= '-' && ((world.exit) + r)->changeroomsouth != 100){
				r = ((world.exit) + r)->changeroomsouth;//change room
			}
			else{
				printf("There's a door closed");
			}
			break;

		case 'w'://West
			printf("%s\n", (((world.exit) + r)->west));
			if (((world.exit) + r)->changeroomwest != '-' && ((world.exit) + r)->changeroomwest != 100){
				r = ((world.exit) + r)->changeroomwest;//change room
			}
			else{
				printf("There's a door closed");
			}
			break;

		case 'q':
			break;//quit

		default:
			printf("What?");//if user ask for another character
			system("pause");
		}
	} while (direc != 'q');




	system("pause");
	return 0;
}