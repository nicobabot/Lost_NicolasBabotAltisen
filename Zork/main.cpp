#include<stdio.h>
#include<stdlib.h>
#include"World.h"
using namespace std;
int main(){
	World world;
	Exits exits;
	world.createworld();
	int r;
	char direc;
	r = 8;
	int temp=0;

	do{
		printf("Where do you want to go (n/s/e/w/q)?\n");
		fflush(stdin);
		scanf_s("%c", &direc);//direcction
		temp = r;
	
		switch (direc){
		case 'n'://North
			printf("%s\n", (((world.exit)+r)->north));
			if (((world.exit) + r)->changeroomnorth == 100){
				system("pause");
				exit(0);
			}
			if (((world.exit) + r)->changeroomnorth == '*'){
				world.enterinhouse(temp);
			}
			if (((world.exit) + r)->changeroomnorth != '-' && ((world.exit) + r)->changeroomnorth != '*'){
				r = ((world.exit) + r)->changeroomnorth;//change room
			}
		
			break;


		case 'e'://East
			printf("%s\n", (((world.exit) + r)->east));
			if (((world.exit) + r)->changeroomeast == 100){
				system("pause");
				exit(0);
			}
			if (((world.exit) + r)->changeroomeast == '*'){
				world.enterinhouse(temp);
			}
			if (((world.exit) + r)->changeroomeast != '-' && ((world.exit) + r)->changeroomeast != '*'){
				r = ((world.exit) + r)->changeroomeast;//change room
			}
			break;

		case 's'://South
			printf("%s\n", (((world.exit) + r)->south));
			if (((world.exit) + r)->changeroomsouth == 100){
				system("pause");
				exit(0);
			}
			if (((world.exit) + r)->changeroomsouth == '*'){
				world.enterinhouse(temp);
			}
			if (((world.exit) + r)->changeroomsouth != '-' && ((world.exit) + r)->changeroomsouth != '*'){
				r = ((world.exit) + r)->changeroomsouth;//change room
			}
			break;

		case 'w'://West
			printf("%s\n", (((world.exit) + r)->west));
			if (((world.exit) + r)->changeroomwest == 100){
				system("pause");
				exit(0);
			}
			if (((world.exit) + r)->changeroomwest == '*'){
				world.enterinhouse(temp);
			}
			if (((world.exit) + r)->changeroomwest != '-' && ((world.exit) + r)->changeroomwest != '*'){
				r = ((world.exit) + r)->changeroomwest;//change room
			}
			break;

		case 'q':
			break;//quit

		default:
			printf("What?");//if user ask for another character
	
		}
	} while (direc != 'q');




	system("pause");
	return 0;
}



