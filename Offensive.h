#pragma once
using namespace std;
#include "Item.h"
class Player;
class Offensive :public Item {
private:
	int damage[2] = { 0, 0 };
	int lifeSteal=0; //Wyra¿a % zadanych obra¿eñ, które zostan¹ dodane do naszego zdrowia
	int armorPenetration=0;

public:
	Offensive();
	void useItem();
	void showItem();
};