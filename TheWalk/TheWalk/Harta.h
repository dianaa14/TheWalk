#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Robot.h"
using namespace std;

class Harta
{
	int nrLinii;
	int nrColoane;
	char** matrice;
	pair<int, int> locatie;		//Destinatia robotului

public:
	Harta(const int linii, const int coloane);
	~Harta();

	pair<int, int> getLocatie() const;						//Returnez pozitia destinatiei
	char getMatrice(int, int) const;							//Returnez ce se afla pe harta la coordonatele date
	int getLinii() const;									//Returnez numarul de randuri 
	int getColoane() const;									//Returnez numarul de coloane

	void setMatrice(const int, const int, const char);		//Modific o valoare din matrice

	friend ostream& operator << (ostream&, const Harta&);	//Supraincarcarea operatorului << pentru afisarea harta
};