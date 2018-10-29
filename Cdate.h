#ifndef ANZAHL_MONATE_IM_JAHR
#define ANZAHL_MONATE_IM_JAHR 12
int blatt_5_a1_main();
int blatt_5_a2_main();

enum struct CdateDarstellungsart : char {deutsch='g', englisch='e'};


class Cdate {
private: 
	static const int DAYS_OF_MONTH[ANZAHL_MONATE_IM_JAHR];
	
	int day, month, year; 
	CdateDarstellungsart presentingMode; 
	bool isSchaltjahr(); 
	void normalisiere();
	int workday(); 

public:
	Cdate();
	Cdate(int day, int month, int year); 
	Cdate(const Cdate &clone);
	~Cdate();

	void printout(); 
	void setPresentationMode(CdateDarstellungsart mode);
	void printoutWeekday(); 
	void printoutDay();
	void adddays(int tage); 
};
#endif // !ANZAHL_MONATE_IM_JAHR

