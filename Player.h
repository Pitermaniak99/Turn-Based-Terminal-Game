#pragma once
using namespace std;
#include "Item.h"
#define DEAFUALT_HP 100
#define DEAFUALT_ARMOR 10
#define DEAFUALT_MONEY 500

class Game;
class Player {
private:
	string name;
	int hp = DEAFUALT_HP;
	int armor = DEAFUALT_ARMOR;
	int attackBoost = 0;
	int lifeStealReduction = 0;
	int money = DEAFUALT_MONEY;
	vector<Item*>itemList;
	Game* ptrGame=nullptr;

public:
	string getName() const { return name; }
	int getHp()		const { return hp; }
	int getArmor()	const { return armor; }
	int getAttackBoost() const { return attackBoost; }
	int getLifeStealReduction() const { return lifeStealReduction; }
	int getMoney()	const { return money; }
	int getItemsNumber()	const { return itemList.size(); }
	void changeHp(int _hp) { hp += _hp; }
	void changeArmor(int _armor) { armor += _armor; }
	void changeAttackBoost(int _attackBoost) { attackBoost = _attackBoost; }
	void changeLifeStealReduction(int _lifeStealReduction) { lifeStealReduction += _lifeStealReduction; }
	void takeDmg(int _dmg) { hp -= _dmg; }
	void setWskGame(Game* _wskGame) { ptrGame = _wskGame; }
	void setName();
	void move(Player* attackedPlayer);
	void addItem();
	void sellItem();
	void showItemList();
	bool attack();
	~Player();
};