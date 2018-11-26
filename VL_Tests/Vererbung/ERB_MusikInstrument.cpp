#include "ERB_MusikInstrument.h"

Musikinstrument::Musikinstrument(const char * name, const char * hersteller) {
	printf("Konstruktor Musikinstrument(%10s) #%i @%p von %.18s \n", name, this->getId(), this, hersteller);
	for (int i = 0; i < INSTRUMENT_HERSTELLER_MAX_LENGTH; ++i) {
		this->hersteller[i] = hersteller[i]; 
		if (hersteller[i] == '\0') break; 
	}
	
	for (int i = 0; i < INSTRUMENT_NAME_MAX_LENGTH; ++i) {
		this->name[i] = name[i]; 
		if (name[i] == '\0') break; 
	}

}
Musikinstrument::Musikinstrument(const char * name) : Musikinstrument(name, "unbekannter Hersteller") {}

Musikinstrument::~Musikinstrument() {
	printf("Destruktor Musikinstrument() #%i @%p \n", this->getId(), this);
}

void Musikinstrument::print() {
	printf("printing [%2i]Musikinstrument %.10s von %.10s", this->getId(), this->name, this->hersteller); 
}
