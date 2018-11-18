#include "Queue.h"
#include <Windows.h>
#define queue Queue<>

int blatt_63_main() {
	queue myQueue(20); 

	myQueue + 2 + 4 + 6 + 8 + 10;
	myQueue + 1 + 3 + 5 + 7 + 9;

	Queue<double, 'f'> herQueue(12);

	printf("The int queue (%i Elememts): \n", myQueue.getSize());
	print(myQueue);

	double part = 1.0; 
	while (myQueue.elements()) {
		part /= -myQueue;
		herQueue + part; 
	}

	printf("\nThe QUEUE (%i Elements): \n", herQueue.getSize()); 
	print(herQueue);

	Queue<double, 'f'> hisQueue = herQueue; 

	printf("\nCopied QUEUE hisQueue (%i Elements): \n", hisQueue.getSize());
	print(hisQueue);

	herQueue + 100; 
	herQueue + 200; 
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