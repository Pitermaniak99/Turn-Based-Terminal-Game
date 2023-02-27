using namespace std;
#include "Mixture.h"
#include "Player.h"

Mixture::Mixture() {
	int n = 0;
	cout << "Ktora bron chcesz kupic?\n";
	cout << "1. Zwiekszenie pancerza            [+20%]pancerz                   Cena:50\n";
	cout << "2. Wzmocnienie ataku				[+10%]dmg						Cena:50\n";
	cout << "3. Redukcja kradzie퓓 퓓cia		[-20%]kradzie퓓 퓓cia			Cena:50\n";
	cout << "4. Wr槍\n";
	while (n < 1 || n>4) {
		while (1) {
			cin >> n;
			if (cin.fail() == true) {
				cout << "Wykryto blad" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}
			else  break;
		}
	}
	switch (n)
	{
	case 1:
		name = "Zwiekszenie pancerza";
		bonusArmor = 20;
		price = 50;
		break;

	case 2:
		name = "Wzmocnienie ataku";
		bonusDamage = 5;
		price = 50;
		break;

	case 3:
		name = "Redukcja kradzie퓓 퓓cia";
		bonusLifeStealReduction = 20;
		price = 50;
		break;


	case 4:
		price = -1;
		break;

	default:
		break;
	}
	sellPrice = 0;
}

void Mixture::useItem() {
	ptrPlayer->changeArmor((ptrPlayer->getArmor()*bonusArmor)/100);
	ptrPlayer->changeAttackBoost(bonusDamage);
	ptrPlayer->changeLifeStealReduction(bonusLifeStealReduction);
}

void Mixture::sell() {
	ptrPlayer->changeArmor((-(ptrPlayer->getArmor() * bonusArmor) / 100));
	ptrPlayer->changeAttackBoost(-bonusDamage);
	ptrPlayer->changeLifeStealReduction(-bonusLifeStealReduction);
}

void Mixture::showItem() {
	cout << name << "	Cena sprzeda퓓:	" << sellPrice << endl;
}