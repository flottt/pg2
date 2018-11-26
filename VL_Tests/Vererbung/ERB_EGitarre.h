#ifndef __ERB_Musik_EGitarre_H__
#define __ERB_Musik_EGitarre_H__
#include "ERB_Gitarre.h"

class EGitarre : public Gitarre {
private: 
	int iSpannungMilliVolt; 


protected: 
public: 
	EGitarre(); 
	EGitarre(const Gitarre &); 
	~EGitarre();
};

// -----
int musik_main(); 
#endif // __ERB_Musik_EGitarre_H__
