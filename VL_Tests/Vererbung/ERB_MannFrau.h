#ifndef __ERB_Lebewesen_Mann_H__
#define __ERB_Lebewesen_Mann_H__
#include "ERB_Mensch.h"


// ------------- MANN -----------
class Mann : public Mensch {
public: 
	Mann(const char * vorname = "Max", int alter = 45); 
	void geburtstag(); 
};


// ------------- FRAU -----------
class KinderFactory : virtual private Lebewesen {
	virtual Lebewesen * create(bool weiblich, const char *) = 0;
};

class Frau final : public Mensch, private KinderFactory {
public:
	Frau(const char * vorname = "Max", int alter = 45);
	Lebewesen * create(bool weiblich = true, const char * vorname = NULLPTR);
	void die() { Lebewesen::die(); };
};

// ---------------
int vlVererbung_main();


#endif __ERB_Lebewesen_Mann_H__