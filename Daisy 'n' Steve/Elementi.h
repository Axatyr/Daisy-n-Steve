#ifndef ELEMENTI_H
#define ELEMENTI_H

#include "Figura.h"

class Elementi
{
public:
	Elementi();

	Figura* getCielo();
	Figura* getPrato();
	Figura* getSole();
	Figura* getGoccia();
	Figura* getSeme();
	Figura* getStelo();
	Figura* getFontana();
	Figura* getFungo();
	Figura* getPetalo();

};

#endif
