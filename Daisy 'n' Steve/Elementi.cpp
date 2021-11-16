#include"Elementi.h"

Elementi::Elementi(){}

Figura* Cielo = new Figura();
Figura* Prato = new Figura();

Figura* Elementi::getCielo()
{
	return Cielo;
}

Figura* Elementi::getPrato()
{
	return Prato;
}
