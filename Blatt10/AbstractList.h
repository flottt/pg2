#ifndef __B10_ABSTRACTLIST_H__
#define __B10_ABSTRACTLIST_H__
#include "AbstractArticle.h" 
#include <iostream>
#include <fstream>

class AbstractList {
protected:
	AbstractArticle * first; 
	AbstractList(); 
	virtual const char * getDefaultFilename() = 0; 
	virtual AbstractArticle * createEntity() = 0;

public: 
	virtual ~AbstractList(); 
	void loadfromfile(const char * filename = nullptr);
	void savetofile(const char * filename = nullptr);
	void removeAll(); 

	void input(); 
	virtual void printout(); 
	void printAskId() const;

	AbstractArticle * searchid(const int id) const; 
	AbstractArticle * searchdescr(const char * descr) const;
	virtual void addelement(AbstractArticle &); 

};

#endif //__B10_ABSTRACTLIST_H__