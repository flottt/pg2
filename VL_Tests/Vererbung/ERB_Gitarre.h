#ifndef __ERB_Musik_Gitarre_H__
#define __ERB_Musik_Gitarre_H__
#include "ERB_Saiteninstrument.h"

class Gitarre : public Saiteninstrument {
protected: 
public: 
	Gitarre(); 
	Gitarre(const int saitenAnzahl, const char * name); 
	~Gitarre();
	using Saiteninstrument::name;
	
};

// -----
int musik_main(); 
#endif // __ERB_Musik_Gitarre_H__
