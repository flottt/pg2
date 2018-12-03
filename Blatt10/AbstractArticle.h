#ifndef __B10_ABSTRACTARTICLE_H__
#define __B10_ABSTRACTARTICLE_H__
#include <iostream>
#include <fstream>
#define ARTICLE_MAX_DESCRIPTION_LENGTH 20 
#define ARTICLE_MAX_SUPPLIER_LENGTH 20 


class AbstractArticle {
private: 
	friend class AbstractList;
	AbstractArticle * next; 
protected: 
	char descr[ARTICLE_MAX_DESCRIPTION_LENGTH + 1]; 
	int id; 
	int stock; 
	int minstock; 
	float price; 

protected: 
	AbstractArticle();
	AbstractArticle(const char * descr, const int id); 
	AbstractArticle(const AbstractArticle &); 
	void load_checkOrFailString(char * text, const char * propertyname, const int TEXT_CAPACITY); 
public: 
	virtual void input(); 
	virtual void printout() const; 
	virtual void savetofile(std::ofstream & file) const; 
	virtual void loadfromfile(std::ifstream & file);

public: 
	virtual ~AbstractArticle(); 
	int addstock(int anzahl); 
	int removestock(int anzahl); 
	inline AbstractArticle & operator+(const int anzahl) { this->removestock(-anzahl); return *this; }
	inline AbstractArticle & operator-(const int anzahl) { this->removestock(anzahl); return *this; }

};

#endif //__B10_ABSTRACTARTICLE_H__