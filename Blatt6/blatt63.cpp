#include "Queue.h"
#include <Windows.h>

using IntQueue = Queue<>; 
using HexQueue = Queue<int, 'X'>; 
using DoubleQueue = Queue<double, 'F'>;

int blatt_63_main() {
	IntQueue myQueue(20); 

	myQueue + 2 + 44 + 666 + 8888 + 0;
	myQueue + 1 + 3 + 5 + 7 + 9;

	DoubleQueue herQueue(12);
	HexQueue hexQueue(20);

	printf("The int queue (%i Elememts): \n", myQueue.getSize());
	print(myQueue);

	double part = 1.0; 
	while (myQueue.elements()) {
		int value = -myQueue;
		part /= value;
		herQueue + part; 
		hexQueue + value; 
	}

	printf("\nThe int Queue with hex representation (%i Elements): \n", hexQueue.getSize());
	print(hexQueue);

	printf("\nThe QUEUE (%i Elements): \n", herQueue.getSize()); 
	print(herQueue);

	DoubleQueue hisQueue = herQueue; 

	printf("\nCopied QUEUE hisQueue (%i Elements): \n", hisQueue.getSize());
	print(hisQueue);

	herQueue + 100; 
	herQueue + 200; 
	herQueue + -herQueue;
	printf("\nExtended full herQUEUE (%i Elements): \n", herQueue.getSize());
	print(herQueue);

	herQueue = hisQueue; 
	herQueue + 300; 
	printf("\nRestored herQUEUE: (%i Elements): \n", herQueue.getSize());
	print(herQueue);
	system("pause");

	herQueue = hisQueue; 

	herQueue + 400; 
	herQueue + 500; 
	herQueue + 1313;
	printf("\nFehler: queue-overflow (%i Elements): \n", herQueue.getSize());

	return 0;
}