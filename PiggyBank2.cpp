#include "PiggyBank2.h"

PiggyBank::PiggyBank(unsigned int capacity) : capacity(capacity), frei(capacity) {
	for (int i = 0; i < PIGGYBANK2_ANZAHL_MUNZEN; ++i) {
		geld[i] = 0;
	}
}

bool PiggyBank::isEmpty() {
	return this->frei >= this->capacity;
}
bool PiggyBank::isFull() {
	return this->frei <= 0;
}
int PiggyBank::breakInto(unsigned int &c1, unsigned int &c10, unsigned int &c50, unsigned int &c100) {
	int werte[4], returnresult;
	returnresult = this->loot(werte);
	c1 = werte[0]; c10 = werte[1]; c50 = werte[2]; c100 = werte[3];
	return returnresult;
}

int PiggyBank::loot(int * muenzen) {
	int cent = 0, i;
	for (i = 0; i < PIGGYBANK2_ANZAHL_MUNZEN; ++i) {
		cent += werte[i] * this->geld[i];
		if (muenzen != nullptr) {
			muenzen[i] = this->geld[i];
		}
		this->geld[i] = 0;
	}
	this->frei = this->capacity;

	return cent;
}

bool PiggyBank::addCoins(int c1, int c10, int c50, int c100) {
	int summe = c1 + c10 + c50 + c100;
	if (summe > this->frei) return false;
	this->frei -= summe;
	this->geld[MUNZ1CENT] += c1;
	this->geld[MUNZ10CENT] += c10;
	this->geld[MUNZ50CENT] += c50;
	this->geld[MUNZ1EURO] += c100;
	return true;
}

bool PiggyBank::addCoins(PiggyBank * andere) {
	if (this == andere) return false;
	for (int i = PIGGYBANK2_ANZAHL_MUNZEN - 1; i > 0; --i) {
		if (andere->geld[i] <= this->frei) {
			//passt genug rein
			this->frei -= andere->geld[i];
			this->geld[i] += andere->geld[i];
			andere->frei += andere->geld[i];
			andere->geld[i] = 0;
		} else {
			//komplett fuellen
			andere->frei += this->frei;
			(andere->geld)[i] -= this->frei;
			this->geld[i] += this->frei;
			this->frei = 0;
			return false;
		}
	}
	return true;
}