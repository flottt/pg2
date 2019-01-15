#include "employee.h"



Employee::Employee() : lastName(nullptr), residence(nullptr), salary(0), chef(nullptr) {
}

Employee::~Employee() {
	free(this->lastName); 
	free(this->residence); 
	this->lastName = nullptr; 
	this->residence = nullptr; 
	this->salary = 0; 
}

bool Employee::operator<(const Employee & that) {
	register char * c1 = this->lastName, * c2 = that.lastName; 
	if (c1 == nullptr) {
		return false; 
	} else if (c2 == nullptr) {
		return true; 
	}
	while (1) {
		if (*c1 == *c2) {
			if (*c1 == '\0') {
				return false;
			}
		} else {
			return (*c1 < *c2); 
		}
		++c1; 
		++c2; 
	}
}

bool Employee::operator==(const char * name) {
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

std::ostream & operator<<(std::ostream & stream, const Employee & that) {
	stream << that.lastName << " [from " << that.residence << ", $$ " << that.salary << "]";
	return stream; 
}
