#include "Robot2.h"

/*
	Robotul 2 se misca pe verticala.
	Un singur item intalnit pe drum, ii cofera de fapt 3, le poate folosi pentru a indeparta capcanele
	Daca nu are niciunul, va pierde o viata pentru a merge mai departe
	Poate colecta si item-uri incompatibile, insa le poate foloi doar daca strange 2
	In momentul in care a strans 2 item-uri incompatibile, isi va adauga o viata, in cazul in care nu 
	are deja maximul de 3, caz in care i se vor adauga cand va pierde o viata
*/

Robot2::Robot2(const int id) : Robot(id), item1(0), itemIncompatibil2(0) {}


pair<int, int> Robot2::alegPozNoua(const Harta& h) const {
	pair <int, int> p = make_pair(-1, -1);

	//Pozitia curenta
	int i = this->getPozitie().first;
	int j = this->getPozitie().second;

	//Destinatia
	pair <int, int> loc = h.getLocatie();

		//Miscarea pe verticala
		if (j % 2 == 0) {
			if (i + 1 < h.getLinii())
				p = make_pair(i + 1, j);
			else {
				if (i + 1 == h.getLinii() && j + 1 < h.getColoane())
					p = make_pair(i, j + 1);
			}
		}
		else {
			if (i - 1 >= 0)
				p = make_pair(i - 1, j);
			else
				if (j + 1 < h.getColoane())
					p = make_pair(i, j + 1);
		}
		return p;
	}

	



void Robot2::mutareRobot(Harta& h, const int linie, const int coloana) {
	//Va primi o viata la 2 itemi incompatibili castiati si itemul compatibil ii va fi triplat 
	if (h.getMatrice(linie, coloana) == 'X') {
		if (this->item1 != 0) {
			cout << "\nRobotul tau a folosit un item pentru a trece de capcana";
			this->item1--;
			if (this->item1 != 0)
					cout << "\nRobotul mai are disponibili" << this->item1 << " itemi.";
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

void Robot2::item(char i) {
	/*
		Daca intalneste un item corespunzator tipului sau,
		robotul castiga o armura = imunitate pentru 3 capcane.
		Daca intalneste un item care nu ii corespunde,
		robotul castiga o arma.
		3 arme = 1 viata in plus
	*/
	if (i == '1') {
		cout << "\nAi gasit un item pentru Robotul1";
		cout << "\nIl va pastra pentru mai tarziu";
		this->itemIncompatibil2++;
		cout << "\nAcum are" << this->itemIncompatibil2 << " itemi incompatibili.";
	}


	if (i == '2') {
		cout << "\nAi gasit un item pentru robotul tau! El va fi triplat! Le vei putea folosi cand vei intampina capcane!";
		this->item1 += 3;
		cout << "\nRobotul tau are acum " << this->item1 << "itemi disponibili";
		
		
	}
	if (i == '3') {
		cout << "\nAi gasit un item pentru Robotul3";
		cout << "\nIl va pastra pentru mai tarziu";
		this->itemIncompatibil2++;
		cout << "\nAcum are" << this->itemIncompatibil2 << " itemi incompatibili.";
	}

	
	//Cand strange 2 itemi incompatibili, adauga o viata
	if (this->getNrVieti() < 3) {
		if (this->itemIncompatibil2 == 2) {
			this->adaugaViata();
			this->itemIncompatibil2-=2;
			cout << "\nRobotul tau si-a incarcat o viata din itemii castigati.";
			cout << "\nRobotul are acum " << this->getNrVieti() << " vieti.";
		}
	}
}

void Robot2::descriereRobot() {
	cout << "\nAi ales Robotul2. El se misca pe veritcala. Atunci cand va intalnii un item compatibil, el i se va tripla. ";
	cout << "\nDaca totusi el intalneste un item care nu ii corespunde, il va pastra.";
	cout << "\nAtunci cand va ramane fara vieti, va putea sa transforme aceii itemi incompatibili in vieti ";
	cout << "\npentru a isi reface maximul.";
	cout << "\nDaca nu reuseste sa treaca de capcana cu ajutorul unui item,";
	cout << "\nva pierde o viata pentru a ajunge la destinatie!";
}