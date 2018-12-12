#include "GfxRect.h"
#include "GfxTriangle.h"
#include <iostream>
#include <conio.h>
#define GfxRectangle GfxRect 
int blatt_92_main(GfxObject **, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);

void printScreen(char s[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	for (int y = 0; y < SCREEN_HEIGHT; ++y) {
	  for (int x = 0; x < SCREEN_WIDTH; ++x) {
			std::cout << s[y][x]; 
	  }
		std::cout << std::endl; 
	}
	std::cout << std::endl; 
}


void deleteScreen(char s[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	for (int y = 0; y < SCREEN_HEIGHT; ++y) {
		for (int x = 0; x < SCREEN_WIDTH; ++x) {
			s[x][y] = ' ';
		}
	}
}

void drawBorder(char s[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	for (int x = 1; x < SCREEN_WIDTH; ++x) {
		s[0][x] = '-'; 
		s[SCREEN_HEIGHT - 1][x] = '-';
	}
	for (int y = 1; y < SCREEN_HEIGHT; ++y) {
		s[y][0] = '|';
		s[y][SCREEN_WIDTH - 1] = '|';
	}
	s[0][0] = '/'; 
	s[SCREEN_HEIGHT - 1][SCREEN_WIDTH - 1] = '/';
	s[0][SCREEN_WIDTH - 1] = '\\';
	s[SCREEN_HEIGHT - 1][0] = '\\';
}


int blatt_91_main() {
  char screen[SCREEN_HEIGHT][SCREEN_WIDTH]; //use first[] for y, use second[] for x

  deleteScreen(screen);
    
  GfxRectangle r1(5,35,8,8); //x, y, height, width
  r1.draw(screen);
    
  GfxTriangle d1(25,32,5); //x, y, height
  d1.draw(screen);
    
  printScreen(screen);
   
  r1.remove(screen);
  r1.move(10,0);
  r1.draw(screen);
  printScreen(screen);
  
	GfxObject *obj[3]; 
	obj[0] = &r1; 
	obj[1] = &d1; 
	obj[2] = nullptr; 

  return blatt_92_main(obj, screen);
}

int blatt_92_main(GfxObject ** obj, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	char input = '\0'; 
	int aktivIndex = 0; 
	drawBorder(screen); 
	while (1) {
		input = getch(); 
		switch(input) {
		case (char)224: //escape sign for arrow keys
			input = getch(); 
			switch (input) {
			case 'M': //rechts
				obj[aktivIndex]->move(1, 0, screen); 
				break;
			case 'K': //links
				obj[aktivIndex]->move(-1, 0, screen); 
				break;
			case 'H': //oben
				obj[aktivIndex]->move(0, -1, screen); 
				break;
			case 'P': //unten
				obj[aktivIndex]->move(0, 1, screen); 
				break;

			}

			break; 
		case '+': 
			obj[aktivIndex]->makeLarger(1, screen); 
			break; 
		case '-': 
			obj[aktivIndex]->makeLarger(-1, screen); 
			break; 
		case ' ': 
			++aktivIndex;
			if (obj[aktivIndex] == nullptr) aktivIndex = 0;
			break; 
		case 'b':
			drawBorder(screen);
			break; 
		case 'c': 
			std::cout << "Neues Zeichen eingeben: "; 
			std::cin >> input; 
			obj[aktivIndex]->setChar(input); 
			obj[aktivIndex]->draw(screen);
			break; 
		case (char)27: 
			return 0; 
		}
		//system("cls");
		printScreen(screen);
	}
}

int main() {
	return blatt_91_main();
}