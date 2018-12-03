#include <stdlib.h>
#include "Blatt2\\blatt2.h"
#include "Blatt3\\blatt3.h"
#include "Blatt3\\blatt35.h"
#include "Blatt5\\Cdate.h"
#include "VL_Tests\\VLTestString.h"
#include "Experimente\Zahl.h"
#include "VL_Tests\problemConstExpr.h"
#include "VL_Tests\VLtemplating.h"
#include "VL_Tests\VLTestTemplateOfTemplate.h"
#include "VL_Tests\Vererbung\ERB_MannFrau.h"
#include "VL_Tests\Vererbung\ERB_Gitarre.h"

int blatt_41_main();
int blatt_42_main();
int blatt_61_main();
int blatt_63_main();
int blatt_71_main();
int blatt_72_main();
int blatt_81_main(); 
int blatt_82_main(); 
int blatt_83_main(); 
int blatt_10_main();
int blatt_10_menu_main();
int stringBuffer_main();
int threadTest_main();
int musikEGitarre_main();

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
	printf("61: Blatt 6: Queue \n");
	printf("63: Blatt 6: Queue \n");
	printf("71: Blatt 7: Quicksort-Klasse \n");
	printf("72: Blatt 7: Quicksort-Template-Klasse \n");
	printf("81: Blatt 8: Verkettete Liste \n"); 
	printf("82: Blatt 8: Verkettete Liste mit Template \n"); 
	printf("83: Blatt 8: Verkettete Liste mit Template mit Klasse student \n"); 
	printf("10: Blatt 10: Storage-Verwaltung \n");
	printf("11: Blatt 10: Storage-Verwaltung mit Menue \n");
	printf("91: Teststring \n"); 
	printf("92: Problem mit CONSTEXPR \n"); 
	printf("93: Test-Templating \n"); 
	printf("94: Template-Template \n");
	printf("95: Vererbung Mensch \n");
	printf("96: Vererbung Musik \n");
	printf("97: StringBufferTest \n"); 
	printf("98: ThreadTest \n"); 
	printf("99: Vererbung Musik E-Gitarre \n"); 
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
	case 61: returnresult = blatt_61_main(); break; 
	case 63: returnresult = blatt_63_main(); break; 
	case 71: returnresult = blatt_71_main(); break; 
	case 72: returnresult = blatt_72_main(); break; 
	case 81: returnresult = blatt_81_main(); break; 
	case 82: returnresult = blatt_82_main(); break; 
	case 83: returnresult = blatt_83_main(); break; 
	case 10: returnresult = blatt_10_main(); break; 
	case 11: returnresult = blatt_10_menu_main(); break; 
	case 91: returnresult = testStringMain(); break; 
	case 92: returnresult = problemConstExpr(); break; 
	case 93: returnresult = templating_main(); break; 
	case 94: returnresult = vlTestTemplateTemplate_main(); break;
	case 95: returnresult = vlVererbung_main(); break; 
	case 96: returnresult = musik_main(); break; 
	case 97: returnresult = stringBuffer_main(); break; 
	case 98: returnresult = threadTest_main(); break; 
	case 99: returnresult = musikEGitarre_main(); break;
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