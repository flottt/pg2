#ifndef __B10_MATERIAL_H__
#define __B10_MATERIAL_H__
#include "AbstractArticle.h" 

class Material : public AbstractArticle {
protected:
	char supplier[20]; 
	float weight; 

public: 
public:
	Material();

	virtual void input(); 
	virtual void loadfromfile(std::ifstream & file);
	virtual void savetofile(std::ofstream & file) const;

	virtual void printout() const;
	
};

#endif //__B10_MATERIAL_H__