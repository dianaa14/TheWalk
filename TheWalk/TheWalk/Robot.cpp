#include "Robot.h"

Robot::Robot(int id) : tip(id), pozitie({ 0,0 }), nrVieti(3) {}

pair<int, int> Robot::getPozitie() const {
	return this->pozitie;
}

void Robot::setPozitie(const pair<int, int> p) {
	this->pozitie = p;
}

int Robot::getNrVieti() const {
	return this->nrVieti;
}

int Robot::getTip() const {
	return this->tip;
}


void Robot::scadeViata() {
	this->nrVieti--;
}

void Robot::adaugaViata() {
	this->nrVieti++;
}