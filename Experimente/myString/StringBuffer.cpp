#include "StringBuffer.h"

/** Konstruktor inneres Struct StringContent */ 
StringBuffer::StringContent::StringContent(int & length, const char * text) : next(NULLPTR) {
	const char * ende = text;
	for (; *ende != '\0'; ++ende);
	length = ende - text;

	char * data = new char[length + 1];
	for (char * anfang = data; text != ende; ++anfang, ++text) {
		*anfang = *text;
	}
	data[length] = '\0';
	this->text = data; 
}

/** Haupt-Konstruktor StringBuffer */
StringBuffer::StringBuffer(const char * text) {
	this->first = new StringContent(this->size, text); 
	this->last = this->first; 
}
/** Copy-Konstruktor StringBuffer */
StringBuffer::StringBuffer(const StringBuffer & that) : StringBuffer(((StringBuffer &)that).toCharArray()){}

/** Destruktor StringBuffer */
StringBuffer::~StringBuffer() {
	delete first;
	this->first = NULLPTR;
	this->last = NULLPTR;
}

/** Zuweisungsoperator */
StringBuffer & StringBuffer::operator=(const StringBuffer & that) {
	delete this->first; 
	int length = 0; 
	this->last = this->first = new StringContent(length, ((StringBuffer &)that).toCharArray());
  this->size = that.size;
	return *this;
}

StringBuffer & StringBuffer::operator+=(const char * text) {
	int length = 0; 
	this->last->next = new StringContent(length, text);
	this->last = this->last->next; 
	this->size += length; 
	return *this; 
}


int StringBuffer::operator-(const StringBuffer & that) {
	StringContent * thisContent = this->first,
		            * thatContent = that.first; 
	const char * thisCursor = thisContent->text,
		            * thatCursor = thatContent->text; 

	int result = 1; 
	while(1) {
		while (*thisCursor == '\0') {
			thisContent = thisContent->next; 
			if (thisContent == NULLPTR) return 0; 
			thisCursor = thisContent->text; 
		}
		while (*thatCursor == '\0') {
			thatContent = thatContent->next; 
			if (thatContent == NULLPTR) return 0; 
			thatCursor = thatContent->text; 
		}
		if (*thisCursor != *thatCursor) return result;

		++result; 
		++thisCursor; 
		++thatCursor; 
	}

	return 0;
}
int StringBuffer::operator!=(const StringBuffer & that) {
	if (this->size != that.size) return -1; 
	return *this - that; 
}

const char * StringBuffer::toCharArray() {
	if (this->first != this->last) {
		char * neuesArray = new char[this->size + 1]; 
		char * copyToCursor = neuesArray; 
		const char * copyFromCursor = NULLPTR; 
		StringContent * aktuell = this->first; 
		while (aktuell != NULLPTR) {
			copyFromCursor = aktuell->text; 
			while (*copyFromCursor != '\0') {
				*copyToCursor = *copyFromCursor; 
				copyToCursor++; 
				copyFromCursor++; 
			}
			aktuell = aktuell->next; 
		}
		neuesArray[this->size] = '\0';

		delete this->first; 
		this->last = this->first = new StringContent(neuesArray); 
	}
	return this->first->text;
}


