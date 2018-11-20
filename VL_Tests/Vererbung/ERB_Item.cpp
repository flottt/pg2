#include "ERB_Item.h"
int Item::MAX_ID = 0; 

Item::Item() : id(++MAX_ID) {
	printf("Konstruktor Item() #%i @%p \n", this->id, this);
}

Item::~Item() {
	printf("Destruktor ~Item() #%i @%p \n", this->id, this);
}

int Item::getId() {
	return this->id;
}
