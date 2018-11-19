#ifndef __ERB_Lebewesen_H__
#define __ERB_Lebewesen_H__
#define ERB_Mensch_MAX_LENGTH_NAME 20
#define NULLPTR nullptr 
#include <stdio.h>

/** abstract. Lebewesen können wegsterben und haben ein Alter. */
class Lebewesen {
private: 
	bool lebt; 
	virtual void xxx() {}
protected: 
	int alter; 
	inline Lebewesen() : lebt(true) { printf("Konstruktor Lebewesen(): @%p \n", this);  }
	// int doNothing; geht nicht -> Funktion und Variable dürfen nicht gleich heissen. 
public: 
	inline bool isAlive() { return this->lebt; }
	inline void die() { this->lebt = false; }
	inline int getAlter() { return this->alter; }
	void doNothing(); 
};

/** abstract. */
class Mensch : virtual public Lebewesen {
private: 
	int geldCent; 
protected: 
	Mensch * partner; 
	char vorname[ERB_Mensch_MAX_LENGTH_NAME + 1]; 
	//using Lebewesen::doNothing; //Einschränkung ist möglich und führt zum nicht-ausreichend-access-fehler. Ohne gehts. 

protected: 
	Mensch(const char * vorname, int alter); 
public: 
	//inline Mensch(void) {}; //nur zum testen. 
	using Lebewesen::alter; 
	//using Lebewesen::lebt; //private kann nicht höher freigegeben werden. 

	inline int getGeldCent(void) { return this->geldCent; }
	inline void addGeldCent(int money) { this->geldCent += money; }
	inline const char * getName() { return this->vorname; }
	void die(int abAlter); 
};
#endif //__ERB_Lebewesen_H__