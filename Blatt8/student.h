#ifndef __student_h__ 
#define __student_h__ 
#include <string>
#include <ostream>

class student {
private: 
	std::string name; 
	float grade; 
public: 
	student(); 
	student(std::string name, float grade); 
	student(const student & that); 

	bool operator< (const student & that) const; 
	inline std::string getName() const { return this->name; }
	inline float getGrade() const { return this->grade; }
	friend std::ostream & operator<< (std::ostream &, const student &);
	void print() const;
};

#endif //__student_h__ 
