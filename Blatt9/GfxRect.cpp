#include "GfxRect.h"

GfxRect::GfxRect(int x, int y, int width, int height, char charRep) : GfxObject(x, y, charRep), height(height), width(width) {}

void GfxRect::paint(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], char charprint) {
	int zeileFrom = this->y; 
	if (zeileFrom < 0) zeileFrom = 0; 
	int zeileToExcl = this->y + this->height; 
	if (zeileToExcl > SCREEN_HEIGHT) zeileToExcl = SCREEN_HEIGHT; 

	register int spalteFrom = this->x; 
	if (spalteFrom < 0) spalteFrom = 0; 
	register int spalteToExcl = this->x + this->width; 
	if (spalteToExcl > SCREEN_WIDTH) spalteToExcl = SCREEN_WIDTH; 

	for (int j = zeileFrom; j < zeileToExcl; ++j) {
		for (int i = spalteFrom; i < spalteToExcl; ++i) {
			screen[j][i] = charprint; 
		}
	}
}

void GfxRect::makeLarger(int diff) {
	this->width += diff; 
	this->height += diff; 
	if (this->width < 0) this->width = 0; 
	if (this->height < 0) this->height = 0;
}

