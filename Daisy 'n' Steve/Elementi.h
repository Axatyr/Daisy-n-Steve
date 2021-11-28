#ifndef ELEMENTI_H
#define ELEMENTI_H

#include "Figura.h"

class Elementi
{
public:
	
	vector<Figura*> Steve;
	Elementi();

	Figura* getCielo();
	Figura* getPrato();
	Figura* getSole();
	Figura* getGoccia();
	void setGoccia(Figura* goccia);
	Figura* getSeme();
	Figura* getStelo();
	Figura* getFontana();
	Figura* getFungo();
	void setFungo(Figura* fungo);
	Figura* getPetalo();
	Figura* getPistillo();
	Figura* getTesta();
	Figura* getOcchio();
	Figura* getBocca();
	Figura* getCorpo();
	Figura* getBraccio();
	Figura* getManico();
	Figura* getSecchio();
	Figura* getGambadx();
	Figura* getGambasx();



};

#endif
