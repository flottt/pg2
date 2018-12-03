#include "MaterialList.h"

const char * MaterialList::getDefaultFilename() {
	static const char FILENAME[24] = "Blatt10\\materials.txt";
	return FILENAME;
}

Material * MaterialList::createEntity() {
	return new Material();
}
