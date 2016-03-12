class Rooms{
public:
	//Rooms();
	char name[25];
	char descriptions[300];
	char north[15];
	char west[15];
	char south[15];
	char east[15];
	char up[40];
	char down[40];
	//wall=0
	int changeroomnorth;//1
	int changeroomwest;//2
	int changeroomsouth;//3
	int changeroomeast;
	//~Rooms();
};