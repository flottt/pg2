#include <stdlib.h>
#include "blatt2.h"
#include "blatt3.h"
#include "blatt35.h"
#include "testung.h"
#include "Cdate.h"
#include "VLTestString.h" 

int blatt_41_main();
int blatt_42_main();

int main() {

	int eingabe = -1, returnresult = -1;
	printf("\nProgrammieren PG 2 Hauptmenue \n");
	printf("2: Blatt 2: Arrays auf Bildschirm ausgeben und in Datei schreiben. \n");
	printf("3: Blatt 3: Verkettete Listen. \n"); 
	printf("35: Blatt 3 Aufgabe 5: Verkettete Listen zu verketteten Listen. \n");
	printf("41: Blatt 4 Aufgabe 1: Piggybank mit Init \n");
	printf("42: Blatt 4 Aufgabe 2: Piggybank mit Construktor \n");
	printf("51: Blatt 5 Aufgabe 1: Klasse Datum anzeigen \n");
	printf("52: Blatt 5 Aufgabe 2: Klasse Datum addieren \n");
	printf("91: Teststring \n"); 
	printf("Ihre Auswahl: ");
	scanf("%i", &eingabe); 
	system("cls");
	switch (eingabe)	{
	case 2: returnresult = blatt_2_main(); break; 
	case 3: returnresult = blatt_3_main(); break; 
	case 35: returnresult = blatt_35_main(); break; 
	case 41: returnresult = blatt_41_main(); break; 
	case 42: returnresult = blatt_42_main(); break; 
	case 51: returnresult = blatt_5_a1_main(); break; 
	case 52: returnresult = blatt_5_a2_main(); break; 
	case 91: returnresult = testStringMain(); break;
	case 0: returnresult = testung(); break;
	default:
		printf("Fehler: Ungueltige Eingabe. "); 
		if (eingabe == -1) {
			printf("Eingabe konnte nicht gelesen werden. ");
		} else {
			printf("Eingabe %i kann nicht zugeordnet werden. ", eingabe);
		}
	  printf("Programm wird beendet. \n");
	}
	system("pause");
	return returnresult;
}