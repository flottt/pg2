#include "FoodList.h"

const char * FoodList::getDefaultFilename() {
	static const char FILENAME[19] = "Blatt10\\food.txt";
	return FILENAME;
}

Food * FoodList::createEntity() {
	return new Food();
}
