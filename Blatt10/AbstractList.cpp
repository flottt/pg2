#include "AbstractList.h"

AbstractList::AbstractList() : first(nullptr) {
}

void AbstractList::input() {
	AbstractArticle * newArticle = this->createEntity(); 
	newArticle->input(); 
	this->addelement(*newArticle);
}

void AbstractList::printout() {
	AbstractArticle * article = this->first; 
	while (article != nullptr) {
	  article->printout(); 
		article = article->next; 
	}
}

void AbstractList::searchid() {
}

AbstractArticle * AbstractList::searchdescr() {
	return nullptr;
}

void AbstractList::addelement(AbstractArticle & neuerArticle) {
	if (first == nullptr) {
		first = &neuerArticle; 
	} else {
		AbstractArticle * last = first; 
		while (last->next != nullptr) {
			last = last->next; 
		}
		last->next = &neuerArticle; 
	}
}

AbstractList::~AbstractList() {
	delete first; 
	first = nullptr;
}

void AbstractList::loadfromfile(const char * filename) {
	this->removeAll(); 
	if (filename == nullptr) filename = this->getDefaultFilename();
	char line[30];
	std::ifstream file(filename, std::ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			file.getline(line, 29);
			line[29] = '\0';
			if (line[0] == '*') {
				AbstractArticle * article = this->createEntity();
				article->loadfromfile(file);
				this->addelement(*article);

			} else if (line[0] == '\0') {
				continue;
			} else {
				std::cout << "IO-ERROR: File should start with ***" << std::endl;
				std::cin >> line[0];
				exit(1);
			}
		}
	  file.close();
	} else {
		std::cout << "IO-ERROR: Could not open file for reading " << filename << std::endl;
	}
}

void AbstractList::savetofile(const char * filename) {
	AbstractArticle * article = this->first;

	if (filename == nullptr) filename = this->getDefaultFilename(); 
	std::ofstream file(filename, std::ios::out); 
	if (file.is_open()) {
		while (article != nullptr) {
			file << "***" << std::endl; 
			article->savetofile(file); 
			article = article->next;
		}
		
		file.close();
	} else {
		std::cout << "IO-ERROR: Could not open file for writing " << filename << std::endl;
	}
}

void AbstractList::removeAll() {
	delete first; 
	first = nullptr; 
}

