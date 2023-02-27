#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
//#include "Offensive.h"
using namespace std;
class Player;
class Item {
protected:
	string name;
	int price = 0;
	int sellPrice = 0;
	Player* ptrPlayer = nullptr;
	Player* ptrEnemyPlayer = nullptr;
public:
	void setWskPlayer(Player* _ptrPlayer) { ptrPlayer = _ptrPlayer; }
	void setWskEnemyPlayer(Player* _ptrEnemyPlayer) { ptrEnemyPlayer = _ptrEnemyPlayer; }
	virtual void useItem() = 0;
	int getPrice() const { return price; }
	int getSellPrice() const { return sellPrice; }
	string getName() const { return name; }
	virtual void showItem() = 0;
};