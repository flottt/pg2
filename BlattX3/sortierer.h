#include <vector>

template<typename T> 
void bubblesort(std::vector<T> & liste, bool (*isLess)(T & a, T & b)) {
	
	int size = liste.size() - 1; 
	for (int i = 0; i < size; i++) {
		int sizeRest = size - i; 
		for (int j = 0; j < sizeRest; j++) {
			if (isLess(liste[j + 1], liste[j])) {
				T swap = liste[j]; 
				liste[j] = liste[j + 1]; 
				liste[j + 1] = swap; 
			}
		}
	}
	
}