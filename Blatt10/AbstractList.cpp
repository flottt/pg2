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

void AbstractList::printAskId() const {
	int id = -1; 
	std::cout << "Which id are you looking for: ";
	char line[64];
	while (std::cin.readsome(line, 63) > 0); 
	std::cin >> id; 
	if (std::cin.fail()) {
		std::cin.clear(); 
		std::cout << "Error: could not read id" << std::endl; 
		return;
	}

	AbstractArticle * article = this->searchid(id); 
	if (article == nullptr) {
		std::cout << "Error: There is no Article with id " << id << std::endl; 
	} else {
		article->printout();
	}
}

AbstractArticle * AbstractList::searchid(const int id) const {
	AbstractArticle * article = first; 
	while (article != nullptr) {
		if (article->id == id) return article; 
		article = article->next; 
	}
	return nullptr; 
}

AbstractArticle * AbstractList::searchdescr(const char * descr) const {
	register char cc1, cc2; 
	AbstractArticle * article = first;
	while (article != nullptr) {
		for(int i = 0; 1; ++i) {
			cc1 = descr[i]; 
			cc2 = article->descr[i]; 
			if (cc1 == '\0' && cc2 == '\0') {
				return article;
			} else if (cc1 != cc2) {
				//this includes the case, that one string terminates and the other continues. 
				break;
			}
		}
		article = article->next;
	}
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

/* Destruktor ueber Iteration. */
AbstractList::~AbstractList() {
	this->removeAll();
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
	AbstractArticle * article = nullptr, * next = this->first;
	
	while (next != nullptr) {
		article = next; 
		next = next->next;
		delete article;
	}
	first = nullptr; 
}

