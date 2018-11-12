#ifndef PIGGYBANK2_ANZAHL_MUNZEN 
#define MUNZ1CENT 0 
#define MUNZ10CENT 1 
#define MUNZ50CENT 2
#define MUNZ1EURO 3
#define PIGGYBANK2_ANZAHL_MUNZEN 4 
#define PiggyBank PiggyBank2
class PiggyBank2 {
private:
	const unsigned int werte[PIGGYBANK2_ANZAHL_MUNZEN] = { 1, 10, 50, 100 };
	unsigned int geld[PIGGYBANK2_ANZAHL_MUNZEN];
	const unsigned int capacity;
	unsigned int frei;

public:
	bool addCoins(unsigned int &c1, unsigned int &c10, unsigned int &c50, unsigned int &c100);
	bool addCoins(PiggyBank2 * andere);
	bool isEmpty();
	bool isFull();
	int loot(int * muenzen);
	int breakInto(unsigned int &c1, unsigned int &c10, unsigned int &c50, unsigned int &c100);

	PiggyBank2(unsigned int capacity);
};

#endif