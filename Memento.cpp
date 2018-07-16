#include <vector>
#include "Juego.h"

class Memento {
private:
	vector<Juego*> backup;
	//Juego backup[100];
	int t;
public:
	Memento() {
		//backup = new Juego({ 1300,700 }, "RapidRoll")[100];
		t = 0;
	}

	void setBackup(Juego *bd) {
		backup.push_back(bd);
		t++;
	}

	Juego* getBackup(int i) {
		Juego *c = backup[i];
		return c;
	}

	int getSize() {
		return t;
	}
};
