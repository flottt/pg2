#include <iostream>
#include <vector>

int stl_vector(); 

int stl_main() {
	return stl_vector();
} 

int stl_vector() {
	std::vector<int> liste(10); 
	std::cout << "ini-size = " << liste.size() << ", ini-capa = " << liste.capacity() << std::endl; 
	liste.reserve(35); 
	liste.reserve(20);
	std::cout << "ini-size = " << liste.size() << ", ini-capa = " << liste.capacity() << std::endl;
	liste.resize(4, 0); 

	int val = 0; 
	liste[0] = 7; 
	liste[1] = 8; 
	liste[2] = 9; 
	
	std::cout << "inverse Vector: "; 
	for (std::vector<int>::const_reverse_iterator zahl = liste.rbegin(); zahl != liste.rend(); ++zahl) {
		std::cout << *zahl << ", "; 

	}
	std::cout << ". " << std::endl;

	std::cout << "Vector: " << std::endl;
	for (std::vector<int>::const_iterator zahl = liste.begin(); zahl != liste.end(); ++zahl) {
		for (std::vector<int>::iterator zahlY = liste.begin(); zahlY != liste.end(); ++zahlY) {
			*zahlY += 10;
			std::cout << "(" << *zahl << ", " << *zahlY << ") - ";
		}
		std::cout << std::endl;
		if (*zahl % 3 == 0) {
			if (val == 0) {
				val = 10; 
				
			}
			val++; 
			liste.push_back(val); 
		}
	}
	std::cout << "." << std::endl; 
	std::cout << "sizeof vector = " << sizeof(liste) << std::endl;  

	for (int i = 0; i < sizeof(liste); i++) {
		printf("%02hhx ", *(i + (char *)&liste));
	}
	// ?? - start - sizeend - capaend 


	return 0; 
}