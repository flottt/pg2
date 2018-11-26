#ifndef __THREAD_A_H__ 
#define __THREAD_A_H__ 
#include <thread>
#include <stdio.h>
class ThreadA {
private: 
	int zahl[3]; 
	int aktiv; 
	static ThreadA * reflexiv; 
	inline bool isActive(const int i);

public: 
	ThreadA() : aktiv(0), zahl{ 0, 0, 0 } {}
	void starten(); 
	void exec(const int); 
	static ThreadA * getInstance(); 
	void print();

};

#endif __THREAD_A_H__ 