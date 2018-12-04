#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "FoodList.h"
#include "BookList.h"
#include "MaterialList.h"
#define List AbstractList
using namespace std;

//TODO

int blatt_10_main()
{
  FoodList Listf;
  BookList Listb;
  MaterialList Listm;
	List * plist = nullptr; 

  cout<<"---food test---\n";
  
  Listf.loadfromfile("Blatt10\\food.txt");
  Listf.printout(); 
  plist=&Listf;
  plist->printout();
  plist->savetofile("foodtest.txt");
  
  cout<<"---book test---\n";
  Listb.loadfromfile("Blatt10\\books.txt");
  Listb.printout();
  plist=&Listb;
  plist->printout();
  
	
  cout<<"---material test---\n";
  Listm.loadfromfile("Blatt10\\materials.txt");
  Listm.printout();
  plist=&Listm;
  plist->printout();     
  
	return 0; 
}

int blatt_10_menu_main() {
	FoodList listf; 
	BookList listb; 
	MaterialList listm; 
	int eingabe; 
	char line[64]; 
	while (1) {

		std::cout << "Storage Main Menu" << std::endl;
		std::cout << "0: Exit " << std::endl; 
		std::cout << "11: Print full food list " << std::endl;
		std::cout << "12: Print full book list " << std::endl;
		std::cout << "13: Print full material list " << std::endl;
		std::cout << "21: Load food list from file " << std::endl;
		std::cout << "22: Load book list from file " << std::endl;
		std::cout << "23: Load material list from file " << std::endl;
		std::cout << "31: Save food list to file " << std::endl;
		std::cout << "32: Save book list to file " << std::endl;
		std::cout << "33: Save material list to file " << std::endl;
		std::cout << "41: Insert new food " << std::endl;
		std::cout << "42: Insert new book " << std::endl;
		std::cout << "43: Insert new material " << std::endl;
		std::cout << "51: Show food with given id " << std::endl;
		std::cout << "52: Show book with given id " << std::endl;
		std::cout << "53: Show material with given id " << std::endl;

		std::cout << "Your choice: ";
		while (std::cin.readsome(line, 63) > 0);
		eingabe = -1; 
		std::cin >> eingabe;
		std::cout << std::endl << std::endl << std::endl << std::endl;
		switch (eingabe) {
		case 0: return 0; 
		case 11: listf.printout(); break;
		case 12: listb.printout(); break;
		case 13: listm.printout(); break;
		case 21: listf.loadfromfile(); break; 
		case 22: listb.loadfromfile(); break; 
		case 23: listm.loadfromfile(); break; 
		case 31: listf.savetofile(); break; 
		case 32: listb.savetofile(); break; 
		case 33: listm.savetofile(); break; 
		case 41: listf.input(); break;
		case 42: listb.input(); break;
		case 43: listm.input(); break;
		case 51: listf.printAskId(); break; 
		case 52: listb.printAskId(); break; 
		case 53: listm.printAskId(); break; 
		default: std::cout << "Illegal command ignored." << std::endl;
		}
		std::cout << "------ " << std::endl << std::endl;
	}
}

//int main() { return blatt_10_menu_main(); }