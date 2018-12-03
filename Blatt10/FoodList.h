#ifndef __B10_FOODLIST_H__
#define __B10_FOODLIST_H__
#include "AbstractList.h" 
#include "Food.h"

class FoodList : public AbstractList {
	static const char FILENAME[20];

public:
	virtual const char * getDefaultFilename();

	virtual Food * createEntity();
};

#endif //__B10_FOODLIST_H__