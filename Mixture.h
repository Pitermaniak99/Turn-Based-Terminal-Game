#pragma once
using namespace std;
#include "Item.h"

class Player;
class Mixture :public Item {
private:
	int bonusArmor = 0;
	int bonusDamage = 0;
	int bonusLifeStealReduction = 0;
public:
	Mixture();
	void useItem();
	void showItem();
	void sell();
};