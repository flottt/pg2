// tests overloaded methods addCoins() of the class piggy bank

#include "piggyBank2.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void showCoins2(unsigned int c1, unsigned int c10, unsigned int c50, unsigned int e1) {
	cout << c1 << " 1-Cent coin(s)" << endl;
	cout << c10 << " 10-Cent coin(s)" << endl;
	cout << c50 << " 50-Cent coin(s)" << endl;
	cout << e1 << " 1-Euro coin(s)" << endl;
}

int blatt_42_main() {
	PiggyBank myPiggy(1000),
		yourPiggy(1000);
	unsigned int  c1 = 0, c10 = 0, c50 = 0, e1 = 0;
	unsigned long cents = 0;

	// insert some coins:
	c1 = 400, c10 = 300, c50 = 200, e1 = 50;
	cout << "I insert these coins in my piggy bank:" << endl;
	showCoins2(c1, c10, c50, e1);
	myPiggy.addCoins(c1, c10, c50, e1);


	c1 = 300, c10 = 200, c50 = 200, e1 = 10;
	cout << "\nI insert these coins in your piggy bank:" << endl;
	showCoins2(c1, c10, c50, e1);
	yourPiggy.addCoins(c1, c10, c50, e1);


	cout << "\nHey, lets break your piggy bank"
		<< " and insert the found coins in my piggy bank!" << endl;
	if (myPiggy.addCoins(&yourPiggy)) {
		cout << "Thank you for all your coins!" << endl;
	} else {
		cout << "\nOnly a part of your coins fit in my piggy bank!" << endl;
		cout << "The rest of your coins out of your piggy bank: " << endl;
		yourPiggy.breakInto(c1, c10, c50, e1);
		showCoins2(c1, c10, c50, e1);
	}

	system("Pause");
	return 0;
}

/* int main() { return blatt_42_main(); } */
#undef PiggyBank