#ifndef __ERB_Musik_Saiteninstrument_H__
#define __ERB_Musik_Saiteninstrument_H__
#include "ERB_MusikInstrument.h"

class Saiteninstrument : private Musikinstrument {
protected: 
	int anzahlSaiten; 

	Saiteninstrument(const int anzahlSaiten, const char * name); 
	~Saiteninstrument(); 
	using Musikinstrument::name; 
	using Item::getId; 
};
#endif // __ERB_Musik_Saiteninstrument_H__
