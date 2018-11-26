#include "ERB_Item.h"
int Item::MAX_ID = 0; 

Item::Item() : id(++MAX_ID) {
	printf("Konstruktor Item() #%i @%p \n", this->id, this);
}

Item::~Item() {
	printf("Destruktor ~Item() #%i @%p \n", this->id, this);
}

int Item::getId(void) const {
	return this->id;
}

void Item::debugDump(int byteAnzahl, int step) {
	if (byteAnzahl == 0) byteAnzahl = sizeof(this); 
	printf("DEBUGDUMP ITEM #%2i [%i / %i Bytes]: \n", this->id, byteAnzahl, sizeof(this)); 
	char line[33]; 
	line[32] = '\0';
	for (int i = 0; i < byteAnzahl; i++) {
		if (i % 2 == 0) printf(" "); 
		char cc = *(((char *)this) + (i * step));
		line[i % 32] = (cc < ' ' ? '.' : cc); 
		printf("%02x", cc & 0xFF);
		if (i % 32 == 31) {
			printf("  |  %32.32s \n", line); 
			for (int j = 0; j < 32; j++) line[j] = '\0';
		}
	}

	if (byteAnzahl % 32 != 0) {
		for (int i = 32 - byteAnzahl % 32; i > 0; i--) {
  		if (i % 2 == 0) printf("   ");  else printf("  "); 
		}
		printf("  |  %-32s \n", line);
	}
	printf("\n");
}
