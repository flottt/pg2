#include <stdio.h>

typedef struct {
	int health = 100; 
	int alter = 0;
	int asked = 0; 
	char geschlecht = 'u'; 
} Mensch;

constexpr int xxx(int a, int b) {
	if (b == 0) return 0; 
	else return a % b;
}

constexpr int getAge(Mensch &mensch) {
	mensch.asked++;
	return mensch.alter; 
}

int leseIntZahl(const char * const text) {
	int result = 0; 
	printf(text); 
	printf(": ");
	scanf("%i", &result); 
	return result; 
}

int testung() {
	printf("Testung\n");
	int x = leseIntZahl("Zahl 1 eingeben"); 
	int y = leseIntZahl("Zahl 2 eingeben");
	printf("Ergebnis: %i\n", xxx(x, y));
	
	printf("MenschTest\n"); 
	Mensch adam;
	adam.alter = x; 
	adam.asked = y; 
	adam.geschlecht = 'm'; 

	printf("Alter %i\n", getAge(adam));
	printf("Ask %i\n", adam.asked);
	

	return 0;
}