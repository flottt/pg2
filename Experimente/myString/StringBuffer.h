#ifndef __MY_STRING_H__ 
#define __MY_STRING_H__ 
#define NULLPTR nullptr 

class StringBuffer {
private:
	struct StringContent {
		char * text;
		struct StringContent * next;
		inline StringContent(char * iniText) : text(iniText), next(NULLPTR) {}
		StringContent(int & length, const char * text); 
		~StringContent() {
			delete[] text;
			delete next;
		}
	};

private:
	struct StringContent * first;  //not NULL
	struct StringContent * last;   //not NULL
	int size;

public:
	/** Constructor */
	StringBuffer(const char * text = "");

	/** Copy Constructor */
	StringBuffer(const StringBuffer &); 

	/** Destructor */
	~StringBuffer();

	/** Zuweisungsoperator */
	StringBuffer & operator= (const StringBuffer &);

	/** Concat */
	StringBuffer & operator+=(const char *);

	/** Concat-Alias */
	inline StringBuffer & operator << (const char * arg) { return this->operator+=(arg); }

	int operator!= (const StringBuffer &);
	inline bool operator== (const StringBuffer & that) { return !(*this != that); }
	/** Sucht die erste Unterscheidung zwischen den beiden Strings. Ist bereits das erste Zeichen unterschiedlich, wird 1 zurueckgegeben. Unterscheiden sich beide auf der Laenge des kuerzeren Strings nicht, wird 0 zurueckgegeben. */
	int operator- (const StringBuffer &);
	const char * toCharArray();

	inline StringBuffer & append(const char * arg) { return this->operator+=(arg); }

};

#endif //__MY_STRING_H__ 
