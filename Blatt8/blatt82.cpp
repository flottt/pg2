#include <iostream>
using namespace std;
#include "llistc82.h"

int blatt_82_main() {

	llistc<float> llistco;

	llistco.insert(0, 0.0);
	llistco.insert(1, 1.0);
	llistco.append(2.0);
	llistco.insert(3, 3.0);

	cout << "printout\n";
	llistco.printout();

	return 0;
}