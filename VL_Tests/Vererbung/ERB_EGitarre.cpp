#include "ERB_EGitarre.h"

EGitarre::EGitarre() : Gitarre(6, "E-Gitarre"), iSpannungMilliVolt(230) {
	printf("Konstruktor E-Gitarre() (%3i V %.10s) #%i @%p \n", this->iSpannungMilliVolt, this->name, this->getId(), this);
}

EGitarre::EGitarre(const Gitarre & refGitarre) {
	printf("ERB-Copy-Konstruktor E-Gitarre([%i]) (%3i V %.10s) #%i @%p \n", refGitarre.getId(), this->iSpannungMilliVolt, this->name, this->getId(), this);

}

EGitarre::~EGitarre() {
	printf("Destruktor ~E-Gitarre(%.10s) #%i @%p \n", this->name, this->getId(), this);
}

int musikEGitarre_main() {
	printf("Musikinstrumente -- E-Gitarre -- Vererbungstest Parent Object einem Child Object zuweisen. \n");
	Gitarre g1(8, "Quadgitarre"); 
	EGitarre e2; 

	printf("SizeOf  Gitarre = %i. \nSizeOf EGitarre = %i\n", sizeof(g1), sizeof(e2));

	g1.debugDump(90); 
	e2.debugDump(90); 
	printf(" --- A --- \n");
//	g1 = e2;
	e2 = g1;
	printf(" --- B --- \n");
	
	printf("SizeOf  Gitarre = %i. \nSizeOf EGitarre = %i\n", sizeof(g1), sizeof(e2));
	g1.debugDump(90); 
	e2.debugDump(90); 

	return 0;
}
