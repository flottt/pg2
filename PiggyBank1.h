#ifndef PIGGYBANK1_ANZAHL_MUNZEN 
#define PiggyBank PiggyBank1
#define PIGGYBANK1_ANZAHL_MUNZEN 4 
enum struct Muenzwert : int { Mu01 = 0, Mu10 = 1, Mu50 = 2, Mu100 = 3 };

class PiggyBank {
private:
	const unsigned int werte[PIGGYBANK1_ANZAHL_MUNZEN] = { 1, 10, 50, 100 };
	unsigned int geld[PIGGYBANK1_ANZAHL_MUNZEN];
	unsigned int capacity;
	unsigned int frei;
	bool virgin; 
	unsigned int addMuenzen(unsigned int anzahl, Muenzwert typ);
public:
	void init(int capacity);
	unsigned int add1Cents(unsigned int anzahl);
	unsigned int add10Cents(unsigned int anzahl);
	unsigned int add50Cents(unsigned int anzahl);
	unsigned int add1Euro(unsigned int anzahl);
	bool isEmpty();
	bool isFull();
	bool isVirgin();
	unsigned int loot(unsigned int * muenzen);
	unsigned int breakInto(unsigned int &c1, unsigned int &c10, unsigned int &c50, unsigned int &c100);
	
};

#endif