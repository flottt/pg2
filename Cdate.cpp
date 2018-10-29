#include "Cdate.h"
#include <iostream> 
const int Cdate::DAYS_OF_MONTH[ANZAHL_MONATE_IM_JAHR] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool Cdate::isSchaltjahr() {
	if (this->year % 4 != 0) return false;
	if (this->year % 100 != 0) return true; 
	if (this->year % 1000 != 0) return false;
	return true;
}

Cdate::Cdate() : day(1), month(1), year(1), presentingMode(CdateDarstellungsart::deutsch) {}

Cdate::Cdate(int day, int month, int year) : day(day), month(month), year(year), presentingMode(CdateDarstellungsart::deutsch) {
	this->normalisiere();
}

void Cdate::normalisiere() {
	if (this->month < 0 || this->month > 12) {
		int diff = 0; 
		diff = this->month / 12; 
		this->month = diff % 12; 
		this->year += diff; 
	}
	if (this->month == 0) {
		this->month = 12; 
		this->year--;
	}
	while (this->day <= 0) {
		this->month--; 
		if (this->month < 1) {
			this->month += 12;
			this->year--;
		}
		if (this->month == 2 && this->isSchaltjahr()) {
			this->day += 29;

		} else {
			this->day += DAYS_OF_MONTH[this->month - 1];

		}
	}

	while (this->day > DAYS_OF_MONTH[this->month - 1]) {
		if (this->month == 2 && this->isSchaltjahr()) {
			if (this->day == 29) break; 
			else {
				this->day -= 29;
			}
		} else {
			this->day -= DAYS_OF_MONTH[this->month - 1]; 
		}
		this->month++; 
		if (this->month > 12) {
			this->month -= 12; 
			this->year++;
		}
	}

	this->year = year;
	this->month = month; 
	this->day = day;
}

int Cdate::workday() {
	int m = this->month - 2, y = this->year, c; 
	if (m <= 0) { 
		m += 12; 
		--y;  
	}
	m *= 26; 
	m -= 2;
	m /= 10; 
	c = y / 100;
	y = y % 100;

	m += this->day; 
	m += y;
	m += y / 4;
	m += c / 4;
	m -= 2 * c; 
	m %= 7; 

	return m;
}

Cdate::Cdate(const Cdate & clone) : day(clone.day), month(clone.month), year(clone.year) {}

Cdate::~Cdate() {}

void Cdate::printout() {
	switch (this->presentingMode) {
	case CdateDarstellungsart::deutsch: 
		std::cout << this->day << "." << this->month << "." << this->year;
		return; 
	case CdateDarstellungsart::englisch: 
		std::cout << this->month << "-" << this->day << "-" << this->year;

	default:
		break;
	}
}

void Cdate::setPresentationMode(CdateDarstellungsart mode) {
	this->presentingMode = mode;
}

void Cdate::printoutWeekday() {
	int workday = this->workday();
	switch (this->presentingMode) {
	case CdateDarstellungsart::deutsch:
		switch (workday) {
		case 0: std::cout << "ist ein Sonntag"; break;
		case 1: std::cout << "ist ein Montag"; break;
		case 2: std::cout << "ist ein Dienstag"; break;
		case 3: std::cout << "ist ein Mittwoch"; break;
		case 4: std::cout << "ist ein Donnerstag"; break;
		case 5: std::cout << "ist ein Freitag"; break;
		case 6: std::cout << "ist ein Samstag"; break;
		default: std::cout << "gibt es nicht";
		}
		break;
	case CdateDarstellungsart::englisch:
		switch (workday) {
		case 0: std::cout << "is a sunday"; break;
		case 1: std::cout << "is a monday"; break;
		case 2: std::cout << "is a tuesday"; break;
		case 3: std::cout << "is a wednesday"; break;
		case 4: std::cout << "is a thursday"; break;
		case 5: std::cout << "is a friday"; break;
		case 6: std::cout << "is a saturday"; break;
		default: std::cout << "does not exist";
	  }
		break; 
	default: 
		std::cout << "error: no presentationtype selected. ";
	}
}

void Cdate::printoutDay() {
	int result = this->day;
	if (isSchaltjahr() && this->month >= 3) ++result;
	for (int i = 1; i < this->month; ++i) {
		result += Cdate::DAYS_OF_MONTH[i - 1];
	}

	switch (this->presentingMode) {
	case CdateDarstellungsart::deutsch :
		std::cout << "ist der " << result << " Tag des Jahres. ";
		break;
	case CdateDarstellungsart::englisch:
		std::cout << "is the " << result << " day of the year. ";
		break; 
	default:
		std::cout << "error: no presentationtype selected. ";
	}
}

void Cdate::adddays(int tage) {
	this->day += tage; 
	this->normalisiere();
}

int blatt_5_a1_main() {
	std::cout << "printout for date1\n";
	Cdate date1(1, 2, 1980); //(day,month,year)
	date1.printout();
	date1.printoutDay();
	date1.printoutWeekday();

	std::cout << "\nprintout for date2\n";
	Cdate date2(date1);
	date2.setPresentationMode(CdateDarstellungsart::deutsch);
	date2.printout();
	date2.printoutDay();
	date2.printoutWeekday();
	return 0;
}

int blatt_5_a2_main() {
	Cdate date1(1, 12, 1980); //(day,month,year)
	date1.printout();
	date1.printoutDay();
	date1.printoutWeekday();

	date1.adddays(31);
	date1.printout();
	date1.printoutDay();
	date1.printoutWeekday();
	return 0;
}