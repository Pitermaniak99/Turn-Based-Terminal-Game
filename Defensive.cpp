using namespace std;
#include "Defensive.h"
#include "Player.h"

Defensive::Defensive() {
	int n = 0;
	cout << "Ktora bron chcesz kupic?\n";
	cout << "1. He³m		[+10]Hp						Cena:100\n";
	cout << "2. Tarcza		[+4]Armor					Cena:200\n";
	cout << "3. Kolczuga	[+10Hp]		  [+5]Armor     Cena:300\n";
	cout << "4. Wroc\n";
	while (n <1||n>4) {
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
		name = "He³m";
		bonusHp = 10;
		price = 100;
		break;

	case 2:
		name = "Tarcza";
		bonusArmor = 4;
		price = 200;
		break;

	case 3:
		name = "Kolczuga";
		bonusHp = 10;
		bonusArmor = 5;
		price = 300;
		break;

	case 4:
		price = -1;
		break;
	default:
		break;
	}
	sellPrice = price / 2;
}

void Defensive::useItem() {
	ptrPlayer->changeHp(bonusHp);
	ptrPlayer->changeArmor(bonusArmor);
}

void Defensive::sell() {
	ptrPlayer->changeHp(-bonusHp);
	ptrPlayer->changeArmor(-bonusArmor);
}


void Defensive::showItem() {
	cout << name << "	Cena sprzeda¿y:	" << sellPrice << endl;
}