#pragma once
using namespace std;
#include "Item.h"

class Player;
class Defensive :public Item {
private:
	int bonusHp = 0;
	int bonusArmor = 0;
public:
	Defensive();
	void useItem();
	void showItem();
	void sell();
};