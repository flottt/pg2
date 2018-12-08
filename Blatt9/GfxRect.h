#ifndef __GFXRECT_H__
#define __GFXRECT_H__
#include "GfxObject.h"

class GfxRect : public GfxObject {
protected: 
	int height, width; 
public: 
	GfxRect(int x = 0, int y = 0, int width = 2, int height = 2, char charRep = '*');
	virtual void paint(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], char charprint);
	virtual void makeLarger(int diff); 
};

#endif //__GFXRECT_H__
