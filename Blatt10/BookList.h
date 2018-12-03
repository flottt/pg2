#ifndef __B10_BOOKLIST_H__
#define __B10_BOOKLIST_H__
#include "AbstractList.h" 
#include "Book.h"

class BookList : public AbstractList {
private: 

public: 
	virtual const char * getDefaultFilename();
	virtual Book * createEntity(); 
};

#endif //__B10_BOOKLIST_H__