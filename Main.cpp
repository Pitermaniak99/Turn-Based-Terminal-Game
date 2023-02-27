#include "Game.h"
using namespace std;

int main(){
		
	setlocale(LC_ALL, "pl_PL");
	bool menu = true;
	int choice = 0;
	Game game1;

	while (menu) {
		cout << "1. Zasady gry\n2. Rozpocznij gre\n3. Wyjdz z gry\n";
		while (1) {
			cin >> choice;
			if (cin.fail() == true) {								//wykrycie b³êdu
				cout << "Wykryto blad" << endl;						//komunikat o b³êdzie
				cin.clear();										//resetowanie flag b³êdu
				cin.ignore(256, '\n');								//czyszczenie 256 znaków bufora
			}														//lub do napotkania znaku nowej linii
			else  break;
		}

		switch (choice){
		case 1:
			system("cls");
			cout << "Gra polega na...\n";
			break;

		case 2:
			system("cls");
			game1.play();
			menu = false;
			break;

		case 3:
			menu = false;
			break;

		default:
			break;
		}
	}
	
	return 0;
}