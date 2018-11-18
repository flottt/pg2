#ifndef __VLTemplateOfTemplate_H__
#define __VLTemplateOfTemplate_H__
#include <cstring>
#include <iostream>
#include <ostream>

template<typename TYPE = int> 
class MengeEndlich {
private: 
	TYPE * liste; 
	const int capacity; 
	int size; 
public: 
	MengeEndlich(int capacity);
	MengeEndlich(const MengeEndlich<TYPE> &);
	~MengeEndlich(); 
	int has(TYPE & obj); 
	MengeEndlich<TYPE> & operator+(TYPE obj); 
	
	template<typename TYPE> //erneuter template-header erforderlich, muss neu erstellen!
	friend std::ostream & operator<< (std::ostream & stream, const MengeEndlich<TYPE> & content);
};

template<typename TYPE>  
MengeEndlich<TYPE>::MengeEndlich(const int capacity) : capacity(capacity), size(0) {
	this->liste = new TYPE[capacity];
}

template<typename TYPE>  
MengeEndlich<TYPE>::MengeEndlich(const MengeEndlich<TYPE> & that) : capacity(that.capacity), size(that.size) {
	this->liste = new TYPE[capacity]; 
	for (int i = 0; i < this->size; ++i) {
		this->liste[i] = that.liste[i];
	}
}


template<typename TYPE>  
MengeEndlich<TYPE>::~MengeEndlich() {
	delete[] this->liste; 
}

template<typename TYPE>
std::ostream & operator<< (std::ostream & stream, const MengeEndlich<TYPE> & that) {
	if (that.size == 0) {
		stream << "EMPTYSET ";
	} else {
		stream << '{' << that.liste[0];
		for (int i = 1; i < that.size; ++i) {
			stream << "; " << that.liste[i];
		}
		stream << '}';
	}
	return stream;
}

template<typename TYPE>
int MengeEndlich<TYPE>::has(TYPE & obj) {
	//TODO 
	return 0;
}

template<typename TYPE> 
MengeEndlich<TYPE> & MengeEndlich<TYPE>::operator+(TYPE obj) {
	if (!this->has(obj)) {
		if (this->size >= this->capacity) {
			std::cout << "Fehler: Menge voll" << std::endl; 
		}
		this->liste[this->size] = obj; 
		this->size++; 
	}
	return *this;
}


//-------------------------

template<typename TDEF = int, typename TBILD = int, template<typename> typename TTT = MengeEndlich >
class MapEndlich {
private:
	const TTT<TDEF> defmenge; 
	const TTT<TBILD> bildmenge; 

public:
	MapEndlich(const TTT<TDEF> definitionsmenge, const TTT<TBILD> bildmenge); 
	void printHead();
};

template<typename TDEF, typename TBILD, template<typename> typename TTT>
MapEndlich<TDEF, TBILD, TTT>::MapEndlich(const TTT<TDEF> definitionsmenge, const TTT<TBILD> bildmenge)
	: defmenge(definitionsmenge), bildmenge(bildmenge) {}


template<typename TDEF, typename TBILD, template<typename> typename TTT>
void MapEndlich<TDEF, TBILD, TTT>::printHead() {
	std::cout << this->defmenge << " --> " << this->bildmenge << std::endl;
}

//-------------------------

template<typename MDEF = MengeEndlich<int>, typename MBILD = MengeEndlich<int>>
class MapEndlich2 {
private:
	const MDEF defmenge; 
	const MBILD bildmenge; 

public:
	MapEndlich2(const MDEF definitionsmenge, const MBILD bildmenge); 
	void printHead();
};

template<typename MDEF, typename MBILD>
MapEndlich2<MDEF, MBILD>::MapEndlich2(const MDEF definitionsmenge, const MBILD bildmenge)
	: defmenge(definitionsmenge), bildmenge(bildmenge) {}


template<typename MDEF, typename MBILD>
void MapEndlich2<MDEF, MBILD>::printHead() {
	std::cout << this->defmenge << " --> " << this->bildmenge << std::endl;
}

//-------------------------

int vlTestTemplateTemplate_main(void);
#endif __VLTemplateOfTemplate_H__