#ifndef __QUEUE_MAX_H__
#define __QUEUE_MAX_H__ 

template <typename TYPE>
class Queue {
private: 
	const int capacity;
	TYPE * liste;
	int head, tail; 
	int size; 

public:
	Queue(const int capacity); 
	~Queue(); 

	void enqueue(TYPE & data); 
	void queueInit(void); 
	TYPE dequeue(void); 
	int queueEmpty(); 
	inline int getSize() {return this->size;}
	inline int elements() { return this->getSize(); }
	inline void push(TYPE & data) { this->enqueue(data); }
	inline TYPE pop(void) { return this->dequeue(); }

	template <typename TYxxPE>  //ohne template-deklaration geht es nicht bei friend. 
	friend void print(Queue<TYxxPE> & that);

	Queue<TYPE> & operator+ (TYPE data);
	TYPE operator- (); 
};

#include "QueueC.h"
#endif //__QUEUE_MAX_H__ 