#include "blatt3.h"
#include <stdio.h>

void llistaddfront(struct llist * pllist, float fval) {
	if (pllist == nullptr) {
		printf("ERROR: Nullpointerexception. Cannot add value %f to nowhere! \n", fval);
		return;
	}
	struct llistel * neuerKnoten = new struct llistel; 
	neuerKnoten->data = fval; 
	neuerKnoten->next = pllist->first;
	neuerKnoten->prev = nullptr; 

	pllist->first = neuerKnoten;

	if (pllist->size == 0) {
		pllist->last = neuerKnoten; 
		pllist->size = 1; 
	}	else {
		neuerKnoten->next->prev = neuerKnoten;
		++pllist->size;
	}
}

void llistaddend(struct llist * pllist, float fval) {
	if (pllist == nullptr) {
		printf("ERROR: Nullpointerexception. Cannot add value %f to nowhere! \n", fval);
		return;
	}
	struct llistel * neuerKnoten = new struct llistel; 
	neuerKnoten->data = fval; 
	neuerKnoten->next = nullptr; 
	neuerKnoten->prev = pllist->last; 

	pllist->last = neuerKnoten; 

	if (pllist->size == 0) {
		pllist->first = neuerKnoten;
		pllist->size = 1;
	}	else {
		neuerKnoten->prev->next = neuerKnoten;
		++pllist->size;
	}
}

void llistcreatefront(struct llist * pllist, int num) {
	if (pllist == nullptr) {
		printf("ERROR: Nullpointerexception. Cannot create list into nowhere! \n");
		return;
	}
	for (--num; num >= 0; --num) {
		llistaddfront(pllist, static_cast<float>(num));
	}
}

void llistprint(struct llist * pllist) {
	if (pllist == nullptr) {
		printf("Liste nicht vorhanden. \n");
		return;
	}
	struct llistel * aktuell = pllist->first; 
	printf("komplette verkettete Liste vorwaerts (%i Elemente): \n", pllist->size);
	while (aktuell != nullptr) {
		printf("%f\n", aktuell->data);
		aktuell = aktuell->next;
	}
}

void llistprintrev(struct llist * pllist) {
	if (pllist == nullptr) {
		printf("Liste nicht vorhanden. \n");
		return;
	}
	struct llistel * aktuell = pllist->last;
	printf("komplette verkettete Liste rueckwaerts (%i Elemente): \n", pllist->size);
	while (aktuell != nullptr) {
		printf("%f\n", aktuell->data);
		aktuell = aktuell->prev;
	}

}

/**löscht die komplette Liste. */
void llistdelete(struct llist * pllist) {
	if (pllist == nullptr) {
		printf("Liste nicht vorhanden. \n");
		return;
	}
	struct llistel * aktuell = pllist->first, * next = nullptr; 
	int i = 0; 
	while (aktuell != nullptr) {
		++i; 
		printf("deleting Element %3i, Value: %12.5f \n", i, aktuell->data);
		next = aktuell->next; 
		
		//zur Nicht-Wiederherstellbarkeit auch im Speicher löschen:
		aktuell->next = nullptr; 
		aktuell->prev = nullptr; 
		aktuell->data = 0.0; 
		
		//Pointer löschen
		delete aktuell; 
		aktuell = next; 
	}
	
	//Hauptliste auf leere Liste aktualisieren
	pllist->first = nullptr; 
	pllist->last = nullptr; 
	pllist->size = 0; 

	printf("deleting successful. \n");
}

void llistinsert(struct llist * pllist, int p, float data) {
	if (pllist == nullptr) {
		printf("ERROR: Nullpointerexception. Cannot add value %f to nowhere! ", data);
		return;
	}
	if (p == 0) {
		//neues Element am Anfang
		llistaddfront(pllist, data); 
		return; 
	}	else if (p < 0 || p >= pllist->size) { 
		//neues Element am Ende
		llistaddend(pllist, data); 
		return;
	}	else {
		//neues Element echt in der Mitte
		struct llistel * nachfolger = pllist->first;
		for (; p > 0; --p) {
			nachfolger = nachfolger->next; 
		}

		struct llistel * neuerKnoten = new struct llistel;
		struct llistel * vorgaenger = nachfolger->prev; 
		neuerKnoten->data = data;
		neuerKnoten->next = nachfolger;
		neuerKnoten->prev = vorgaenger;
		nachfolger->prev = neuerKnoten;
		vorgaenger->next = neuerKnoten;
		++pllist->size; 
		return;
	}
}


int blatt_3_main() {
	struct llist llistvar; 
	
	llistvar.size = 0; 
	llistvar.first = NULL; 
	llistvar.last = NULL; 

	llistcreatefront(&llistvar, 10); 

	printf("\nprintout after list creation \n");
	llistprint(&llistvar);

	llistinsert(&llistvar, 0, 999.);
	llistinsert(&llistvar, 3, 999.);
	llistinsert(&llistvar, 12, 999.);

	printf("\nprintout after insert \n");
	llistprint(&llistvar);

	llistprintrev(&llistvar);

	llistdelete(&llistvar);

	return 0;
}