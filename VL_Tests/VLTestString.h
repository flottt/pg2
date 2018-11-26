#pragma once
int testStringMain();

class VLTestString {
private: 
	static int wert;
protected:
	int plusplus; 
public:
	int iii;
	//VLTestString();
	VLTestString(int x = 7);
	~VLTestString();
	friend VLTestString & operator+(VLTestString & s1, VLTestString & s2);
	friend VLTestString & operator+=(VLTestString & s1, VLTestString & s2);
	VLTestString & operator++(); 
	VLTestString & operator++(int); 
	inline int get();
};
