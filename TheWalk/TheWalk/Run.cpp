#include "Run.h";

Game::Game() :runda(0), finish(0) {
	//Construiesc harta
	cout << "Se creeaza jocul. Please wait...\n\n";
	cout << "Introduceti dimensiunile hartii:\n";
	int x, y;
	int flag = 0;
	while (flag == 0) {
		try {
			cout << "Latime:";
			cin >> x;
			if (x < 15)
				throw x;
			else
				flag = 1;
		}
		catch (int) {
			cout << "Valoarea introdusa trebuie sa fie cel putin 15. ";
		}
	}

	flag = 0;
	while (flag == 0) {
		try {
			cout << "Lungime:";
			cin >> y;
			if (y < 15)
				throw y;
			else
				flag = 1;
		}
		catch (int) {
			cout << "Valoarea introdusa trebuie sa fie cel putin 15. ";
		}
	}
	cout << endl;
	H = new Harta(x, y);

	//Se alege robotul
	cout << "Alegeti apasati 1, 2 sau 3 pentru a alege unul dintre cei trei roboti:"<<endl;
	cout << "		 1: Robotul 1- poate vedea in jurul sau o pozitie\n";
	cout << "		 2: Robotul 2- merge pe verticala, insa avantejul i se tripleaza \n";
	cout << "		 3: Robotul 3- merge pe orizontala, insa avantajul sau este inmultit cu 5 \n\n";
	cout << "		 Introduceti optiunea: ";
	int op;
	cin >> op;
	while (op < 1 || op>3) {
		cout << "\n Optiunea nu este valida.";
		cin >> op;
	}

	if (op == 1) {
		cout << "Ati ales Robotul 1"<<endl<<endl;
		r = new Robot1(1);
	}
	if (op == 2) {
		cout << "Ati ales Robotul 2" << endl << endl;
		r = new Robot2(2);
	}
	if (op == 3) {
		cout << "Ati ales Robotul 3" << endl << endl;
		r = new Robot3(3);
	}

	r->descriereRobot();
	cout << "\n\n";

}


//Destructor
Game::~Game() {
	delete H;
	delete r;
	runda = 0;
	finish = 0;
}


//Simulare runda
void Game::runGame() {
	runda++;
	cout << "\nRunda " << runda << " :";

	pair<int, int> poz = r->getPozitie();					//Pozitia pe care se afla robotul
	pair<int, int> newPoz = r->alegPozNoua(*H);		//Noua pozitie pe care trebuie sa se mute robotul

	//Inseamna ca nu a gasit o alta pozitie, deci robotul s-a blocat
	if (newPoz == make_pair(-1, -1)) {
		cout << "\n Robotul s-a blocat. Mai joaca o data!"<<endl;
		
		this->finish = 1;
	}
	else {
		//Mut robotul pe noua pozitie
		cout << "\nRobotul s-a mutat de pe pozitia (" << poz.first << "," << poz.second << ") pe pozitia (" << newPoz.first << "," << newPoz.second << ")";
		r->mutareRobot(*H, newPoz.first, newPoz.second);

		//Daca robotul a ajuns la destinatie
		if (newPoz == H->getLocatie()) {
			cout << "\nAi ajuns la destinatie! Mai joaca o data!" << endl;
			this->finish = 1;
		}

		//Daca robotul si-a pierdut toate vietile inainte sa ajunga la destinatie
		if (r->getNrVieti() == 0) {
			cout << "\n Mai joaca o data!" << endl;
			this->finish = 1;
		}
	}
	cout << endl;
}


//Returneaza pozitia de finish
int Game::getFinish() const {
	return this->finish;
}


//Afiseaza harta la stadiul curent
void Game::print() {
	cout << *H;
}
