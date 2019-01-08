#include <cstdlib>
#include <iostream>
#include<string.h>

using namespace std;


#include"employee.h"
#include"employeeadmin.h"


int blatt121_main(int argc = 0, char *argv[] = nullptr)
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

	
	cout << "Printout for vector with composition" << endl << endl;
	
	EmployeeAdmin ea;
	
	ea.addEmployee(e1);
	ea.addEmployee(e2);
	ea.addEmployee(e3);
	
	ea.printEmployeeList();
	cout << "Num of employees: " << ea.numEmployees() << endl << endl;
	ea.setSalaryEmployee("Meier", 1000);
	ea.setSalaryEmployee("Mueller", 2000);
	ea.setSalaryEmployee("Maurer", 3000);
	ea.setSalaryEmployee("Niemand", 4000);

	ea.printEmployeeList();
	cout << "Num of Employees: " << ea.numEmployees() << " cause costs of: " << ea.calculateCosts() << endl << endl;
	cout << "----"; 
	
	ea.dismissEmployee("Mueller");
	ea.printEmployeeList();
	cout << "Num of Employees: " << ea.numEmployees() << " cause costs of: " << ea.calculateCosts() << endl << endl;

	ea.setSalaryEmployee("Niemand", 500);
	ea.addEmployee(e4);
	ea.setSalaryEmployee("Andersen", 5000);

	ea.printEmployeeList();
	cout << "Num of Employees: " << ea.numEmployees() << " cause costs of: " << ea.calculateCosts() << endl << endl;
	
	return 0;
}
