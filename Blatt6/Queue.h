//Blatt 6
#ifndef __QUEUE_MAX_H__
#define __QUEUE_MAX_H__ 
#define QUEUE_TEMPLATE_HEADER template <typename TYPE = int, char PRINTF_EXPR = 'i'>
#define Queue_T Queue<TYPE, PRINTF_EXPR>

QUEUE_TEMPLATE_HEADER 
class Queue {
private: 
	/** capacity is the count of objects the queue can take. */
	const int capacity;
	
	/**the content of the queue. */
	TYPE * liste;
	
	/** head is the next object to get. 
	 * tail ist the free space, where the next pushed object appears. */
	int head, tail; 
	
	/** size is the count of object waiting in the queue. */
	int size; 

	/**replaces all objects by the given queue's objects. */
	void queueInitCopy(const Queue_T &);


public:
	/**constructor for a new queue with given capacity. */
	Queue(const int capacity); 
	
	/**copy constructor */
	Queue(const Queue &); 

	/**default assignment with dynamic mem. */
	Queue<TYPE, PRINTF_EXPR> & operator= (const Queue &);

	/**default destructor with dynamic mem. */
	~Queue(); 

	/**removes all objects out of the queue. */
	void queueInit(void); 

	/**add the given data into the queue. */
	void enqueue(TYPE & data); 

	/**gives the next object out of the queue. */
	TYPE dequeue(void); 

	/**checks, if the queue is empty. 
	 * return boolean */
	int queueEmpty(); 

	/**gives the count of elements waiting in the queue. */
	inline int getSize() {return this->size;}
	
	/**gives the count of elements waiting in the queue. */
	inline int elements() { return this->getSize(); }
	
	/**add the given data into the queue. see enqueue(TYPE &) */
	inline void push(TYPE & data) { this->enqueue(data); }

	/**removes all objects out of the queue. see dequeue() */
	inline TYPE pop(void) { return this->dequeue(); }

	/**prints the queue to cout. */
	QUEUE_TEMPLATE_HEADER  //ohne template-deklaration geht es nicht bei friend. 
	friend void print(Queue_T & that);
	
	/**add the given data into the queue. see enqueue(TYPE &) */
	Queue_T & operator+ (TYPE data);

	/**removes all objects out of the queue. see dequeue() */
	TYPE operator- (); 
};

#include "QueueC.h"
#endif //__QUEUE_MAX_H__ 