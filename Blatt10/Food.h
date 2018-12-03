#ifndef __B10_FOOD_H__
#define __B10_FOOD_H__
#include "AbstractArticle.h" 

class Food : public AbstractArticle {
protected: 
	char supplier[ARTICLE_MAX_SUPPLIER_LENGTH + 1];
	int storeability; 
public: 
	Food(); 

	virtual void input();
	virtual void loadfromfile(std::ifstream & file);
	virtual void savetofile(std::ofstream & file) const;

	virtual void printout() const;
};

#endif //__B10_FOOD_H__