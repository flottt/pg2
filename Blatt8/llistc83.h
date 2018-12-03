#ifndef __LLISTC83_H__ 
#define __LLISTC83_H__ 
#define lcontent TContent
#define NULLPTR nullptr 
#define llistc llistc83 
#define TEMPLATE_HEADER_TCONTENT template<typename lcontent>
template<typename lcontent = float>
class llistc {
	struct llist_node {
		lcontent data; 
		llist_node * next;
		llist_node(lcontent content) : data(content), next(NULLPTR) {}
		~llist_node(); 
		
	};

private: 
	llist_node *first, *last;

protected: 
	void printSingleContent(lcontent & data, const int index);

public:
	llistc() : first(NULLPTR), last(NULLPTR) {}
	~llistc() { delete first; }
	void printout() const; 
	void insert(int p, lcontent content); 
	inline void append(lcontent content) { this->insert(-1, content); }
	const lcontent * searchmin() const; 
	void findmin() const; 
};

#include "llistc83C.h"
#endif //__LLISTC83_H__ 