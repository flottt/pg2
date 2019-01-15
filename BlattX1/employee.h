#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream> 
#include <vector>

class Employee {
protected:
	friend class EmployeeAdmin; 
	EmployeeAdmin * chef; 
	void setSalary(int newSalary) { this->salary = newSalary; }
	int getSalary() const { return this->salary; }

public: //public access neccessary according to main
	char * lastName; 
	char * residence; 
	int salary; 

public:
	Employee();
	~Employee();
	friend std::ostream & operator<< (std::ostream &, const Employee &); 
	bool operator< (const Employee &); 
	const char * getLastName() const { return lastName; }
	bool operator== (const char *); 

};

#endif //__EMPLOYEE_H__