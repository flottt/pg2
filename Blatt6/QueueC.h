#ifndef __QUEUE_MAX_H__
#include "Queue.h"
#elif !defined(__QUEUE_MAX_C_H__) 
#define __QUEUE_MAX_C_H__
#include <stdio.h>
#include <stdlib.h>
#define NULLPTR nullptr 

template <typename TYPE> 
Queue<TYPE>::Queue(const int max) : capacity(max) {
	this->liste = new TYPE[max];
	this->queueInit();
}

template <typename TYPE> 
Queue<TYPE>::~Queue() {
	delete[] this->liste;
	this->liste = NULLPTR;
}

template <typename TYPE> 
void Queue<TYPE>::enqueue(TYPE & data) {
	if (this->size == this->capacity) {
		printf("queue overflow. \n");
		exit(1);
	}
	this->liste[tail] = data; 
	tail = (tail + 1) % this->capacity; 
	this->size++;
}

template <typename TYPE> 
void Queue<TYPE>::queueInit(void) {
	this->head = this->tail = 0;
	this->size = 0; 
}

template <typename TYPE> 
TYPE Queue<TYPE>::dequeue(void) {
	if (queueEmpty()) {
		printf("attempt to remove element from empty queue \n.");
		exit(1); 

	}
	--size; 
	TYPE element = liste[head]; 
	head = (head + 1) % this->capacity;
	return element;
}

template <typename TYPE>
int Queue<TYPE>::queueEmpty() {
	return (this->size == 0);
}

template <typename TYPE>
void print(Queue<TYPE> & that) {
	for (int i = 0; i < that.size; i++) {
		printf("[%i] = %i \n", i, that.liste[(that.head + i) % that.capacity]);
	}


}

template <typename TYPE> 
Queue<TYPE> & Queue<TYPE>::operator+(TYPE data) {
	this->enqueue(data); 
	return *this;
}

template <typename TYPE> 
TYPE Queue<TYPE>::operator-() { 
	return this->dequeue();
}
#endif