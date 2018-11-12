#ifndef __BLATT_35_H__
#define __BLATT_35_H__
#include "blatt3.h"

struct blistel {
	struct llist * data;
	struct blistel * next;
};

struct blist {
	struct blistel *first = nullptr;
	int size = 0;
};

int blatt_35_main();
void llistprintSingleLine(struct llist * pllist);
void blistaddfront(struct blist * pblist, int num);
void blistcreatefront(struct blist * pblist, int numa, int numb);
void blistprint(struct blist * pblist);
void blistdelete(struct blist * pblist);

#endif // !__BLATT_35_H__