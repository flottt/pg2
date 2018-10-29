#include "blatt35.h"
#include <stdio.h>


void llistprintSingleLine(struct llist * pllist) {
	if (pllist == nullptr) {
		printf("Liste nicht vorhanden. \n");
		return;
	}
	struct llistel * aktuell = pllist->first;
	int i = 0;
	while (aktuell != nullptr) {
		++i;
		printf("a%02i: %5.2f \t", i, aktuell->data);
		aktuell = aktuell->next;
	}
}

void blistaddfront(struct blist * pblist, int num) {
	if (pblist == nullptr) {
		printf("ERROR: Nullpointerexception. Cannot add %i Lists to nowhere! \n", num);
		return;
	}

	struct blistel * neuerKnoten = new struct blistel;
	neuerKnoten->data = new struct llist;
	llistcreatefront(neuerKnoten->data, num);
	neuerKnoten->next = pblist->first;
	pblist->first = neuerKnoten;
	++pblist->size;
}

void blistcreatefront(struct blist * pblist, int numa, int numb) {
	if (pblist == nullptr) {
		printf("ERROR: Nullpointerexception. Cannot add %i Lists to nowhere! \n", numb);
		return;
	}

	for (--numb; numb >= 0; --numb) {
		blistaddfront(pblist, numa);
	}
}

void blistprint(struct blist * pblist) {
	if (pblist == nullptr) {
		printf("Liste nicht vorhanden. \n");
		return;
	}

	struct blistel * aktuell = pblist->first;
	struct llist * dataList = nullptr;
	int i = 0;

	printf("komplette doppelt verkettete Liste: \n");
	while (aktuell != nullptr) {
		++i;
		dataList = aktuell->data;
		printf("b%02i: ", i);
		if (dataList != nullptr) {
			llistprintSingleLine(dataList);
		}
		printf("\n");
		aktuell = aktuell->next;
	}

}

void blistdelete(struct blist * pblist) {
	if (pblist == nullptr) {
		printf("Liste nicht vorhanden. \n");
		return;
	}

	struct blistel * aktuell = pblist->first, *next = nullptr;
	struct llist * dataList = nullptr;

	while (aktuell != nullptr) {
		next = aktuell->next;
		dataList = aktuell->data;
		if (dataList != nullptr) {
			llistdelete(dataList);
			delete dataList;
			dataList = nullptr;
		}

		aktuell->next = nullptr;
		aktuell->data = nullptr;
		delete aktuell;

		aktuell = next;
	}
}

int blatt_35_main() {
	struct blist blistvar;
	blistvar.size = 0;
	blistvar.first = NULL;

	blistcreatefront(&blistvar, 3, 4); //struct blist* pblist, int numa, int numb
	printf("\nprintout after list creation\n");
	blistprint(&blistvar);

	blistdelete(&blistvar);
	return 0;
}
