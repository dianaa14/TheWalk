#pragma once
#include "Harta.h"
#include "Robot.h"
#include "Robot1.h"
#include "Robot2.h"
#include "Robot3.h"
#include <iostream>
using namespace std;

class Game
{
	Harta* H;				//Harta pe care se joaca 
	Robot* r;				//Robotul ales de utilizator pentru acest joc
	int runda;				//Numarul rundei 
	int finish;				//Marchez finish cu 1 daca jocul s-a terminat

public:
	Game();
	~Game();

	void print();				//Afisez harta pentru runda curenta
	void runGame();				//Simulare runda
	int getFinish() const;			//Returnez finish
};