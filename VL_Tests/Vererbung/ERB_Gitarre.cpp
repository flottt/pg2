#include "ERB_Gitarre.h"



Gitarre::Gitarre() : Saiteninstrument(6, "Gitarre") {
	printf("Konstruktor Gitarre(%.10s) #%i @%p \n", this->name, this->getId(), this);
}

Gitarre::~Gitarre() {
	printf("Destruktor ~Gitarre(%.10s) #%i @%p \n", this->name, this->getId(), this);
}

int musik_main() {
	printf("Musikinstrumente -- Vererbungstest \n");
	Gitarre g1; 


	return 0;
}
