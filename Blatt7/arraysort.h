#ifndef __blatt7_arraysort_h__
#define __blatt7_arraysort_h__
#include <iostream>
#include <stdlib.h>

template <typename TYPE=int>
class arraysort {
private: 
	const int capacity;
	TYPE * liste; 


public:
	arraysort(const int capacity);
	~arraysort(); 

	TYPE & operator[] (const int index);

	void printout(); 
	void quicksort(int from, int to); 
};




template<typename TYPE=int>
arraysort<TYPE>::arraysort(const int capacity) : capacity(capacity) {
	this->liste = new TYPE[capacity];
}

template<typename TYPE=int>
inline arraysort<TYPE>::~arraysort() {
	delete[] this->liste;
}

template<typename TYPE=int>
inline TYPE & arraysort<TYPE>::operator[](const int index) {
	return liste[index];
}

template<typename TYPE>
void arraysort<TYPE>::printout() {
	for (int i = 0; i < this->capacity; ++i) {
		std::cout << "[" << i << "] = " << this->liste[i] << std::endl;
	}
}

template<typename TYPE> 
int fktPointerKleiner(const void * p1, const void * p2) {
	return *(TYPE *)(p1) < *(TYPE *)(p2); 
}

template<typename TYPE>
inline void arraysort<TYPE>::quicksort(int from, int to) {
	//TODO from to
	int(*fktPointerKlein) (const void * p1, const void * p2) = &fktPointerKleiner<TYPE>; 
	qsort(this->liste, this->capacity, sizeof(TYPE), fktPointerKlein);
}



#endif // !__blatt7_arraysort_h__ 
