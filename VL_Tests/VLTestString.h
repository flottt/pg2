#pragma once
int testStringMain();

class VLTestString {
private: 
	static int wert;
public:
	int iii;
	//VLTestString();
	VLTestString(int x = 7);
	~VLTestString();
	friend VLTestString & operator+(VLTestString & s1, VLTestString & s2);
	friend VLTestString & operator+=(VLTestString & s1, VLTestString & s2);
	inline int get();
};
