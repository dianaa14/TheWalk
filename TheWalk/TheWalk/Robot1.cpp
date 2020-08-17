#include "Robot1.h"
#include <vector>
#include <map>
#include <cmath>

/*  Robotul 1 poate vedea in jururl sau  la o singura pozitie distanta, prin
	urmare el are vizibilitate 1 si se poate deplasa in orice directie pe harta

	Incearca sa evite capcanele daca poate
	Daca nu are de ales si este inconjurat de capcane,
	poate trece peste ea daca a cules pe drum un item compatibil care il ajuta sa faca asta
	Alege pozitia libera de pe harta care este cat mai aproape de destinatie
	Daca nu are nici item ajutator, va pierde o viata pentru a isi continua drumul
*/

Robot1::Robot1(const int id) : Robot(id), nrItem(0) {}

pair<int, int> Robot1::alegPozNoua(const Harta& h) const {
	/*
		p -> pozitia urmatoare pentru care distanta este minima (daca nu contine capcana)
		pc -> pozitia urmaotoare pentru care distanta este minima (daca contine capcana)
		loc -> coordonatele punctului de finish
		dmin -> distanta minima pana la destinatie (pentru pozitiile care nu contin capcane)
		dminc -> distanta minima pana la destinatie (pentru pozitiile care contin capcane)
	*/
	pair <int, int> p = make_pair(-1, -1);
	pair <int, int> pc = make_pair(-1, -1);
	pair <int, int> loc = h.getLocatie();
	double d, dmin, dminc;
	dmin = -1;
	dminc = -1;

	//Pozitia curenta
	int i = this->getPozitie().first;
	int j = this->getPozitie().second;

	//Verific vecinatatea
	for (int l = i - 1; l <= i + 1; l++)
		for (int c = j - 1; c <= j + 1; c++) {
			if (l >= 0 && l < h.getLinii() && c >= 0 && c < h.getColoane() && (l != i || c != j)) {
				if (h.getMatrice(l, c) != 'X' && h.getMatrice(l, c) != '/') {
					d = sqrt((loc.first - l) * (loc.first - l) + (loc.second - c) * (loc.second - c));
					if (dmin == -1) {
						dmin = d;
						p = make_pair(l, c);
					}
					else
						if (d < dmin) {
							dmin = d;
							p = make_pair(l, c);
						}
				}
				else {
					if (h.getMatrice(l, c) == 'X') {
						d = sqrt((loc.first - l) * (loc.first - l) + (loc.second - c) * (loc.second - c));
						if (dminc == -1) {
							dminc = d;
							pc = make_pair(l, c);
						}
						else
							if (d < dminc) {
								dminc = d;
								pc = make_pair(l, c);
							}
					}
				}
			}
		}
	//Daca am gasit o pozitie libera, atunci o aleg
	//Daca nu, aleg pozitia-capcana cea mai apropiata de destinatie
	//Altfel, robotul s-a blocat
	if (p != make_pair(-1, -1))
		return p;
	else
		return pc;
}



void Robot1::mutareRobot(Harta& h, const int linie, const int coloana) {
	/*
		Daca pe noua pozitie se afla o capcana,
		inseamna ca pote trece pe ea daca are item sau pierde o viata pentru a continua
		Intai va folosi item- ul daca il are, daca nu, va pierde una dintre cele 3 vieti
	*/

	if (h.getMatrice(linie, coloana) == 'X') {
		if (this->nrItem != 0) {
			cout << "\nRobotul tau a folosit un item pentru a trece de capcana";
			this->nrItem--;
			if (this->nrItem != 0)
				
				cout << "\nRobotul mai are disponibili " << this->nrItem << " itemi.";
		}
		else {
			this->scadeViata();
			if (this->getNrVieti() == 0)
				cout << "\n Robotul tau a murit incercand sa ajunga la finish.";
			else {
				cout << "\nRobotul tau a pierdut o viata.";
				cout << "\n Acum mai are " << this->getNrVieti() << " vieti ramase.";
			}
		}
	}

	//Daca pe noua pozitie se afla un item
	if (h.getMatrice(linie, coloana) == '1' || h.getMatrice(linie, coloana) == '2' || h.getMatrice(linie, coloana) == '3') {
		this->item(h.getMatrice(linie, coloana));
	}

	//Trebuie sa marchez noua pozitie cu 'R'
	h.setMatrice(linie, coloana, 'R');
	pair<int, int> p = this->getPozitie();
	h.setMatrice(p.first, p.second, '/');

	//Setez noua pozitie a robotului
	this->setPozitie(make_pair(linie, coloana));
}



void Robot1::item(char i) {
	/*
		Daca intalneste un item corespunzator tipului sau,
		robotul il va pastra pentru a trece peste o capcana
		Daca intalneste un item care nu ii corespunde,
		robotul il va ignora pentru ca nu ii corespunde.
	*/
	if (i == '1') {
		cout << "\nAi gasit un item pentru robotul tau! Il vei putea folosi cand vei intampina capcane!";
		this->nrItem++;
		cout << "\nRobotul tau are acum " << nrItem << "itemi disponibili";
	}
	if (i == '2') {
		cout << "\nAi gasit un item pentru Robotul 2";
		cout << "\nNu il poti folosi in drumul tau";
	}
	if (i == '3') {
		cout << "\nAi gasit un item pentru Robotul 2";
		cout << "\nNu il poti folosi in drumul tau";
	}
	
}


void Robot1::descriereRobot() {
	cout << "\nAi ales Robotul1. El are vizibilitatea 1 ceea ce inseamna ca poate vedea in jurul sau";
	cout << "\ninsa doar la o mutare distanta. El incearca sa evite toate capcanele. ";
	cout << "\nDaca va ajunge sa fie inconjurat de ele, va putea sa foloseasca un item ajutator,";
	cout << "\nBineinteles, daca va avea norocul sa dea de el in drumul sau";
	cout << "\nDaca nu reuseste sa treaca de capcana cu ajutorul unui item,";
	cout << "\nva pierde o viata pentru a ajunge la destinatie!";



		
	
}