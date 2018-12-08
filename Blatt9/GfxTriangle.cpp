#include "GfxTriangle.h"

GfxTriangle::GfxTriangle(int x, int y, int h, char charRep) : GfxObject(x, y, charRep), h(h) {}

void GfxTriangle::paint(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], char charprint) {
	int pyMin = 0; 
	if (this->y < 0) pyMin = -this->y; 
	int pyMaxExcl = this->h; 
	if (this->y + pyMaxExcl > SCREEN_HEIGHT) pyMaxExcl = SCREEN_HEIGHT - this->y; 

	for (int py = pyMin; py < pyMaxExcl; ++py) {
		int pxMin = this->h - py - 1; 
		if (pxMin + this->x < 0) pxMin = -this->x; 
		int pxMaxExcl = this->h + py; 
		if (pxMaxExcl + this->x > SCREEN_WIDTH) pxMaxExcl = SCREEN_WIDTH - this->x; 
		for (int px = pxMin; px < pxMaxExcl; ++px) {
			screen[py + this->y][px + this->x] = charprint;
		}

	}
}

void GfxTriangle::makeLarger(int diff) {
	this->h += diff; 
	if (this->h < 0) this->h = 0;
	this->x -= diff;
}


