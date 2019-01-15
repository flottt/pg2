#include "employeeadmin.h"


EmployeeAdmin::EmployeeAdmin(const char * firmenname) {
	companyName = "abc"; //strdup(firmenname); 
	employees.reserve(20); 
}

EmployeeAdmin::~EmployeeAdmin() {
	delete[] companyName; 
}

void EmployeeAdmin::addEmployee(Employee & newEmployee) {
	if (newEmployee.chef != nullptr) {
		//TODO
	}
	employees.push_back(newEmployee); 
	newEmployee.chef = this; 
}

bool EmployeeAdmin::dismissEmployee(const char * name) {
	for (std::vector<Employee>::iterator worker = this->employees.begin(); worker != this->employees.end(); ++worker) {
		if ((*worker) == name) {
			employees.erase(worker -1); 
			return true; 
		}
	}
	return false; 
}

void EmployeeAdmin::setSalaryEmployee(const char * name, int newSalary) {
	Employee * worker = this->findByName(name); 
	if (worker == nullptr) {
		std::cout << "cannot find worker " << name << std::endl; 
	} else {
		worker->setSalary(newSalary); 
	}

}

void EmployeeAdmin::printEmployeeList() {
	std::cout << "List of Employees of " << this->companyName << std::endl;  
	for (std::vector<Employee>::const_iterator worker = this->employees.cbegin(); worker != this->employees.cend(); ++worker) {
		std::cout << *worker << std::endl; 
	}
}

int EmployeeAdmin::calculateCosts() {
	int result = 0; 
	const Employee * currentworker = nullptr; 
	for (std::vector<Employee>::const_iterator worker = this->employees.cbegin(); worker != this->employees.cend(); ++worker) {
		currentworker = &(*worker); 
		result += currentworker->getSalary(); 
	}
	return result; 
}

int EmployeeAdmin::numEmployees() {
	return employees.size();
}

Employee * EmployeeAdmin::findByName(const char * name) {
	for (std::vector<Employee>::iterator worker = this->employees.begin(); worker != this->employees.end(); ++worker) {
		if ((*worker) == name) return &(*worker); 
	}
}
