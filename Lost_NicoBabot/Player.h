#ifndef _PLAYER_
#define _PLAYER_
#include"Room.h"
#include"Creature.h"
#include"Entity.h"
class Player: public Creature{
public:
	Player(const char* name, const char* descrip, const int health, const int damage, const int accuracy, Room* pos) : Creature(name, descrip, health, damage, accuracy, PLAYER, pos){

	}
	//Room *playerposit = nullptr;
	Dlist<Entity*> equipedlist;
	void pick(const Vector<mystring>&)const;
	void drop(const Vector<mystring>&)const;
	void equip(const Vector<mystring>& options);
	void put(const Vector<mystring>& options)const;
	void unequip(const Vector<mystring>& options);
	void get(const Vector<mystring>& options)const;
	void buy(const Vector<mystring>& options);
	void attack(const Vector<mystring>& options);
	void use(const Vector<mystring>& options);
	void sell(const Vector<mystring>& options);
	int count = 0;
	int money = 0;
	int other = 0;
	int maxequiped = 0;
	bool pdead = false;
	unsigned int SpecialAttackTimer = GetTickCount();
	unsigned int Actualtime = GetTickCount();
	void Update(){
		if (health <= 0){
			printf("You are dead, next try!");
			pdead = true;
		}
	}
	
};
#endif