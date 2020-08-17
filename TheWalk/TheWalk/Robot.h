#pragma once
#include <iostream>
#include "Harta.h"
using namespace std;

class Harta;

class Robot
{
	int nrVieti;				//Numar vieti
	int tip;						//Tipul robotului
	pair <int, int> pozitie;		//Pozitia curenta a robotului

public:
	Robot(int);
	virtual ~Robot() {};

	pair<int, int> getPozitie() const;				//Getter pentru pozitia curenta a robotului
	void setPozitie(const pair<int, int>);			//Setez noua pozitie a robotului dupa fiecare runda

	int getNrVieti() const;							//Getter pentru numarul de vieti ale robotului
	int getTip() const;							//Getter pentru tipul robotului

	void scadeViata();							//Scad numarul de vieti
	void adaugaViata();									//Adaug o viata

	virtual pair<int, int> alegPozNoua(const Harta& h) const = 0;			//Aleg noua pozitie a robotului
	virtual void mutareRobot(Harta&, const int, const int) = 0;					//Mut robotul pe noua pozitie
	virtual void item(char) = 0;											//*Modelez cum se comporta robotul fata de un item
	virtual void descriereRobot() = 0;												//Descriere a capabilitatilor robotului
};
