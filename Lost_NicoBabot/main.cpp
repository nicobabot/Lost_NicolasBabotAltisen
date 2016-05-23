#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"Room.h"
#include"memleaks.h"
#include "conio.h"
World *world = nullptr;
#define COMMANDBUFFER 50
int main(){
	ReportMemoryLeaks();
	world = new World;
	world->help();
	mystring option;
	char command[COMMANDBUFFER];
	unsigned int charcommandnum = 0;
	char key;
	int x = 0;
	world->createworld();
	while (1){
		if (_kbhit())
		{
			if (charcommandnum < (COMMANDBUFFER - 2)){
				
				command[charcommandnum] = _getch();
				key = command[charcommandnum];
				printf("%c", key);
				command[charcommandnum + 1] = '\0';
				//printf("String: %s\n", command);
				charcommandnum++;
				
				if (command[charcommandnum - 1] == '\r'){
					//printf("Your command is: %s\n", command);
					command[charcommandnum - 1] = '\0';
					charcommandnum = 0;
					option = command;
					Vector<mystring> tokoption = option.Tokenize(" ", command);
					world->movement(tokoption);
					if (world->q != 0 || world->player->playerposit == world->entities[8]){
						printf("THANK YOU FOR PLAYING THE GAME");
						system("pause");
						return 0;
					}
					//tokoption.clean();
				}
			}
			else{
				command[COMMANDBUFFER - 1] = '\0';
			}
		}
	}
	system("pause");
	return 0;
}



