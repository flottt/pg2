#include "ERB_Saiteninstrument.h"

Saiteninstrument::Saiteninstrument(const int anzahlSaiten, const char * name, const char * hersteller) : Musikinstrument(name, hersteller), anzahlSaiten(anzahlSaiten) {
	printf("Konstruktor Saiteninstrument(%i, %10s) #%i @%p \n", anzahlSaiten, name, this->getId(), this);
}

Saiteninstrument::~Saiteninstrument() {
	printf("Destruktor Saiteninstrument() : %10s #%i @%p \n", name, this->getId(), this);
	
}

