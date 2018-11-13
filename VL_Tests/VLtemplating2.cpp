#include "VLtemplating.h"
/*
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


int templating_main2() {
	wicky<int, int> w_II; 
	wicky<int, double> w_ID; 
	wicky<double, int> w_DI; 

	return 0;
}
*/

int spam() {
	mistStack<int, int> st(1,2,3);
	return 0;
}
