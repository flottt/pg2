#include <iostream>
using namespace std;
#include "llistc81.h"

int blatt_81_main() {

	llistc llistco;

	llistco.insert(0, 0.0);
	llistco.insert(1, 1.0);
	llistco.append(2.0);
	llistco.insert(3, 3.0);

	cout << "printout\n";
	llistco.printout();

	//return 0;
	cout << "extended testing" << endl; 
	llistc li; 
	li.insert(7, 1.5); 
	li.insert(7, 2.5); 
	li.insert(1, -3); 
	li.insert(1, -4); 
	li.insert(4, -5);
	li.insert(4, -6);
	li.insert(4, -7);
	li.insert(0, 0);

	li.printout();

	return 0;
}