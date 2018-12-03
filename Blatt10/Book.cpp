#include "Book.h"

Book::Book() {
}

void Book::loadfromfile(std::ifstream & file) {
	AbstractArticle::loadfromfile(file);

	file.getline(this->publisher, BOOK_MAX_PUBLISHER_LENGTH); 
	this->load_checkOrFailString(this->publisher, "publisher", BOOK_MAX_PUBLISHER_LENGTH);

	file.getline(this->author, BOOK_MAX_AUTHOR_LENGTH);
	this->load_checkOrFailString(this->author, "author", BOOK_MAX_AUTHOR_LENGTH);

	if (file.fail()) {
		std::cout << "IO-ERROR: file corrupted. " << std::endl;
		std::cin >> this->author[0];
		exit(1);
	}
}

void Book::savetofile(std::ofstream & file) const {
	AbstractArticle::savetofile(file);
	file << this->publisher << std::endl;
	file << this->author << std::endl;

	if (file.fail()) {
		int i;
		std::cout << "IO-ERROR: file write error. " << std::endl;
		std::cin >> i;
		exit(1);
	}
}

void Book::input() {
	char line[64];
	std::cout << "Insert data of Book: " << std::endl; 
	AbstractArticle::input(); 
	
	while (std::cin.readsome(line, 63) > 0);
	std::cout << "Author: "; 
	std::cin.getline(this->author, BOOK_MAX_AUTHOR_LENGTH); 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a text. " << std::endl;
		std::cin.clear();
		this->author[0] = '\0';
	}
	
	while (std::cin.readsome(line, 63) > 0);
	std::cout << "Publisher: "; 
	std::cin.getline(this->author, BOOK_MAX_PUBLISHER_LENGTH); 
	if (std::cin.fail()) {
		std::cout << "IO-ERROR not a text. " << std::endl;
		std::cin.clear();
		this->publisher[0] = '\0';
	}

}

void Book::printout() const {
	std::cout << "BUCH "; 
	AbstractArticle::printout(); 
	std::cout << " from " << this->author << std::endl;
}
