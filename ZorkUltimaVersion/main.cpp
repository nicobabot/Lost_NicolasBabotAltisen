#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include<string.h>
int main(){
	World world;
	world.createworld();
	world.createitems();
	world.movement();
	system("pause");
	return 0;
}



