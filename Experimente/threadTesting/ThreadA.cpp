#include "ThreadA.h"
#include <chrono>
ThreadA * ThreadA::reflexiv = nullptr; 


void exec0(const int i) {
	ThreadA * that = ThreadA::getInstance();
	that->exec(i);
}

void ThreadA::starten() {
	this->aktiv |= 7;
	std::thread t0(&exec0, 0); 
	std::thread t1(&exec0, 1); 
	std::thread t2(&exec0, 2); 
	
	int k = -1; 
	scanf("%i", &k);
	
	aktiv &= ~3;
	printf("%i", k);
	t0.join(); 
	t1.join(); 
	t2.join();
}

inline bool ThreadA::isActive(const int i) {
	return (1 << i) & this->aktiv;
}

void ThreadA::exec(const int i) {
	for (this->zahl[i] = 0; this->zahl[i] < 250123 && this->isActive(i); this->zahl[i]++) {
		this->print(); 
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

ThreadA * ThreadA::getInstance() {
	if (reflexiv == nullptr) {
		reflexiv = new ThreadA(); 
	}
	return reflexiv;
}

void ThreadA::print() {
	printf("%6i  -  %6i  -  %6i\n", zahl[0], zahl[1], zahl[2]); 
}

int threadTest_main() {
	ThreadA::getInstance()->starten();
	return 0; 
}