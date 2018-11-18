#include "VLTestTemplateOfTemplate.h"
// Vorlesung Templates Seite 29ff

int vlTestTemplateTemplate_main(void) {
	MengeEndlich<> definitionsMenge(255); 
	MengeEndlich<> werteMenge(255); 

	definitionsMenge + 8 + 7 + 6 + 5 + 4;
	werteMenge + 1 + 2 + 3 + 4; 
	

	//map1 uses templateOfTemplate with the explicit ToT declaration 
	MapEndlich<> map1(definitionsMenge, werteMenge);

	definitionsMenge + 101 + 102; //wird nicht übernommen
	map1.printHead();

	//map2 uses template, which is a template, but implicit
	MapEndlich2<> map2(definitionsMenge, werteMenge); 

	map2.printHead();

	//now test it with non-default-datatype: double
	MengeEndlich<double> defDouble(255); 
	MengeEndlich<double> werteDouble(255); 

	defDouble + 99 + 88 + 77 + 66 + 55 + 44;
	werteDouble + 11 + 22 + 33 + 44; 

	//map3 like map1
	MapEndlich<double, double> map3(defDouble, werteDouble); //MapEndlich<double,double,MapEndlich>
	map3.printHead();
	
	//map4 like map2
	MapEndlich2<MengeEndlich<double>, MengeEndlich<double>> map4(defDouble, werteDouble); 
	map4.printHead(); 

	return 0; 
}
