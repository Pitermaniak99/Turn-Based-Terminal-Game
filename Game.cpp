using namespace std;
#include "Game.h"

Game::Game() {
	cout << "Witaj w krainie czarów i magii.\n";
	cout << "Na pocz¹tek dodaj dwóch graczy\n";
	playerList[0] = addPlayer();
	cout << "Witaj " << playerList[0]->getName() << endl;
	playerList[1] = addPlayer();
	cout << "Witaj " << playerList[1]->getName() << endl << endl;
}

Game::~Game() {
	//cout << "Destruktor\n";
	delete playerList[1];
	delete playerList[0];
}


Player* Game::addPlayer() {
	Player* tmp = new Player;
	tmp->setName();
	tmp->setWskGame(this);
	return tmp;
}

void Game::play() {
	int wygrany = -1;
	while (playerList[0]->getHp() > 0 && playerList[1]->getHp() > 0) {
		playerList[0]->move(playerList[1]);
		if (playerList[0]->getHp() > 0)
			wygrany = 0;
		if (playerList[0]->getHp() > 0 && playerList[1]->getHp() > 0) {
			playerList[1]->move(playerList[0]);
			if (playerList[1]->getHp() > 0)
				wygrany = 1;
		}
	}
	system("cls");
	if (wygrany == -1)
		wygrany = 1;
	cout << "GAMEOVER!!!\n\n" << "Wygra³ " << playerList[wygrany]->getName() << "\n\nGRATULACJE!!!\n";
}

Player* Game::getEnemy(Player* _player) {
	if (_player == playerList[0])
		return playerList[1];
	else
		return playerList[0];
}