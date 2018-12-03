#ifndef __B10_MATERIALLIST_H__
#define __B10_MATERIALLIST_H__
#include "AbstractList.h" 
#include "Material.h"

class MaterialList : public AbstractList {
	static const char FILENAME[20];

public:
	virtual const char * getDefaultFilename();

	virtual Material * createEntity();
};

#endif //__B10_MATERIALLIST_H__