#pragma once
#include "Player.h"
using namespace std;
#define PLAYER_NUMBER 2

class Game{
private:
	Player* playerList[PLAYER_NUMBER];

public:
	Game();
	~Game();
	Player* addPlayer();
	Player* getEnemy(Player* _player);
	void play();
};