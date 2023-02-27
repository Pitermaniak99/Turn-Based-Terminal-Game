using namespace std;
#include "Player.h"
#include "Offensive.h"
#include "Defensive.h"
#include "Mixture.h"
#include "Game.h"

void Player::setName() {
	cout << "Podaj imie gracza:\n";
	cin >> name;
}

void Player::addItem() {
	int n = 0;
	Item* tmp = nullptr;
	system("cls");
	cout << "Jakie przedmiot chcesz kupi�?\n1. Ofensywny\n2. Defensywny\n3. Mikstur�\n";
	while (tmp == nullptr) {
		while (1) {
			cin >> n;
			if (cin.fail() == true) {
				cout << "Wykryto blad" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}
			else  break;
		}
		switch (n) {
		case 1:
			tmp = new Offensive;
			break;

		case 2:
			tmp = new Defensive;
			break;

		case 3:
			tmp = new Mixture;
			break;
		}
	}
	if (tmp == nullptr)
		cout << "B��d pami�ci\n";
	else {
		if (itemList.size() <= 10) {
			if (tmp->getPrice() == -1) {
				delete tmp;
			}
			else {
				if (money >= tmp->getPrice()) {
					money -= tmp->getPrice();
					tmp->setWskPlayer(this);
					tmp->setWskEnemyPlayer(ptrGame->getEnemy(this));
					itemList.push_back(tmp);
					cout << "Kupiono " << itemList[itemList.size() - 1]->getName() << endl;
					if (typeid(*tmp) == typeid(Offensive)) {}
					else
						tmp->useItem();
				}
				else {
					cout << "Masz za ma�o pieni�dzy\n";
					delete tmp;
				}
			}
		}
		else
			cout << "Posiadasz ju� maksymaln� ilo�� przedmiot�w\n";
	}
	cout << "Press ENTER to continue...\n";
	cin.ignore();
	cin.get();
}

void Player::sellItem() {
	system("cls");
	int n = 0;
	if (itemList.size() > 0) {
		cout << "Kt�ry przedmiot chcesz sprzeda�?\n";
		showItemList();
		cout << itemList.size() + 1 << ". Wr��\n";
		while (n<1 || n>itemList.size() + 1) {
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
		if (n == itemList.size() + 1) {}
		else {
			cout << "Sprzeda�e� " << itemList[n - 1]->getName() << " za " << itemList[n - 1]->getSellPrice() << endl;
			money += itemList[n - 1]->getSellPrice();
			if (typeid(*itemList[n - 1]) == typeid(Defensive))
				dynamic_cast<Defensive*>(itemList[n - 1])->sell(); //Mog� bezpiecznie zrzutowa�, gdy� mam pewno�� ze ten item zawsze bedzie defensywny
			delete itemList[n - 1];
			itemList.erase(itemList.begin() + n - 1);
		}
	}
	else
		cout << "Nie masz jeszcze �adnych przedmiot�w.\n";
	cout << "Press ENTER to continue...\n";
	cin.ignore();
	cin.get();
}

void Player::showItemList() {
	if (itemList.size() > 0) {
		for (unsigned int i = 0; i < itemList.size(); i++) {
			cout << i + 1 << ". ";
			itemList[i]->showItem();
		}
	}
	else
		cout << "Nie masz jeszcze �adnych przedmiot�w.\n";
}

bool Player::attack() {
	vector<Item*>tmpItemList;
	int n = 0;
	for (unsigned int i = 0; i < itemList.size(); i++) {
		if (typeid(*itemList[i]) == typeid(Offensive)) {
			tmpItemList.push_back(itemList[i]);
		}
	}
	if (tmpItemList.size() > 0) {
		cout << "Kt�rym przedmiotem chcesz zaatakowa�?\n";
		for (unsigned int i = 0; i < tmpItemList.size(); i++) {
			cout << i + 1 << ". ";
			tmpItemList[i]->showItem();
		}
		while (1) {
			cin >> n;
			if (cin.fail() == true) {
				cout << "Wykryto blad" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}
			else  break;
		}
		tmpItemList[n - 1]->useItem();
		return true;
	}
	else {
		cout << "Nie masz �adnego przedmiotu ofensywnego.\n";
		cout << "Press ENTER to continue...\n";
		cin.ignore();
		cin.get();
		return false;
	}
}

void Player::move(Player* attackedPlayer) {
	int n = 0;
	bool play = true, attack1 = false;
	if (itemList.size() > 0) {
		for (int i = 0; i <itemList.size(); i++) {
			if (typeid(*itemList[i]) == typeid(Mixture)) {
				dynamic_cast<Mixture*>(itemList[i])->sell(); //Mog� bezpiecznie zrzutowa�, gdy� mam pewno�� ze ten item zawsze bedzie mikstur�
				delete itemList[i];
				itemList.erase(itemList.begin() + i);
				i--;
			}
		}
	}
	while (play) {
		system("cls");
		cout << "Tura gracza " << name << endl;
		cout << "Pieni�dze: " << money << "		Hp: " << hp << "		Pancerz: " << armor << endl;
		cout << "1. Statystyki\n2. Kup item\n3. Sprzedaj przedmiot\n4. Atakuj\n5. Zako�cz tur�\n10. Poddaj si�\n";
		while (1) {
			cin >> n;
			if (cin.fail() == true) {
				cout << "Wykryto blad" << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}
			else  break;
		}
		switch (n) {
		case 1:
			system("cls");
			showItemList();
			cout << "Press ENTER to continue...\n";
			cin.ignore();
			cin.get();
			break;

		case 2:
			addItem();
			break;

		case 3:
			sellItem();
			break;

		case 4:
			system("cls");
			if (attack1 == false) {
				attack1 = attack();
				if (ptrGame->getEnemy(this)->getHp() <= 0)
					play = false;
			}
			else {
				cout << "Mo�esz zaatakowa� tylko raz w swojej turze\n";
				cout << "Press ENTER to continue...\n";
				cin.ignore();
				cin.get();
			}
			break;

		case 5:
			if (attack1 == true) {
				money += 100;
				play = false;
			}
			else {
				system("cls");
				cout << "Je�li nie zaatakujesz nie otrzymasz pieni�dzy\nCzy na pewno chcesz zako�czy� swoj� ture?\n1. Tak\n2. Nie\n";
				while (1) {
					cin >> n;
					if (cin.fail() == true) {
						cout << "Wykryto blad" << endl;
						cin.clear();
						cin.ignore(256, '\n');
					}
					else  break;
				}
				switch (n) {
				case 1:
					play = false;
					break;
				default:
					break;
				}
			}
			break;
		case 10:
			hp = 0;
			play = false;
			break;

		default:
			break;
		}
	}
}

Player::~Player() {
	for (int unsigned i = 0; i < itemList.size(); i++)
		delete itemList[i];
}