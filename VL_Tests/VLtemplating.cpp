#include "VLtemplating.h"
template <> 
struct wicky<int, int> {
	wicky() {
		std::cout << " - C: int, int - " << std::endl;	}
};

template <typename BB> 
struct wicky<int, BB> {
	wicky() {	std::cout << " - B: int, BB - " << std::endl; }
};

template <typename AA, typename BB> 
struct wicky { //not accept <AA, BB> {
	wicky() {	std::cout << " - A: AA, BB - " << std::endl; }
};

template<typename AA, typename BB>
mistStack<AA, BB>::mistStack(AA a, BB b, const int size) : aaa(a), bbb(b), size(size) {
}

// PROBLEM: das geht zwar, aber es dürfen keine weiteren Templates ausserhalb dieser cpp mehr vorkommen. 


int templating_main() {
	wicky<int, int> w_II; 
	wicky<int, double> w_ID; 
	wicky<double, int> w_DI; 

	mistStack<int, int> stacko(7, 5, 3); 
	std::cout << "Stacko: " << stacko + 100 << std::endl; 

	return 0;
}