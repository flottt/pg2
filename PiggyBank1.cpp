#include "PiggyBank1.h"


/*PiggyBank::PiggyBank() {
this->init();
}*/


void PiggyBank::init(int capacity) {
	this->capacity = capacity;
	this->frei = capacity;
	this->virgin = true;
	int i;
	for (i = 0; i < PIGGYBANK1_ANZAHL_MUNZEN; ++i) {
		geld[i] = 0;
	}
}

unsigned int PiggyBank::addMuenzen(unsigned int anzahl, Muenzwert typ) {
	if (!virgin) return anzahl;
	if (anzahl <= 0) {
		return anzahl;
	} else if (anzahl <= this->frei) {
		this->geld[(int)typ] += anzahl;
		this->frei -= anzahl;
		return 0;
	} else {
		anzahl -= this->frei;
		this->geld[(int)typ] += this->frei;
		this->frei = 0;
		return anzahl;
	}
}
unsigned int PiggyBank::add1Cents(unsigned int anzahl) {
	return this->addMuenzen(anzahl, Muenzwert::Mu01);
}
unsigned int PiggyBank::add10Cents(unsigned int anzahl) {
	return this->addMuenzen(anzahl, Muenzwert::Mu10);
}
unsigned int PiggyBank::add50Cents(unsigned int anzahl) {
	return this->addMuenzen(anzahl, Muenzwert::Mu50);
}
unsigned int PiggyBank::add1Euro(unsigned int anzahl) {
	return this->addMuenzen(anzahl, Muenzwert::Mu100);
}
bool PiggyBank::isEmpty() {
	return this->frei >= this->capacity;
}
bool PiggyBank::isFull() {
	return this->frei <= 0;
}
bool PiggyBank::isVirgin() {
	return this->virgin;
}
unsigned int PiggyBank::breakInto(unsigned int &c1, unsigned int &c10, unsigned int &c50, unsigned int &c100) {
	unsigned int werte[4], returnresult;
	returnresult = this->loot(werte);
	c1 = werte[0]; c10 = werte[1]; c50 = werte[2]; c100 = werte[3];
	return returnresult;
}

unsigned int PiggyBank::loot(unsigned int * muenzen) {
	int cent = 0, i;
	for (i = 0; i < PIGGYBANK1_ANZAHL_MUNZEN; ++i) {
		cent += werte[i] * geld[i];
		if (muenzen != nullptr) {
			muenzen[i] = geld[i];
		}
	}
	this->init(0);
	this->virgin = false;
	return cent;
}