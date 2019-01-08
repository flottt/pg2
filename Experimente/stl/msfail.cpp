#include <iostream>
#include <vector>

class INTY {
	class SCOUNT {
	private: 
		static int zaehler; 
		int id; 
	public:
		SCOUNT() : id(zaehler++) { std::cout << "<ID [@" << static_cast<void*>(this) << "] " << this->id << ">"; }
		SCOUNT(const SCOUNT &) : id(zaehler++) { std::cout << "<IC [@" << static_cast<void*>(this) << "] " << this->id << ">"; }
		SCOUNT & operator=(const SCOUNT & that) { std::cout << "< == >"; return *this; }
		~SCOUNT() { std::cout << "<~~ID [@" << static_cast<void*>(this) << "] " << this->id << ">" << std::endl; }
	};
private: 
	SCOUNT index; 
	int wert; 
public: 
	INTY(int value = 0) : wert(value) { std::cout << "Erstelle INT [@" << static_cast<void*>(this) << "]" << value << std::endl; }
	INTY(const INTY & that) : wert(that.wert) { std::cout << "Clone INT [@" << static_cast<void*>(this) << "]" << this->wert << std::endl; }
	~INTY() { this->wert++; std::cout << "DELETE INT [@" << static_cast<void*>(this) << "]" << this->wert << std::endl; }
	bool operator< (const INTY & that) {
		return (this->wert < that.wert); 
	}
	INTY & operator+= (int i) { this->wert += i; return *this;  }
	friend std::ostream & operator<< (std::ostream & stream, const INTY & that); 
};
int INTY::SCOUNT::zaehler = 0;

std::ostream & operator<<(std::ostream & stream, const INTY & that) {
	stream << that.wert << " "; 
	return stream; 
}


int msfail_start_main() {
	std::vector<INTY> vec; 
	vec.reserve(20); 
	INTY a(10), b(20), c(30), d(40), e(50); 
	vec.push_back(a); 
	vec.push_back(b); 
	vec.push_back(c); 
	vec.push_back(d); 
	vec.push_back(e); 

	std::vector<INTY>::iterator it = vec.begin(); 
	std::cout << "1 >> " << *it << std::endl;
	(*it) += 2; 
	it++; 
	std::cout << "2 >> " << *it << std::endl;
	(*it) += 2;
	vec.erase(it); 
	
	std::cout << "------" << std::endl;
	it = vec.begin(); 
	std::cout << "1 >> " << *it << std::endl;
	it++; 
	std::cout << "2 >> " << *it << std::endl;
	it++; 
	std::cout << "3 >> " << *it << std::endl;
	it++; 
	std::cout << "4 >> " << *it << std::endl;
	it++; 
	if (it == vec.end()) {
  	std::cout << "-- END --" << std::endl;
	}
  std::cout << "---------" << std::endl;



	return 0; 
}

int msfail_main() {
	int result = msfail_start_main();
	std::cout << " - ENDE - " << std::endl; 
	char text[50]; 
	std::cin >> text; 

	return result;
}