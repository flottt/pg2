#include "employee.h"
#define DEBUG 0


Employee::Employee() : lastName(nullptr), residence(nullptr), salary(0) {
	if (DEBUG) std::cout << "creating <@" << static_cast<void*>(this) << "> ??? " << std::endl;
}

Employee::Employee(const Employee & that) : lastName(nullptr), residence(nullptr), salary(that.salary) {
	this->lastName = strdup(that.lastName); 
	this->residence = strdup(that.residence); 
	if (DEBUG) std::cout << "cloning <@" << static_cast<void*>(this) << "> " << this->lastName << std::endl; 
}

Employee::~Employee() {
	if (DEBUG) std::cout << "deleting <@" << static_cast<void*>(this) << "> " << this->lastName << std::endl; 
	free(this->lastName); 
	free(this->residence); 
	this->lastName = nullptr; 
	this->residence = nullptr; 
	this->salary = 0; 
}

bool operator<(const Employee & a, const Employee & b) {
	return a.getSalary() < b.getSalary(); 
}

bool Employee::operator==(const char * name) const {
	char * c1 = this->lastName;
	if (c1 == nullptr || name == nullptr) {
		return false; 
	} else {
		while (1) {
			if (*c1 == *name) {
				if (*c1 == '\0') return true; 
			} else {
				return false; 
			}
			++c1;
			++name; 
		}
	}
}

Employee & Employee::operator=(const Employee & that) {
	free(this->lastName); 
	free(this->residence); 
	this->lastName = strdup(that.lastName); 
	this->residence = strdup(that.residence); 
//	strcpy(this->lastName, that.lastName);
//	strcpy(this->residence, that.residence);

	this->salary = that.salary; 
	return *this;
}

std::ostream & operator<<(std::ostream & stream, const Employee & that) {
	stream << that.lastName << " [from " << that.residence << ", $$ " << that.salary << "]";
	return stream; 
}
