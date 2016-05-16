#include<stdio.h>
#include<stdlib.h>
#include"World.h"
#include"memleaks.h"
World *world = nullptr;
int main(){
	ReportMemoryLeaks();
	world = new World;
	world->createworld();
	world->movement();
	system("pause");
	return 0;
}



