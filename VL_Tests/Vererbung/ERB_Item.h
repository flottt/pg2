#ifndef __ERB_Musik_Item_H__
#define __ERB_Musik_Item_H__
#include <stdio.h>
class Item {
private: 
	static int MAX_ID; 

protected: 
	Item(); 
	~Item(); 

public: 
	int id; 
	int getId(void) const;  
	void debugDump(int byteAnzahl = 0, int step = 1);
};


#endif // __ERB_Musik_Item_H__
