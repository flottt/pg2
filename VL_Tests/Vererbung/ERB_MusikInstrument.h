#ifndef __ERB_Musik_Instrument_H__
#define __ERB_Musik_Instrument_H__
#define INSTRUMENT_NAME_MAX_LENGTH 35
#include "ERB_Item.h"

class Musikinstrument : public Item {
protected:
	char name[INSTRUMENT_NAME_MAX_LENGTH + 1];
	char hersteller[40]; 

	Musikinstrument(const char * name); 
	~Musikinstrument(); 
};

#endif // __ERB_Musik_Instrument_H__
