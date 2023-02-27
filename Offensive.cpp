using namespace std;
#include "Offensive.h"
#include "Player.h"

Offensive::Offensive() {
	int n = 0;
	cout << "Ktora bron chcesz kupic?\n";
	cout << "1. Harpun                [12-30]dmg                                     Cena:100\n";
	cout << "2. Miecz œwietlny        [17-23]dmg    [4]przebicia pancerza            Cena:200\n";
	cout << "3. Magiczna Ró¿d¿czka	  [40-60]dmg    [30%]kradzie¿y ¿ycia             Cena:300\n";
	cout << "4. Wróæ\n";
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
		name = "Harpun";
		damage[0] = 12;
		damage[1] = 30;
		armorPenetration = 0;
		price = 100;
		break;

	case 2:
		name = "Miecz œwietlny";
		damage[0] = 17;
		damage[1] = 23;
		armorPenetration = 4;
		price = 200;
		break;

	case 3:
		name = "Magiczna Ró¿d¿czka";
		damage[0] = 40;
		damage[1] = 60;
		lifeSteal = 30;
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

void Offensive::useItem() {
	int dmg = 0;
	int lifeStolen = 0;
	srand((unsigned int)time(NULL));
	dmg = rand() % (damage[1] - damage[0] + 1) + damage[0];
	dmg -= ptrEnemyPlayer->getArmor() - armorPenetration;
	dmg += dmg * ptrPlayer->getAttackBoost() / 100;
	if (dmg > 0) {
		lifeStolen = (dmg * lifeSteal) / 100;
		lifeStolen -= lifeStolen * ptrEnemyPlayer->getLifeStealReduction() / 100;
		ptrEnemyPlayer->takeDmg(dmg);
		ptrPlayer->changeHp(lifeStolen);
		cout << ptrEnemyPlayer->getName() << " otrzyma³ " << dmg << " obra¿eñ\n";
		cout << "Press ENTER to continue...\n";
		cin.ignore();
		cin.get();
	}
	else {
		dmg = 0;
		cout << "Pancerz przeciwnika okaza³ siê silniejszy\nNie zadajesz ¿adnych obra¿eñ\n";
		cout << "Press ENTER to continue...\n";
		cin.ignore();
		cin.get();
	}
}

void Offensive::showItem() {
	cout << name << "	Cena sprzeda¿y:	" << sellPrice << endl;
}