#include "Zahl.h"


Zahl::Zahl(int value) {
	this->value = value; 
	this->high = nullptr;
}

Zahl::Zahl(const char * zahl, const char tausend = '.') {
	const uint64_t funf = 50000000000000000;
	int blocks = 0; 
	uint64_t * werte = Zahl::zahlInBloecke(zahl, tausend, blocks); 
	//TODO: if (werte != 0) throw zahlInBloecke;

	uint64_t * hex = new uint64_t[blocks];
	if (hex == nullptr) {
		delete[] werte;
		throw -1;
	}
	this->value = hex[0];
	if (blocks > 1) {
		Zahl * last = this;
		for (int i = 1; i < blocks; ++i) {
			Zahl * xxx = new Zahl(0); 
			xxx->value = hex[i];
			xxx->high = nullptr;
			last->high = xxx;
		}
	}	else {
		this->high = nullptr; 
	}


	delete[] hex; 
	delete[] werte; 
}

inline uint64_t * bloeckeLesen(uint64_t * werte, int &blocks) {
	for (; blocks > 0 && werte[blocks] != 0; --blocks);

	uint64_t * result = new uint64_t[blocks];
	int block = 0, part = 0, i;

	uint64_t resX, mask16 = 0xFFFF, mask = 10000000000000000 >> 16; // = 10^16 / 2^16

	for (block = 0; block < blocks; ++block) {
		for (part = 0; part < 64; part += 16) {
			resX = (werte[0] & mask16) << part;
			result[block] |= resX;

			werte[0] >>= 16;
			for (i = 1; i < blocks; ++i) {
				werte[i - 1] += mask * (werte[i] & mask16);
				werte[i] >>= 16;
			}
		}
	}

	for (; blocks > 0 && result[blocks] != 0; --blocks);

	return result; 
}

//2^64-1 = 18.446.744.073.709.551.615 (1 und 19 weitere Ziffern)
inline uint64_t * Zahl::zahlInBloecke(const char * const zahl, const char tausend, int &blocks) {
	int pos = 0, i, j;
	char cc = 0;
	const char * ziffer = zahl;

	//bestimme Länge des Strings
	while (*ziffer != '\0') {
		++ziffer;
		++pos;
	}
	--ziffer;
	--pos;
	
	blocks = pos / 16 + 1;

	uint64_t * werte = new uint64_t[blocks];
	
	if (werte == nullptr) return nullptr;
	for (i = 0; i < blocks; ++i) {
		werte[i] = 0;
	}

	for (i = 0; i < blocks; ++i) {
		for (j = 0; j < 16; ++j) {
			do {
				if (ziffer < zahl) return werte; 
				cc = *ziffer;
				--ziffer;
				
			} while (cc == tausend);
			if (cc < '0' || cc > '9') {
				delete[] werte;
				return nullptr;
			}
			werte[i] *= 10;
			werte[i] += cc - '0';
		}
	}
}

Zahl::~Zahl() {
	delete this->high; 
	this->value = 0; 
}
