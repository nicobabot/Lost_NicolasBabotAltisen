#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"Room.h"
#include"memleaks.h"
#include "conio.h"
#include <Windows.h>
World *world = nullptr;
#define COMMANDBUFFER 50
#define DELAY 1000
int main(){
	ReportMemoryLeaks();
	world = new World;
	world->help();
	printf("\n");
	mystring option;
	char command[COMMANDBUFFER];
	unsigned int charcommandnum = 0;
	char key;
	int x = 0;
	unsigned int initialtime = 0;
	unsigned int currenttime = 0;
	world->createworld();
	while (1){
		initialtime = GetTickCount();

		while (command != "q\0"){
			currenttime = GetTickCount();
			if (currenttime >= (initialtime + DELAY)){
				initialtime = currenttime;
				for (int i = 0; i < world->entities.size(); i++)
				{
					world->entities[i]->Update();
				}

			}

			if (_kbhit())
			{
				if (charcommandnum < (COMMANDBUFFER - 2)){

					command[charcommandnum] = _getch();
					key = command[charcommandnum];
					printf("%c", key);
					command[charcommandnum + 1] = '\0';
				
					charcommandnum++;

					if (command[charcommandnum - 1] == '\b'){
						if (charcommandnum>1){
							charcommandnum--;
							charcommandnum--;
						}
						else{
							charcommandnum--;
						}

					}
					if (command[charcommandnum - 1] == '\r'){
					
						command[charcommandnum - 1] = '\0';
						charcommandnum = 0;
						option = command;
						Vector<mystring> tokoption = option.Tokenize(" ", command);
						if (tokoption.size() >= 1){
							world->movement(tokoption);
						}
						
						//tokoption.clean();
					}
					/*else if (key == '\b' && charcommandnum > 0){
						charcommandnum--;
						charcommandnum--;
					}*/
				}
				else{
					command[charcommandnum - 1] = '\0';
					charcommandnum = 0;
				}
			}
			if (world->q != 0 || world->player->position == world->entities[8] || world->player->pdead == true){
				printf("THANK YOU FOR PLAYING THE GAME\n");
				system("pause");
				return 0;
			}

		}
	}
	system("pause");
	return 0;
}



