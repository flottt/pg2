#ifndef __LLISTC83_H__ 
#include "llistc83.h"
#elif !defined __LLISTC83_CH__
#define __LLISTC83_CH__
#include <iostream>

TEMPLATE_HEADER_TCONTENT
void llistc<lcontent>::printSingleContent(lcontent & data, const int index) {
	std::cout << "Element " << index << ", Value: " << data << std::endl; 
}

TEMPLATE_HEADER_TCONTENT
void llistc<lcontent>::printout() const {
	llist_node * node = first; 
	for (int index = 0; node != NULLPTR; ++index) {
		printSingleContent(node->data, index);
		node = node->next; 
	}
}

TEMPLATE_HEADER_TCONTENT
void llistc<lcontent>::insert(int p, lcontent content) {
	llist_node * newNode = new llist_node(content);
	if (newNode == NULLPTR) {
		std::cout << "ERROR: out of memory @llistc:" << __LINE__ << std::endl;
		throw -1; 
	} else if (this->first == NULLPTR) {
		//in leerer Liste wird der Index p ignoriert. 
		this->first = this->last = newNode;
	} else if (p < 0) {
		//neues Objekt wird an das Ende gesetzt. 
		last->next = newNode; 
		last = newNode; 
	} else if (p == 0) {
		//neues Objekt wird an den Anfang gesetzt. 
		newNode->next = first;
		first = newNode;
	} else {
	  /** aktNode ist das Objekt, hinter das das neue Objekt eingefügt werden soll.  
		  * first -> ... -> aktNode -> newNode -> ... -> last */
		llist_node * aktNode = this->first; 
		//neues Objekt wird in der Mitte eingefuegt. 
		for (int i = 1; i < p && aktNode != NULLPTR; i++) {
			aktNode = aktNode->next; 
		}
		if (aktNode == NULLPTR || aktNode->next == NULLPTR) {
			//das neue Object soll ganz hinten eingefuegt werden
			last->next = newNode; 
			last = newNode; 
		} else {
			//einreihen in der Mitte ... -> aktNode -> newNode -> ...
		  newNode->next = aktNode->next; 
		  aktNode->next = newNode;
		}
	}
}

TEMPLATE_HEADER_TCONTENT
llistc<lcontent>::llist_node::~llist_node() {
  delete this->next; 
}

TEMPLATE_HEADER_TCONTENT
const lcontent * llistc<lcontent>::searchmin() const {
	if (this->first == NULLPTR) {
		//leere Liste -> Ergebnis NULL
		return NULLPTR;
	} else {
		llist_node * aktnode = first, * resultnode = first; 
		while (aktnode != NULLPTR) {
			if (aktnode->data < resultnode->data) {
				resultnode = aktnode; 
			}
			aktnode = aktnode->next; 
		} //end while
		
		return &(resultnode->data); 
	}
}

TEMPLATE_HEADER_TCONTENT 
void llistc<lcontent>::findmin() const {
	const lcontent * min = this->searchmin(); 
	if (min == NULLPTR) {
		std::cout << "Leere Liste, kein bester Student. " << std::endl; 
	} else {
		std::cout << "Bester Student: " << *min << std::endl; 
	}
}
#endif//!__LLISTC83_CH__