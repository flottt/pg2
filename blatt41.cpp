// tests piggybank
#include "PiggyBank1.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void showCoins(unsigned int c1, unsigned int c10,
	unsigned int c50, unsigned int e1) {
	cout << c1 << " 1-Cent coin(s)" << endl;
	cout << c10 << " 10-Cent coin(s)" << endl;
	cout << c50 << " 50-Cent coin(s)" << endl;
	cout << e1 << " 1-Euro coin(s)" << endl;
}

int blatt_41_main() {
	unsigned int c1 = 0, c10 = 0, c50 = 0, e1 = 0;
	PiggyBank myPiggy;
	myPiggy.init(500);

	if (myPiggy.isEmpty())
		cout << "The piggy bank is empty" << endl;

	myPiggy.add1Cents(200);
	myPiggy.add10Cents(200);
	myPiggy.add50Cents(200);
	//myPiggy.add1Euros(200);

	if (myPiggy.isFull())
		cout << "The piggy bank is full" << endl;

	cout << "The piggy bank is being slaughtered!" << endl;
	unsigned long cents = myPiggy.breakInto(c1, c10, c50, e1);

	cout << "The outcome of the piggy bank has been: "
		<< endl;
	showCoins(c1, c10, c50, e1);

	cout << "That are " << cents << " cents."
		<< endl;

	system("Pause");
	return 0;
}

//int main() { return blatt_42_main(); }
#undef PiggyBank