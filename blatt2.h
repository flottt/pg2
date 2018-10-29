#ifndef __BLATT_2_H__
#define __BLATT_2_H__
#include <stdio.h>
#define Blatt2_MIT_ADDON 0
#define Blatt2_D1 10
#define Blatt2_D2 12
#define ERR_IO_OPEN_EXCEPTION  -801
#define ERR_IO_WRITE_EXCEPTION -802
#define ERR_IO_READ_EXCEPTION  -803
int blatt_2_main();
void showme(float[Blatt2_D1][Blatt2_D2]);
void statistics(float daten[Blatt2_D1][Blatt2_D2]);
int speichern(FILE * file, float daten[Blatt2_D1][Blatt2_D2]); 
int laden(FILE * file, float daten[Blatt2_D1][Blatt2_D2]); 

#endif // !__BLATT_2_H__