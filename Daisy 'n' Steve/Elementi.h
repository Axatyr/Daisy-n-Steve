#ifndef ELEMENTI_H
#define ELEMENTI_H

#include "Figura.h"
#include "Omino.h"

class Elementi
{
public:
	vector<Figura*> Steve;
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
	void setAngolo(float angolo);
	float getAngolo();

private:
	float angolo = 0.0;

};

#endif
