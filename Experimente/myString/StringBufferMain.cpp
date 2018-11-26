#include<stdio.h>
#include "StringBuffer.h"

int stringBuffer_main() {
	StringBuffer s = "Hallo";
	s += " meine ";
	s += "Maus. ";

	StringBuffer tx = s; 
	tx += "Was machst du heute? "; 
	s += "Wie geht es dir? "; 
	s << "Schoen" << ", dass" << " du da bist. ";

	tx << "Gehen wir zusammen weg? ";
	s += "ja ";

	StringBuffer zuweisung = "0"; 
	zuweisung = tx; 
	printf("1. %s\n", s.toCharArray());
	printf("2. %s\n", tx.toCharArray());
	printf("3. %s\n", zuweisung.toCharArray());
	printf("gleich: %i \n", s != tx);
	
	return 0;
}