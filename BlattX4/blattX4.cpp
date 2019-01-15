#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


#include"employee.h"
#include"employeeadmin4.h"


int blatt124_main(int argc = 0, char *argv[] = nullptr)
{
	Employee e1, e2, e3, e4;
	e1.lastName = strdup("Meier");
	e1.residence = strdup("Regensburg");
	e1.salary = 1;
	e2.lastName = strdup("Mueller");
	e2.residence = strdup("Oldenburg");
	e2.salary = 2;
	e3.lastName = strdup("Niemand");
	e3.residence = strdup("Berlin");
	e3.salary = 3;
	e4.lastName = strdup("Andersen");
	e4.residence = strdup("Hamburg");
	e4.salary = 4;


	cout << "-------------------------------------------------------------------------------" << endl;
	EmployeeAdmin4 ea3;
	cout << "Print out for Set" << endl << endl;

	ea3.addEmployee(e1);
	ea3.addEmployee(e2);
	ea3.addEmployee(e3);

	ea3.printEmployeeList();
	cout << "Num of employees: " << ea3.numEmployees() << endl << endl;


	ea3.setSalaryEmployee("Meier", 4000);
	ea3.setSalaryEmployee("Mueller", 2000);
	ea3.setSalaryEmployee("Maurer", 3000);
	ea3.setSalaryEmployee("Niemand", 4000);

	ea3.printEmployeeList();
	cout << "Num of Employees: " << ea3.numEmployees() << " cause costs of: " << ea3.calculateCosts() << endl << endl;

	ea3.dismissEmployee("Mueller");
	ea3.printEmployeeList();
	cout << "Num of Employees: " << ea3.numEmployees() << " cause costs of: " << ea3.calculateCosts() << endl << endl;

	ea3.setSalaryEmployee("Niemand", 500);
	ea3.addEmployee(e4);
	ea3.setSalaryEmployee("Andersen", 5000);

	ea3.printEmployeeList();
	cout << "Num of Employees: " << ea3.numEmployees() << " cause costs of: " << ea3.calculateCosts() << endl << endl;

	return 0;
}

int main() { int returnresult = blatt124_main(); system("pause"); return returnresult; }