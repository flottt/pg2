#include <stdio.h>
#include <conio.h>
typedef char feld; 
typedef unsigned char routefeld; 
const int MAPWIDTH = 14;
const int MAPHEIGHT = 14; 
feld map[MAPWIDTH * MAPHEIGHT + 1]; 
routefeld route[MAPWIDTH * MAPHEIGHT + 1]; 
int pos; 

#define mapp(x, y) (map[(y) * MAPWIDTH + (x)])
#define getX() (pos % MAPWIDTH)
#define getY() (pos / MAPWIDTH)
#define NEXTFLAG_OBEN 1
#define NEXTFLAG_UNTEN 2
#define NEXTFLAG_LINKS 4
#define NEXTFLAG_RECHTS 8
#define NEXTFLAG_OR 16
#define NEXTFLAG_UR 32
#define NEXTFLAG_OL 64
#define NEXTFLAG_UL 128
#define NEXTDIFF_OBEN() (-MAPWIDTH) 
#define NEXTDIFF_UNTEN() (+MAPWIDTH) 
#define NEXTDIFF_LINKS() (-1) 
#define NEXTDIFF_RECHTS() (1) 
#define NEXTDIFF_OBENRECHTS() (NEXTDIFF_OBEN() + NEXTDIFF_RECHTS()) 
#define NEXTDIFF_UNTENRECHTS() (NEXTDIFF_UNTEN() + NEXTDIFF_RECHTS()) 
#define NEXTDIFF_OBENLINKS() (NEXTDIFF_OBEN() + NEXTDIFF_LINKS()) 
#define NEXTDIFF_UNTENLINKS() (NEXTDIFF_UNTEN() + NEXTDIFF_LINKS()) 




void printmap(); 
void readFile(const char * FILENAME = "map.txt"); 
void routeTo(feld ziel); 



void printmap() {
	for (int y = 0; y < MAPHEIGHT; ++y) {
		for (int x = 0; x < MAPWIDTH; ++x) {
			printf("%c", mapp(x, y));
		}
		for (int x = 0; x < MAPWIDTH; ++x) {
			printf(" %03hhi", (route[(y)* MAPWIDTH + (x)]));
		}
		printf("\n");
	}
}

void readFile(const char * FILENAME) {
	map[MAPWIDTH * MAPHEIGHT] = '\0';
	route[MAPWIDTH * MAPHEIGHT] = '\0';
	FILE * file = fopen(FILENAME, "r");
	if (file == nullptr) {
		
		printf("IO-ERROR: cannot open file \n"); 
	} else {
		const int dim = MAPHEIGHT * MAPWIDTH; 
		char cc = '\0'; 
		feld * mapPtr = map; 
		feld const * const mapPtrEnde = mapPtr + MAPHEIGHT * MAPWIDTH; 

		for (; mapPtr < mapPtrEnde; ++mapPtr) {
			fscanf(file, "%c", &cc); 
			//force upper case
			if (cc >= 'a' && cc <= 'z') {
				cc -= ('a' - 'A');
			}
			*mapPtr = cc; 
			if (cc == 'S') {
				pos = mapPtr - map; 
			}
			if (cc == '\0') {
				printf("IO-ERROR: map is incomplete. \n");
				for (; mapPtr < mapPtrEnde; ++mapPtr) {
					*mapPtr = '\0';
				}
			}
		}

	  fclose(file); 
	}
}

/** put value on the stack #index */
inline void pushToStack(int * stack, int distanz, int feldPtr) {
	route[feldPtr] = distanz; 
	distanz %= 4;
	stack += distanz * (2 * (MAPHEIGHT + MAPWIDTH));
	++(*stack);
	*(stack + 1 + (*stack)) = feldPtr; 
}

inline int popFromStack(int * stack, int distanz) {
	distanz %= 4; 
	stack += (distanz * (2 * (MAPHEIGHT + MAPWIDTH)));

	if (*stack == 0) {
		return -1; 
	}
	--(*stack); 
	return *(stack + 2 + *stack);
}

/** test if any stack has a content. */
inline bool hasAnyStack(int * stack) {
	for (int i = 0; i < 4; ++i) {
		if (*stack != 0) return true; 
		stack += (2 * (MAPHEIGHT + MAPWIDTH));
	}
	return false; 
}

inline void checkeNachbarfeld(int * fetterstack, const int nextfeldzeiger, int * nextfeldflags, const int nextfeldflagmask, const int requirenextfeldflagmask, int distanzInklMetrik) {
	if (((*nextfeldflags & requirenextfeldflagmask) == requirenextfeldflagmask) && (map[nextfeldzeiger] != '#')) {
		*nextfeldflags |= nextfeldflagmask;
		if (route[nextfeldzeiger] > distanzInklMetrik) {
			pushToStack(fetterstack, distanzInklMetrik, nextfeldzeiger);
		}
	}
}

inline void routeTo_berechneDistanzen(feld ziel) {
	//resette route array
	feld const * mapPtr = map; 
	routefeld const * const routePtrEnde = route + MAPHEIGHT * MAPWIDTH; 
	
	//jeweils erst size, dann content
	int fetterstack[4 * (2 * (MAPHEIGHT + MAPWIDTH))] = { 0 };
	routefeld distanz = 0; 

	for (routefeld * routePtr = route; routePtr < routePtrEnde; ++routePtr, ++mapPtr) {
		if (*mapPtr == ziel) {
		  pushToStack(fetterstack, distanz, mapPtr - map); 

		} else {
		  *routePtr = 250; 
		}
	}

	while (hasAnyStack(fetterstack)) {
		while (1) {
			int feldzeiger = popFromStack(fetterstack, distanz);
			if (feldzeiger == -1) break;
			if (feldzeiger == pos) return; 
			if (route[feldzeiger] != distanz) continue;
			int nextfeldflags = 0;

			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_OBEN(), &nextfeldflags, NEXTFLAG_OBEN, 0, distanz + 2);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_UNTEN(), &nextfeldflags, NEXTFLAG_UNTEN, 0, distanz + 2);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_LINKS(), &nextfeldflags, NEXTFLAG_LINKS, 0, distanz + 2);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_RECHTS(), &nextfeldflags, NEXTFLAG_RECHTS, 0, distanz + 2);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_OBENRECHTS(), &nextfeldflags, 0, NEXTFLAG_OBEN | NEXTFLAG_RECHTS, distanz + 3);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_UNTENRECHTS(), &nextfeldflags, 0, NEXTFLAG_UNTEN | NEXTFLAG_RECHTS, distanz + 3);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_OBENLINKS(), &nextfeldflags, 0, NEXTFLAG_OBEN | NEXTFLAG_LINKS, distanz + 3);
			checkeNachbarfeld(fetterstack, feldzeiger + NEXTDIFF_UNTENLINKS(), &nextfeldflags, 0, NEXTFLAG_UNTEN | NEXTFLAG_LINKS, distanz + 3);
		}
		distanz++;
	}
}


inline void vergleiche(int nextfeldzeiger, int * mindistanz, int * nexthop, int distanz, int * nexthop2, int * nexthop3, int * nextfeldflags, const int nextfeldmask, const int requirenextfeldmask) {
	if (((*nextfeldflags & requirenextfeldmask) == requirenextfeldmask) && (map[nextfeldzeiger] != '#')) {
		*nextfeldflags |= nextfeldmask;
		int routedistanz = route[nextfeldzeiger];
		if (routedistanz == distanz - 2) {
			*nexthop2 = nextfeldzeiger;
		}
		if (routedistanz == distanz - 3) {
			*nexthop3 = nextfeldzeiger;
		}
		if (routedistanz < *mindistanz) {
			*nexthop = nextfeldzeiger;
			*mindistanz = route[nextfeldzeiger];
		}
	}
}

//using fact, that border is wall. => no overflow-check neccessary. 
void routeTo(feld ziel) {
	routeTo_berechneDistanzen(ziel);

	int position = pos; 
	int distanz = route[pos]; 
	int nexthop, nexthop2, nexthop3; 
	int mindistanz; 

	while (map[position] != ziel) {
		distanz = mindistanz = route[position]; 
		nexthop2 = -1; nexthop3 = -1; 
		int nextfeldflags = 0; 
		vergleiche(position + NEXTDIFF_OBEN(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, NEXTFLAG_OBEN, 0);
		vergleiche(position + NEXTDIFF_UNTEN(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, NEXTFLAG_UNTEN, 0);
		vergleiche(position + NEXTDIFF_LINKS(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, NEXTFLAG_LINKS, 0);
		vergleiche(position + NEXTDIFF_RECHTS(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, NEXTFLAG_RECHTS, 0);
		vergleiche(position + NEXTDIFF_OBENLINKS(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, 0, NEXTFLAG_OBEN | NEXTFLAG_LINKS);
		vergleiche(position + NEXTDIFF_OBENRECHTS(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, 0, NEXTFLAG_OBEN | NEXTFLAG_RECHTS);
		vergleiche(position + NEXTDIFF_UNTENLINKS(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, 0, NEXTFLAG_UNTEN | NEXTFLAG_LINKS);
		vergleiche(position + NEXTDIFF_UNTENRECHTS(), &mindistanz, &nexthop, distanz, &nexthop2, &nexthop3, &nextfeldflags, 0, NEXTFLAG_UNTEN | NEXTFLAG_RECHTS);
		
		if (nexthop3 != -1) {
			if (map[position] <= ' ') map[position] = 'x';
			position = nexthop3; 
		} else if (nexthop2 != -1) {
			if (map[position] <= ' ') map[position] = 'x';
			position = nexthop2; 
		} else {
			if (map[position] <= ' ') map[position] = 'x';
			position = nexthop; 
		}


	}



	
}

int robo_main() {
	char cc; 
	readFile(); 
	while (1) {
		printf("Position (%i, %i). MAP: \n", getX(), getY()); 
		printmap();
		printf("next Ziel (1, 2, 3): ", getX(), getY()); 
		cc = getche();
		if (cc >= '1' && cc <= '3') {
			routeTo(cc);
		}
	}
	return 0; 
}