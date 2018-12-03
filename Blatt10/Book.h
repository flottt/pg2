#ifndef __B10_BOOK_H__
#define __B10_BOOK_H__
#include "AbstractArticle.h" 
#define BOOK_MAX_PUBLISHER_LENGTH 20 
#define BOOK_MAX_AUTHOR_LENGTH 20 

class Book : public AbstractArticle {
protected: 
	char publisher[BOOK_MAX_PUBLISHER_LENGTH + 1];
	char author[BOOK_MAX_AUTHOR_LENGTH + 1];
public: 
	Book(); 

	virtual void input(); 
	virtual void loadfromfile(std::ifstream & file); 
	virtual void savetofile(std::ofstream & file) const;
	
	virtual void printout() const;
};

#endif //__B10_BOOK_H__