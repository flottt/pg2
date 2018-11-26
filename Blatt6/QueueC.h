//Blatt 6
#ifndef __QUEUE_MAX_H__
#include "Queue.h"
#elif !defined(__QUEUE_MAX_C_H__) 
#define __QUEUE_MAX_C_H__
#include <stdio.h>
#include <stdlib.h>
#define NULLPTR nullptr 

QUEUE_TEMPLATE_HEADER
Queue_T::Queue(const int max) : capacity(max) {
	this->liste = new TYPE[max];
	this->queueInit();
}

QUEUE_TEMPLATE_HEADER
Queue_T::Queue(const Queue & that) : capacity(that.capacity) { //TODO _T
	this->liste = new TYPE[that.capacity];
	this->queueInitCopy(that);
}

QUEUE_TEMPLATE_HEADER
Queue_T & Queue_T::operator= (const Queue & that) { //TODO _T
	this->queueInitCopy(that);
	return *this; 
}

QUEUE_TEMPLATE_HEADER
Queue_T::~Queue() {
	delete[] this->liste;
	this->liste = NULLPTR;
}

QUEUE_TEMPLATE_HEADER
void Queue_T::queueInit(void) {
	this->head = this->tail = 0;
	this->size = 0; 
}

QUEUE_TEMPLATE_HEADER
void Queue_T::queueInitCopy(const Queue_T & that) {
	if (that.size > 0) {
		if (that.head < that.tail) {
			for (int i = that.head; i <= that.tail; ++i) {
				this->liste[i] = that.liste[i];
			}
		} else {
			for (int i = 0; i < that.capacity; ++i) {
				if (i == that.tail) {
					i = that.head; 
				}

				this->liste[i] = that.liste[i];
			}
		}
		this->head = that.head; 
		this->tail = that.tail; 
		this->size = that.size;
	} else {
		this->queueInit();
	}
}

QUEUE_TEMPLATE_HEADER
void Queue_T::enqueue(TYPE & data) {
	if (this->size == this->capacity) {
		printf("queue overflow. \n");
		exit(1);
	}
	this->liste[tail] = data; 
	tail = (tail + 1) % this->capacity; 
	this->size++;
}


QUEUE_TEMPLATE_HEADER
TYPE Queue_T::dequeue(void) {
	if (queueEmpty()) {
		printf("attempt to remove element from empty queue \n.");
		exit(1); 

	}
	--size; 
	TYPE element = liste[head]; 
	head = (head + 1) % this->capacity;
	return element;
}

QUEUE_TEMPLATE_HEADER
int Queue_T::queueEmpty() {
	return (this->size == 0);
}

QUEUE_TEMPLATE_HEADER
void print(Queue_T & that) {
	for (int i = 0; i < that.size; i++) {
		char formatstring[4] = "%i ";
		formatstring[1] = PRINTF_EXPR; 
		printf(formatstring, that.liste[(that.head + i) % that.capacity]);
	}
	printf("\n");
}
QUEUE_TEMPLATE_HEADER
void printLarge(Queue_T & that) {
	for (int i = 0; i < that.size; i++) {
		char formatstring[12] = "[%i] = %i \n";
		formatstring[8] = PRINTF_EXPR; 
		printf(formatstring, i, that.liste[(that.head + i) % that.capacity]);
	}
}

QUEUE_TEMPLATE_HEADER
Queue_T & Queue_T::operator+(TYPE data) {
	this->enqueue(data); 
	return *this;
}

QUEUE_TEMPLATE_HEADER
TYPE Queue_T::operator-() { 
	return this->dequeue();
}
#endif