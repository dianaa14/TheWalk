#pragma once
#include "Robot.h"

class Robot3 : public Robot {
	int item2;
	int itemiIncompatibili2;

public:
	Robot3(const int id);

	pair<int, int> alegPozNoua(const Harta& h) const;
	void mutareRobot(Harta&, const int, const int);
	void item(char);
	void descriereRobot();
	~Robot3() {};
};