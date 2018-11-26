#ifndef __ERB_Musik_Instrument_H__
#define __ERB_Musik_Instrument_H__
#define INSTRUMENT_NAME_MAX_LENGTH 35
#define INSTRUMENT_HERSTELLER_MAX_LENGTH 39
#include "ERB_Item.h"

class Musikinstrument : public Item {
protected:
	char name[INSTRUMENT_NAME_MAX_LENGTH + 1];
	char hersteller[INSTRUMENT_HERSTELLER_MAX_LENGTH + 1]; 

	Musikinstrument(const char * name, const char * hersteller);
	Musikinstrument(const char * name); 
	~Musikinstrument(); 

public: 
	void print(); 
};

#endif // __ERB_Musik_Instrument_H__
