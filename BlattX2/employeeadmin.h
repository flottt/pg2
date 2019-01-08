#ifndef __EMPLOYEE_ADMIN_H__ 
#define __EMPLOYEE_ADMIN_H__ 
#include <string.h>
#include <vector>
#include "employee.h"

class EmployeeAdmin {
protected: 
	const char * companyName; 
	std::vector<Employee> employees; 

public:
	EmployeeAdmin(const char * firmenname = "BeispielAG");
	~EmployeeAdmin();
	void addEmployee(Employee &); 
	bool dismissEmployee(const char *); 
	void setSalaryEmployee(const char *, int); 
	void printEmployeeList(); 
	int calculateCosts();
	int numEmployees(); 
	Employee * findByName(const char *); 
};

#endif //__EMPLOYEE_ADMIN_H__ 