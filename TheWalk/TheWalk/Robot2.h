#pragma once
#include "Robot.h"

class Robot2 :public Robot {
	int item1;
	int itemIncompatibil2;

public:
	Robot2(const int id);

	pair<int, int> alegPozNoua(const Harta& h) const;
	void mutareRobot(Harta&, const int, const int);
	void item(char);
	void descriereRobot();
	~Robot2() {};
};