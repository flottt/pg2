#include <iostream>
#include "arraysort.h"

int blatt_71_main() {
	int n = 5;
	arraysort<> testi(n);
	testi[0] = 4; testi[1] = 2; testi[2] = 6; testi[3] = 1; testi[4] = -1;
	testi.printout();
	testi.quicksort(0, n - 1);
	testi.printout();
	std::cout << "\n\n";

	return 0;
}


int blatt_72_main() {
	int n = 5;
	arraysort<long> testi(n);
	testi[0] = 4; testi[1] = 2; testi[2] = 6; testi[3] = 1; testi[4] = -1;
	testi.printout();
	testi.quicksort(0, n - 1);
	testi.printout();
	std::cout << "\n\n";

	n = 6;
	arraysort<float> testf(n);
	testf[0] = 4.1f; testf[1] = 2.1f; testf[2] = 6.1f;  testf[3] = 1.4f; testf[4] = -1.2f; testf[5] = -0.2f;  //append f to solve warning
	testf.printout();
	testf.quicksort(0, n - 1);
	testf.printout();

	return 0;
}
