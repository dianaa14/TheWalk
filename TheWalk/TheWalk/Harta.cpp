#include "Harta.h"

// Constructor harta 
Harta::Harta(const int rows, const int columns) :nrLinii(rows), nrColoane(columns) {
	matrice = new char* [nrLinii];
	for (int i = 0; i < nrLinii; i++)
		matrice[i] = new char[nrColoane];
	for (int i = 0; i < nrLinii; i++)
		for (int j = 0; j < nrColoane; j++)
			matrice[i][j] = '_';

	//Robotul se afla initial in coltul din stanga sus (marcat pe harta cu R)
	matrice[0][0] = 'R';

	srand((unsigned int)time(NULL));

	//Generare pozitie destinatie (marcat cu F pe harta)
	int ok = 0;
	do {
		int poz_final_x = rand() % nrLinii;
		int poz_final_y = rand() % nrColoane;
		if (matrice[poz_final_x][poz_final_y] == '_') {
			matrice[poz_final_x][poz_final_y] = 'F';
			this->locatie = make_pair(poz_final_x, poz_final_y);
			ok = 1;
		}
	} while (ok == 0);


	//Generare pozitii pentru capcane (0 pe harta) si itemii (1,2,3)
	//nrItems = min(nrRows,nrColumns)
	//nrTraps = random(2*min(nrRows,nrColumns), 2*max(nrRows,nrColumns))
	int nrItems, nrTraps;
	if (nrLinii <= nrColoane) {
		nrItems = nrLinii;
		nrTraps = nrColoane * 2;
	}
	else {
		nrItems = nrColoane;
		nrTraps = rand() % nrLinii + (2 * nrLinii + 1);
	}

	while (nrTraps) {
		int poz_x = rand() % nrLinii;
		int poz_y = rand() % nrColoane;
		if (matrice[poz_x][poz_y] == '_') {
			nrTraps--;
			matrice[poz_x][poz_y] = '0';
		}
	}
	while (nrItems) {
		//Items de 3 tipuri (fiecare este compatibil cu un tip de robot) - 1, 2, 3
		int type = rand() % 3 + 1;
		int poz_x = rand() % nrLinii;
		int poz_y = rand() % nrColoane;
		if (matrice[poz_x][poz_y] == '_') {
			nrItems--;
			switch (type) {
			case 1: matrice[poz_x][poz_y] = '1'; break;
			case 2: matrice[poz_x][poz_y] = '2'; break;
			case 3: matrice[poz_x][poz_y] = '3'; break;
			}
		}
	}
}


//Destructor
Harta::~Harta() {
	for (int i = 0; i < nrLinii; i++)
		delete[] matrice[i];
	delete[] matrice;
	nrLinii = 0;
	nrColoane = 0;
}

int Harta::getLinii() const {
	return this->nrLinii;
}

int Harta::getColoane() const {
	return this->nrColoane;
}

pair <int, int> Harta::getLocatie() const {
	return this->locatie;
}

char Harta::getMatrice(int i, int j) const {
	return this->matrice[i][j];
}

void Harta::setMatrice(const int i, const int j, const char c) {
	this->matrice[i][j] = c;
}


//Afisare harta
ostream& operator << (ostream& out, const Harta& h) {
	for (int i = 0; i < h.nrLinii; i++) {
		for (int j = 0; j < h.nrColoane; j++)
			out << h.matrice[i][j] << " ";
		out << endl;
	}
	return out;
}