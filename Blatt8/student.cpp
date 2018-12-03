#include "student.h"
#include <iostream>

student::student() : name(""), grade(0.0) {}
student::student(std::string name, float grade) : name(name), grade(grade) {}
student::student(const student & that) : name(that.name), grade(that.grade) {}

bool student::operator< (const student & that) const { return this->grade < that.grade; }

std::ostream & operator<<(std::ostream & stream, const student & that) {
	stream << that.name << "(" << that.grade << ")";
	return stream;
}

void student::print() const {
	std::cout << *this << std::endl;
}
