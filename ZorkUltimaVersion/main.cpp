#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
int main(){
	World world;
	int fpos = 0;
	world.createworld();
	do{
		world.movement();
	} while (1);
	system("pause");
	return 0;




}



