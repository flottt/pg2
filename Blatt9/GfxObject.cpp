#include "GfxObject.h"



GfxObject::GfxObject(int x, int y, char charRep) : x(x), y(y), charRepr(charRep) {

}

GfxObject::~GfxObject() {
}

void GfxObject::move(int dx, int dy) {
	this->x += dx; 
	this->y += dy; 
}

void GfxObject::move(int dx, int dy, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	this->remove(screen); 
	this->move(dx, dy); 
	this->draw(screen); 
}

void GfxObject::draw(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	this->paint(screen, this->charRepr);
}

void GfxObject::remove(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	this->paint(screen, ' ');
}

void GfxObject::makeLarger(int diff, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	this->remove(screen); 
	this->makeLarger(diff); 
	this->draw(screen);
}
