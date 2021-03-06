#ifndef __GFXTRIANGLE_H__
#define __GFXTRIANGLE_H__
#include "GfxObject.h"

class GfxTriangle : public GfxObject {
protected: 
	/** x = linkeste Position des Dreiecks. (bei unterem Schenkel) */
	/** y = oberste Position des Dreiecks. (bei Spitze) */
	/** Hoehe des Dreiecks. */
	int h; 

public: 
	GfxTriangle(int x, int y, int h, char charRep = '*');
	virtual void paint(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], char charprint);
	virtual void makeLarger(int diff);
};

#endif //__GFXTRIANGLE_H__
