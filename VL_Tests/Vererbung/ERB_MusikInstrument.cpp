#include "ERB_MusikInstrument.h"

Musikinstrument::Musikinstrument(const char * name) {
	printf("Konstruktor Musikinstrument(%.10s) #%i @%p \n", name, this->getId(), this);
	for (int i = 0; i < INSTRUMENT_NAME_MAX_LENGTH; ++i) {
		this->name[i] = name[i]; 
		if (name[i] == '\0') break; 
	}
}

Musikinstrument::~Musikinstrument() {
	printf("Destruktor Musikinstrument() #%i @%p \n", this->getId(), this);
}
