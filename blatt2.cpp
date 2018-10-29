#include <stdlib.h>
#include <time.h>
#include "blatt2.h"

void showme(float daten[Blatt2_D1][Blatt2_D2]) {
	int i, j;
	printf("\n Tabelle:  | ");
	for (j = 0; j < Blatt2_D2; ++j) {
		printf("[%7i] | ", j);
	}
	printf("\n");
	for (j = 0; j <= Blatt2_D2; ++j) {
		printf("-----------+");
	}

	printf("\n");
	for (i = 0; i < Blatt2_D1; ++i) {
		printf(" [%7i] | ", i);
		for (j = 0; j < Blatt2_D2; ++j) {
			printf("%9.2f | ", daten[i][j]);
		}
		printf("\n");
	}
}

void statistics(float daten[Blatt2_D1][Blatt2_D2]) {
	printf("\n Statistik: \n");
	const int TEILBEREICHE = 20; 
	const int MIN_VALUE = -100; 
	const int MAX_VALUE = 100; 
	int anzahl[TEILBEREICHE]; 
	const int SIZE = MAX_VALUE - MIN_VALUE;

	int i, j, gruppe, limitsMin, limitsMax; 
	float value; 

	for (i = 0; i < TEILBEREICHE; ++i) {
		anzahl[i] = 0;
	}

	for (i = 0; i < Blatt2_D1; ++i) {
		for (j = 0; j < Blatt2_D2; ++j) {
			value = (daten[i][j]); 
			gruppe = (int)(TEILBEREICHE * (value - MIN_VALUE) / SIZE);
			if (gruppe >= TEILBEREICHE) gruppe = TEILBEREICHE - 1;
			++anzahl[gruppe];
		}
	}

	for (gruppe = 0; gruppe < TEILBEREICHE; ++gruppe) {
		limitsMin = gruppe * SIZE / TEILBEREICHE + MIN_VALUE; 
		limitsMax = (gruppe + 1) * SIZE / TEILBEREICHE + MIN_VALUE;
		printf(" Im Bereich von %4i bis %4i liegen %2i Zahlen. ", limitsMin, limitsMax, anzahl[gruppe]); 
		for (i = anzahl[gruppe]; i > 0; --i) printf("*");
		printf("\n");
	}
}

int speichern(FILE * file, float daten[Blatt2_D1][Blatt2_D2]) {
	int i, j; 
	if (file == NULL) return ERR_IO_OPEN_EXCEPTION; 

	fprintf(file, "Array-Werte;%ix%i;\n", Blatt2_D1, Blatt2_D2);
	for (i = 0; i < Blatt2_D1; ++i) {
		for (j = 0; j < Blatt2_D2; ++j) {
			fprintf(file, "%f;", daten[i][j]);
		}
		fprintf(file, "\n");
	}

	return 0;
}

int laden(FILE * file, float daten[Blatt2_D1][Blatt2_D2]) {
	int i, j, ok;
	if (file == NULL) return ERR_IO_OPEN_EXCEPTION;


	ok = fscanf(file, "Array-Werte;%ix%i;\n", &i, &j); 
	if (ok <= 1) return ERR_IO_READ_EXCEPTION; 
	for (i = 0; i < Blatt2_D1; ++i) {
		for (j = 0; j < Blatt2_D2; ++j) {
			ok = fscanf(file, "%f;", &daten[i][j]);
			if (ok <= 0) return ERR_IO_READ_EXCEPTION;
		}
		ok = fscanf(file, "\n");
		if (ok < 0) return ERR_IO_READ_EXCEPTION;
	}

	return 0;
}

void assign(float daten[Blatt2_D1][Blatt2_D2]) {
	const float MIN_VALUE = -100.0;
	const float MAX_VALUE =  100.0;

	int i, j; 
	register long double z; 

	for (i = 0; i < Blatt2_D1; ++i) {
		for (j = 0; j < Blatt2_D2; ++j) {
			z = rand();     //integer Zufallszahl zwischen 0 und RAND_MAX
			z /= RAND_MAX;  //z liegt jetzt zwischen 0 und 1
			z *= (MAX_VALUE - MIN_VALUE); //z liegt jetzt zwischen 0 und SIZE  
			z += MIN_VALUE; //z liegt jetzt zwischen MIN_VALUE und MAX_VALUE

			daten[i][j] = (float)z;
		}
	}
}

int blatt_2_main()
{
	float g[Blatt2_D1][Blatt2_D2] = {
		-56.652035, -46.848888, -65.849617, 97.900391, 67.446869, -47.053074, 42.627151, 32.321533,
		-41.666157, -11.179771, -81.368958, 47.473312,
		-79.774918, -58.122986, 32.914032, -9.763908, -7.233795, -27.749191, 18.817032, -40.123260,
		-72.374924, -55.387932, -24.635025, -10.026901,
		-33.030823, -44.564377, 34.718781, 62.939911, -39.625813, 97.126236, -75.723694, 3.722153,
		-49.722660, -41.573311, 1.622543, -82.275787,
		11.373611, -55.750301, 50.045746, 69.707458, 33.069916, 68.676788, 17.180779, 53.294998,
		-89.446198, -49.905193, -56.468899, 3.320015,
		22.345612, 62.348145, 63.196747, 49.970688, -93.039795, -61.438267, -60.056217, -26.070618,
		-6.002655, 74.662567, -63.130699, 54.371536,
		71.788788, -38.854389, -41.906311, -77.933868, 19.572296, 59.716232, -60.209648,-69.054085,
		-96.034065, 89.836105, -99.346626, 37.035858,
		58.512894, 17.834152, -9.669128, 69.066696, 67.928955, 33.861969, -27.613281, -9.725426,
		-3.789886, -64.416519, -59.754745, 3.170326,
		-25.854790, -19.810959, 77.099701, 68.142563,-45.148396, -86.030998, 22.514091, -73.359604,
		-24.885391, 80.607788, -51.293468, 94.686920,
		40.324020,-11.503120, -74.367180, 44.289963, -21.667015, -73.713799, -18.674179, -63.154118,
		44.120346, 71.656693, -94.087418, 12.049309,
		5.518661, -21.700699, -97.676125, -98.271225, -97.676125, -98.271225, 13.882782, -57.430870,
		4.899094, 88.027985, 22.758171, -18.001205
	};
	float h[Blatt2_D1][Blatt2_D2]; 
	const char FILENAME[] = "array.csv"; 

	//addon exercise 5
	if (Blatt2_MIT_ADDON) {
		srand(time(NULL));
		assign(g);
	}
	//end addon exercise 5

	showme(g);
	//end exercise 1

	statistics(g); 
	//end exercise 2

	FILE *fp; 
	fp = fopen(FILENAME, "w"); 
	int errorcode = speichern(fp, g);
	if (errorcode != 0) {
		printf("\n----------------------\nProblem: \nIO-Fehler beim speichern. \n");
		fclose(fp); 
		return -1;
	}	else {
		fclose(fp);
	}
	//end exercise 3

	fp = fopen(FILENAME, "r");
	errorcode = laden(fp, h); 
	if (errorcode != 0) {
		printf("\n----------------------\nProblem: \nIO-Fehler beim laden. \n");
		fclose(fp); 
		return -1;
	}	else {
		fclose(fp); 
	}
	showme(h);
	//end exercise 4

	return 0;
}
