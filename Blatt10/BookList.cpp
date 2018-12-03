#include "BookList.h"

const char * BookList::getDefaultFilename() {
	static const char FILENAME[20] = "Blatt10\\books.txt";
	return FILENAME;
}

Book * BookList::createEntity() {
	return new Book(); 
}
