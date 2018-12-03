#include "AbstractArticle.h"

AbstractArticle::AbstractArticle() : next(nullptr) {
}

AbstractArticle::AbstractArticle(const char * descr, const int id) : id(id), next(nullptr) {
	for (int i = 0; i < ARTICLE_MAX_DESCRIPTION_LENGTH; ++i) {
		this->descr[i] = descr[i];
		if (descr[i] == '\0') break;
	}
	this->descr[ARTICLE_MAX_DESCRIPTION_LENGTH] = '\0';
}

AbstractArticle::AbstractArticle(const AbstractArticle & that) : id(that.id), stock(that.stock), minstock(that.minstock), price(that.price) {
	for (int i = 0; i < ARTICLE_MAX_DESCRIPTION_LENGTH; i++) {
		this->descr[i] = that.descr[i]; 
		if (this->descr[i] == '\0') break; 
	}
	this->descr[ARTICLE_MAX_DESCRIPTION_LENGTH] = '\0';
}

AbstractArticle::~AbstractArticle() {}

void AbstractArticle::load_checkOrFailString(char * text, const char * propertyname, const int TEXT_CAPACITY) {
	if (*text == '*') {
		std::cout << "IO-ERROR: missing " << propertyname << " of book #" << this->id << std::endl;
		exit(1);
	}
	text[TEXT_CAPACITY] = '\0'; 
}

void AbstractArticle::input() {
	char line[64]; 
	while(std::cin.readsome(line, 63) > 0);
	std::cout << "Beschreibung eingeben: "; 
	std::cin.getline(this->descr, ARTICLE_MAX_DESCRIPTION_LENGTH); 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a text. " << std::endl;
		std::cin.clear();
		this->descr[0] = '\0';
	}

	while(std::cin.readsome(line, 63) > 0);
	std::cout << "ID: "; 
	std::cin >> this->id; 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a number. " << std::endl; 
		std::cin.clear();
		this->id = 0; 
	}

	while(std::cin.readsome(line, 63) > 0);
	std::cout << "Vorratsmenge eingeben: "; 
	std::cin >> this->stock; 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a number. " << std::endl;
		std::cin.clear();
		this->stock = 0;
	}

	while(std::cin.readsome(line, 63) > 0);
	std::cout << "Mindest-Vorratsmenge eingeben: "; 
	std::cin >> this->minstock; 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a number. " << std::endl;
		std::cin.clear();
		this->minstock = 0;
	}

	while(std::cin.readsome(line, 63) > 0);
	std::cout << "Einzelpreis eingeben: "; 
	std::cin >> this->price; 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a number. " << std::endl;
		std::cin.clear();
		this->price = 0;
	}

}

void AbstractArticle::printout() const {
	std::cout << this->descr << " [" << this->id << "] x" << this->stock;
}

void AbstractArticle::savetofile(std::ofstream & file) const {
	file << this->descr << std::endl; 
	file << this->id << std::endl; 
	file << this->stock << std::endl; 
	file << this->minstock << std::endl; 
	file << this->price << std::endl; 
	if (file.fail()) {
		int i; 
		std::cout << "IO-ERROR: write not possible. " << std::endl; 
		std::cin >> i; 
		exit(1);
	}
}
void AbstractArticle::loadfromfile(std::ifstream & file) {
	char line[5]; 
	file.getline(this->descr, ARTICLE_MAX_DESCRIPTION_LENGTH);
	this->load_checkOrFailString(this->descr, "description", ARTICLE_MAX_DESCRIPTION_LENGTH); 
	file >> this->id;
	file >> this->stock;
	file >> this->minstock;
	file >> this->price;
	file.getline(line, 4);
	if (file.fail()) {
		std::cout << "IO-ERROR: file corrupted. " << std::endl; 
		std::cin >> line[0]; 
		exit(1);
	}
}


int AbstractArticle::addstock(int anzahl) {
	return 0;
}

int AbstractArticle::removestock(int anzahl) {
	return 0;
}
