#include "employeeadmin4.h"


EmployeeAdmin4::EmployeeAdmin4(const char * firmenname) {
	companyName = strdup(firmenname); 
	//employees.reserve(20);  //unneccessary with set
}

EmployeeAdmin4::~EmployeeAdmin4() {
	delete[] companyName; 
}

bool earnsLess(Employee & a, Employee & b) {
	return a.salary < b.salary; 
}

void EmployeeAdmin4::addEmployee(Employee & newEmployee) {
	employees.insert(newEmployee); 
}

bool EmployeeAdmin4::dismissEmployee(const char * name) {
	for (std::set<Employee>::iterator worker = this->employees.begin(); worker != this->employees.end(); ++worker) {
		if ((*worker) == name) {
			employees.erase(worker); 
			return true; 
		}
	}
	return false; 
}

void EmployeeAdmin4::setSalaryEmployee(const char * name, int newSalary) {
	for (std::set<Employee>::iterator worker = this->employees.begin(); worker != this->employees.end(); ++worker) {
		if ((*worker) == name) {
			Employee newWorker(*worker); 
			newWorker.setSalary(newSalary); 
			this->employees.erase(worker); 
			this->employees.insert(newWorker); 
			return;
		}
	}
	std::cout << this->companyName << " hat keinen Mitarbeiter, der " << name << " heisst. " << std::endl; 
}

void EmployeeAdmin4::printEmployeeList() {
	std::cout << "List of Employees of " << this->companyName << std::endl;  
	for (std::set<Employee>::const_iterator worker = this->employees.cbegin(); worker != this->employees.cend(); ++worker) {
		std::cout << *worker << std::endl; 
	}
}

int EmployeeAdmin4::calculateCosts() {
	int result = 0; 
	const Employee * currentworker = nullptr; 
	for (std::set<Employee>::const_iterator worker = this->employees.cbegin(); worker != this->employees.cend(); ++worker) {
		currentworker = &(*worker); 
		result += currentworker->getSalary(); 
	}
	return result; 
}

int EmployeeAdmin4::numEmployees() {
	return employees.size();
}


