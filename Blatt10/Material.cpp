#include "Material.h"

Material::Material() {
}

void Material::input() {
	char line[64];
	std::cout << "Insert data of Material: " << std::endl;
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
	std::cout << "weight in kg per unit: ";
	std::cin >> this->weight;
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a number. " << std::endl;
		std::cin.clear();
		this->weight = 0;
	}
}

void Material::loadfromfile(std::ifstream & file) {
	char line[5];
	AbstractArticle::loadfromfile(file);

	file.getline(this->supplier, ARTICLE_MAX_SUPPLIER_LENGTH);
	this->load_checkOrFailString(this->supplier, "supplier", ARTICLE_MAX_SUPPLIER_LENGTH);

	file >> this->weight;
	file.getline(line, 4);

	if (file.fail()) {
		std::cout << "IO-ERROR: file corrupted. " << std::endl;
		std::cin >> line[0];
		exit(1);
	}
}

void Material::savetofile(std::ofstream & file) const {
	AbstractArticle::savetofile(file); 
	file << this->supplier << std::endl; 
	file << this->weight << std::endl;

	if (file.fail()) {
		int i; 
		std::cout << "IO-ERROR: file write error. " << std::endl;
		std::cin >> i; 
		exit(1);
	}
}

void Material::printout() const {
	std::cout << "MATERIAL ";
	AbstractArticle::printout();
	std::cout << " from " << this->supplier << "(" << this->weight << " kg)" << std::endl;
}
