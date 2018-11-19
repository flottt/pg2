#include "ERB_Mensch.h"

Mensch::Mensch(const char * vorname, int alter) : partner(NULLPTR) {
	printf("Konstruktor Mensch(%.10s, %i): @%p \n", vorname, alter, this);
	this->alter = alter; 
	this->vorname[ERB_Mensch_MAX_LENGTH_NAME] = '\0';
	for (int i = 0; i < ERB_Mensch_MAX_LENGTH_NAME; ++i) {
		this->vorname[i] = vorname[i]; 
		if (vorname[i] == '\0') break; 
	}
}

void Mensch::die(int abAlter) {
	if (this->alter >= abAlter) {
		this->Lebewesen::die();
	}
}

void Lebewesen::doNothing() {
	printf("nichts tun \n");
}
