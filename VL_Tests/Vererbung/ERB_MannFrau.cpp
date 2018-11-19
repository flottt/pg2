//SKIZZE
// KinderFactory  <--- Frau  
//       |              |  
//       V              V  
//  Lebewesen  <---  Mensch  <---  Mann


#include "ERB_MannFrau.h"

Mann::Mann(const char * vorname, int alter) : Mensch(vorname, alter) {
	printf("Konstruktor Mann(%.10s, %i): @%p\n", vorname, alter, this);
}
Frau::Frau(const char * vorname, int alter) : Mensch(vorname, alter) {
	printf("Konstruktor Frau(%.10s, %i): @%p\n", vorname, alter, this);
}

void Mann::geburtstag() {
	this->alter++;
}

Lebewesen * Frau::create(bool weiblich, const char * vorname) {
	if (vorname == NULLPTR) vorname = ""; 
	if (weiblich) {
		Frau * kindW = new Frau(vorname, 0); 
		printf("creating %s: %p [/%i]\n", vorname, kindW, sizeof(*kindW));
		Lebewesen * lebewesen = kindW; 
		printf("creating %s: %p [/%i]\n", vorname, lebewesen, sizeof(*lebewesen));

		return (Lebewesen *)/*(Mensch *)*/kindW;
	} else {
		Mann * kindM = new Mann(vorname, 0); 
		printf("creating %s: %p\n", vorname, kindM);
		return kindM;
	}
}

int vlVererbung_main() {
	printf("Vererbungstest\n");
	Mann max; 
	Mann fritz("Fritz", 47);
	printf("%.10s ist %i Jahre alt. \n", fritz.getName(), fritz.alter);
	fritz.geburtstag(); 
	printf("Heute feiert %.10s seinen %i. Geburtstag. \n", fritz.getName(), fritz.alter);
	fritz.doNothing();
	max.Lebewesen::die(); 
	//max.die(); //geht nicht, weil Mensch::die(int) existiert. 
	if (max.isAlive()) {
		printf("Max lebt noch. \n"); 
	} else {
		printf("Max ist tot. \n"); 
	}

	//Mensch heidi; //geht nicht, weil Mensch ist abstract. 
	Frau heidi("Heidi", 28);
	heidi.addGeldCent(2500);

	Lebewesen * lebewesen = heidi.create(true, "Jessica");
	Frau * jessi = dynamic_cast<Frau *>(lebewesen);
	
	printf("%.10s ist auf der Welt. %i Jahre alt. \n", jessi->getName(), jessi->Mensch::alter);
	printf("deleting %.10s: %p\n", jessi->getName(), jessi);
	jessi->die();
	delete jessi; 

	Mann * walter = dynamic_cast<Mann *>(heidi.create(false, "Walter")); 
	walter->geburtstag(); 
	walter->geburtstag(); 
	printf("%.10s ist auf der Welt. %i Jahre alt. \n", walter->getName(), walter->alter);
	printf("deleting %.10s: %p\n", walter->getName(), walter);
	delete walter; 
	printf("ok\n");
	return 0; 
}
