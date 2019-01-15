#ifndef __EMPLOYEE_ADMIN_H__ 
#define __EMPLOYEE_ADMIN_H__ 
#include <string.h>
#include <set>
#include "employee.h"

class EmployeeAdmin4 {
protected: 
	const char * companyName; 
	std::multiset<Employee> employees; 

public:
	EmployeeAdmin4(const char * firmenname = "BeispielAG");
	~EmployeeAdmin4();
	void addEmployee(Employee &); 
	bool dismissEmployee(const char *); 
	void setSalaryEmployee(const char *, int); 
	void printEmployeeList(); 
	int calculateCosts();
	int numEmployees(); 
};

#endif //__EMPLOYEE_ADMIN_H__ 