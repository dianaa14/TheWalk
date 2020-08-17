#include "Robot3.h"
#include <vector>
#include <map>
#include <cmath>

/*
Robotul 2 se misca pe orizontala.
	Un singur item intalnit pe drum, ii cofera de fapt 5, le poate folosi pentru a indeparta capcanele
	Daca nu are niciunul, va pierde o viata pentru a merge mai departe
	Poate colecta si item-uri incompatibile, insa le poate foloi doar daca strange 4
	In momentul in care a strans 4 item-uri incompatibile, isi va adauga o viata, in cazul in care nu
	are deja maximul de 3, caz in care i se vor adauga cand va pierde o viata
*/

Robot3::Robot3(const int id) : Robot(id), item2(0), itemiIncompatibili2(0) {}

pair<int, int> Robot3::alegPozNoua(const Harta& h) const {
	pair <int, int> p = make_pair(-1, -1);

	//Pozitia curenta
	int i = this->getPozitie().first;
	int j = this->getPozitie().second;

	//Destinatia
	pair <int, int> loc = h.getLocatie();

	//Miscarea pe orizontala
	
	if (i % 2 == 0) {
		if (j + 1 < h.getColoane())
			p = make_pair(i, j + 1);
		else {
			if (j + 1 == h.getColoane() && i + 1 < h.getLinii())
			{
				p = make_pair(i + 1, j);

			}
			
		}
	}
	else {
		if (j -1 >= 0)
			p = make_pair(i, j - 1);
		else
			if (j - 1 < h.getColoane())
				p = make_pair(i + 1, j);

	}
		return p;

	
}


void Robot3::mutareRobot(Harta& h, const int linie, const int coloana) {
	

	if (h.getMatrice(linie, coloana) == 'X') {
		if (this->item2 != 0) {
			cout << "\nRobotul tau a folosit un item pentru a trece de capcana";
			this->item2--;
			if (this->item2 != 0)
				cout << "\nRobotul mai are disponibili  " << this->item2 << " itemi";
		}
		else {
			this->scadeViata();
			if (this->getNrVieti() == 0)
				cout << "\n Robotul tau a murit incercand sa ajunga la finish.";
			else {
				
			}
		}
	}

	//Daca pe noua pozitie se afla un item
	if (h.getMatrice(linie, coloana) == '2' || h.getMatrice(linie, coloana) == '3' || h.getMatrice(linie, coloana) == '1') {
		this->item(h.getMatrice(linie, coloana));
	}

	//Trebuie sa marchez noua pozitie cu 'R'
	h.setMatrice(linie, coloana, 'R');
	pair<int, int> p = this->getPozitie();
	h.setMatrice(p.first, p.second, '/');

	//Setez noua pozitie a robotului
	this->setPozitie(make_pair(linie, coloana));
}


void Robot3::item(char i) {
	if (i == '1') {
		cout << "\nAi gasit un item pentru Robotul1";
		cout << "\nIl va pastra pentru mai tarziu";
		this->itemiIncompatibili2++;
		cout << "\nAcum are" << this->itemiIncompatibili2 << " itemi incompatibili.";
	}

	if (i == '2') {
		cout << "\nAi gasit un item pentru Robotul1.";
		cout << "\nIl va pastra pentru mai tarziu ";
		this->itemiIncompatibili2++;
		cout << "\nAcum are" << this->itemiIncompatibili2 << " itemi incompatibili.";
	}
	
	if (i == '3') {
		cout << "\nAi gasit un item pentru robotul tau, el se va inmulti cu 5";
		this->item2+=5;
		cout << "\nRobotul tau are " << this->item2 << " itemi.";
	}

	
	//Cand strange 4 itemi incompatibili, adauga o viata
	if (this->getNrVieti() < 3) {
		if (this->itemiIncompatibili2 == 4) {
			this->adaugaViata();
			this->itemiIncompatibili2-=4;
			cout << "\nRobotul tau si-a incarcat o viata din itemii castigati.";
			cout << "\nRobotul are acum " << this->getNrVieti() << " vieti.";
		}
	}
	
}


void Robot3::descriereRobot() {

		cout << "\nAi ales Robotul3. El se misca pe orizontala. Atunci cand va intalnii un item compatibil, el se va inmultii cu 5. ";
		cout << "\nDaca totusi el intalneste un item care nu ii corespunde, il va pastra.";
		cout << "\nAtunci cand va ramane fara vieti, va putea sa transforme aceii itemi incompatibili in vieti ";
		cout << "\npentru a isi reface maximul.";
		cout << "\nDaca nu reuseste sa treaca de capcana cu ajutorul unui item,";
		cout << "\nva pierde o viata pentru a ajunge la destinatie!";
	
}