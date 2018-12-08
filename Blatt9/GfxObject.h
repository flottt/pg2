#ifndef __GFXOBJECT_H__
#define __GFXOBJECT_H__

#define SCREEN_HEIGHT 50
#define SCREEN_WIDTH 50


class GfxObject {
protected: 
	char charRepr;
	int x, y; 

protected: 
	GfxObject(int x, int y, char charRep = '*'); 

public: 
	virtual ~GfxObject(); 
	virtual void move(int dx, int dy); 
	void move(int dx, int dy, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]); 
	void draw(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);
	void remove(char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);
	virtual void paint(char screen[SCREEN_HEIGHT][SCREEN_WIDTH], char charprint) = 0;

	virtual void makeLarger(int diff) = 0; 
	void makeLarger(int diff, char screen[SCREEN_HEIGHT][SCREEN_WIDTH]);
};


inline int max(int a, int b) { if (a < b) return b; else return a; }
#endif //__GFXOBJECT_H__