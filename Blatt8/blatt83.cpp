#include "llistc83.h"
#include "student.h"

int blatt_83_main() {

	student s1("Bob", 2.3);
	student s2("Jane", 1.7);
	student s3("Mary", 3.0);

	llistc<student> list;

	/*
	list.insert(0, s1);
	list.insert(1, s2);
	list.insert(2, s3);
	*/

	/*
	list.append(s1);
	list.append(s2);
	list.append(s3);
	*/

	list.insert(0, s1);
	list.append(s2);
	list.insert(2, s3);

	list.findmin();

	return 0;
}