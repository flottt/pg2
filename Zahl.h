#ifndef __ZAHL_INCLUDEGUARD_H__
#define __ZAHL_INCLUDEGUARD_H__
#include <stdint.h>
class Zahl {
	uint64_t value;  //least significant block
	Zahl * high; 
private: 
	inline uint64_t * zahlInBloecke(const char * const zahl, const char tausend, int &blocks);

public:
	Zahl(int value = 0);
	Zahl(const char * zahl, const char tausend) throw (int);
	~Zahl();
	//char * to_String_dyn(); 
};

#endif // !__ZAHL_INCLUDEGUARD_H__