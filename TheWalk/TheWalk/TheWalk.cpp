#include <iostream>
#include "Run.h"
#include "Harta.h"
#include "Robot.h"
#include "Robot1.h"
#include "Robot2.h"
#include "Robot3.h"
#include "Harta.cpp"
#include "Robot.cpp"
#include "Robot1.cpp"
#include "Robot2.cpp"
#include "Robot3.cpp"
#include "Run.cpp"
using namespace std;



int main() {
cout << "Jocul TheWalk";
cout << "\nPe harta exista un robot, al carui tip il vei putea alege ulterior";
cout << "\nPe harta exista si o locatie unde robotul tau trebuie sa ajunga.\n";
cout << "\nDe asemenea, pe harta sunt distribuite diferite capcane care il pot incurca pe robotul sau item-uri care sa il ajute in calatoria lui.\n\n";
	
	Game G;
	
	G.print();
	cout << endl;

	cout << "Cum doriti sa se desfasoare jocul?" << endl;
	cout << "\nOptiunea 1 : Oprirea jocului la fiecare runda" << endl;
	cout << "\nOptiunea 2 : Simulare succesiva a rundelor " << endl;
	cout << "\n  Optiunea dumneavoastra: ";
	int op;
	cin >> op;
	while (op != 1 && op != 2) {
		cout << "\n Optiunea nu este valida. Introduceti una din cele de mai sus:";
		cin >> op;
	}
	cout << endl;
	cout << endl;

	if (op == 1) {
		int f = 0;
		int cont = 1;
		do {
			G.runGame();
			G.print();
			f = G.getFinish();
			if (f == 0) {
				cout << "\nDoriti sa continuati jocul?\nIntroduceti 1 pentru DA sau 0 pentru NU:";
				cin >> cont;
				while (cont != 1 && cont != 0) {
					cout << "\n Optiunea nu este valida. Introduceti una din cele de mai sus:";
					cin >> cont;
				}
				cout << endl;
			}
		} while (cont == 1 && f == 0);
		if (cont == 0)
			cout << endl << "Robotul nu a ajuns la destinatie!" << endl;
	}
	else {
		while (G.getFinish() == 0) {
			G.runGame();
		}
		G.print();
	}

	return 0;
}