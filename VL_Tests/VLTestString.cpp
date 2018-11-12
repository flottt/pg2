#include "VLTestString.h"
#include <stdio.h> 
#include <stdlib.h>
int VLTestString::wert = 10;


VLTestString::VLTestString(int x) { //default parameter darf in definition nicht stehen.
	this->iii = x;
	printf("Creating Teststring %5i.   ..... p=%p \n", x, this);
}

VLTestString::~VLTestString() {
	VLTestString::wert++;
	printf("Destructing %3i: iii = %5i   .....  p=%p \n", VLTestString::wert, this->iii, this);
	this->iii = -1; 
}

inline int VLTestString::get() { return this->iii; }
void uselessFkt(int i = 0) {
	volatile int j[32] = { 0 };
	printf(".%i .. %p\n", j[20], j);
}

void testExecute() {
	printf("starte TestString \n");
	printf("ini\n");
	int kk = 0; 
	VLTestString s1; 
	VLTestString s2 = 2; 
	VLTestString s3 = 3; 
	VLTestString s4 = s1; 
	printf("ini fertig\n");
	s3 = s2; 
	s3 = s1; 
	printf("overridden\n"); 
	printf("Pointer: 1: %p, 2: %p, 3: %p, 4: %p \n", &s1, &s2, &s3, &s4);
	printf("start adding\n");
	VLTestString * sp =  &(s3 + s2 + s1); 
	kk = sp->iii;
	s1 = *sp;
	printf("Pointer: sp: %p = %i \n", sp, kk); 
	printf("end adding\n");
	uselessFkt();
	printf("Pointer: sp: %p = %i \n", sp, sp->get()); 
	printf("start addingeq\n");
	s1 += s3;
	printf("end addingeq\n");
	printf("Ende\n");
}

int testStringMain() {
	printf("--- 1. Durchlauf --- \n");
	testExecute();
	printf("--- 2. Durchlauf --- \n");
	testExecute();
	printf("--- 3. Durchlauf --- \n");
	testExecute();
	return 0; 
}

VLTestString & operator+(VLTestString & s1, VLTestString & s2) {
	VLTestString xxx = s1.iii + s2.iii;
	VLTestString yyy = 27;
	xxx.iii = 999;
	printf("returning teststring p=%p  (op+ %i [%p] + %i [%p] )  \n", &xxx, s1.iii, &s1, s2.iii, &s2);
	return xxx;
}

VLTestString & operator+=(VLTestString & s1, VLTestString & s2) {
	s1.iii += s2.iii;
	return s1; 
}
