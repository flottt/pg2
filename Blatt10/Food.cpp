#include "Food.h"

Food::Food() {
}

void Food::input() {
	char line[64];
	std::cout << "Insert data of Food: " << std::endl;
	AbstractArticle::input();
	
	while (std::cin.readsome(line, 63) > 0);
	std::cout << "Supplier: ";
	std::cin.getline(this->supplier, ARTICLE_MAX_SUPPLIER_LENGTH);
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a text. " << std::endl;
		std::cin.clear();
		this->supplier[0] = '\0';
	}

	while (std::cin.readsome(line, 63) > 0);
	std::cout << "Storeablitity in days: ";
	std::cin >> this->storeability;
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a number. " << std::endl;
		std::cin.clear();
		this->storeability = 0;
	}
}

void Food::loadfromfile(std::ifstream & file) {
	char line[5];
	AbstractArticle::loadfromfile(file);

	file.getline(this->supplier, ARTICLE_MAX_SUPPLIER_LENGTH);
	this->load_checkOrFailString(this->supplier, "supplier", ARTICLE_MAX_SUPPLIER_LENGTH);

	file >> this->storeability; 
	file.getline(line, 4);

	if (file.fail()) {
		std::cout << "IO-ERROR: file corrupted. " << std::endl;
		std::cin >> line[0];
		exit(1);
	}
}

void Food::savetofile(std::ofstream & file) const {
	AbstractArticle::savetofile(file);
	file << this->supplier << std::endl;
	file << this->storeability << std::endl;

	if (file.fail()) {
		int i;
		std::cout << "IO-ERROR: file write error. " << std::endl;
		std::cin >> i;
		exit(1);
	}
}

void Food::printout() const {
	std::cout << "FOOD ";
	AbstractArticle::printout();
	std::cout << " from " << this->supplier << std::endl;
}
