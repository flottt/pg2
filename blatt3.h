#ifndef __BLATT_3_H__
#define __BLATT_3_H__

struct llistel {
	float data = 0.0;
	struct llistel *next = nullptr;
	struct llistel *prev = nullptr;
};

struct llist {
	struct llistel *first = nullptr;
	struct llistel *last = nullptr;
	int size = 0;
};

int blatt_3_main();
void llistaddfront(struct llist * pllist, float fval);
void llistaddend(struct llist * pllist, float fval); 
void llistcreatefront(struct llist * pllist, int num);
void llistprint(struct llist * pllist);
void llistprintrev(struct llist * pllist); 
void llistinsert(struct llist * pllist, int p, float data);
void llistdelete(struct llist * pllist);

#endif // !__BLATT_3_H__