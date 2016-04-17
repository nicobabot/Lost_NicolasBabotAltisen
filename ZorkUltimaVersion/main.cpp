#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"memleaks.h"

int main(){
	ReportMemoryLeaks();
	World world;
	world.createworld();
	world.movement();
	system("pause");
	return 0;
}



