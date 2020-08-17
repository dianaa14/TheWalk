#pragma once
#include "Robot.h"

class Robot1 : public Robot {
	int nrItem;
public:
	Robot1(const int id);

	pair<int, int> alegPozNoua(const Harta& h) const;
	void mutareRobot(Harta&, const int, const int);
	void item(char);
	void descriereRobot();
	~Robot1() {};
};