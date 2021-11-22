#ifndef OMINO_H
#define OMINO_H

#include "Figura.h"
#include "Color.h"

class Omino
{
public:
	Omino();

private:
	Figura creaTesta();
	Figura creaCorpo();
	Figura creaGambe();


};
#endif