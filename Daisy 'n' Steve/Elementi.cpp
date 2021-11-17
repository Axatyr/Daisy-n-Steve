#include"Elementi.h"

Elementi::Elementi(){}

Figura* Cielo = new Figura();
Figura* Prato = new Figura();
Figura* Sole = new Figura();
Figura* Goccia = new Figura();
// Da valutare se avere solo figure e poi quando "levella il fiore" si aggiungono le altre parti oppure fare una classe solo per fiore
Figura* Seme = new Figura();
Figura* Stelo = new Figura();
Figura* Fiore = new Figura();
Figura* Fontana = new Figura();
Figura* Fungo = new Figura();

Figura* Elementi::getCielo()
{
	return Cielo;
}

Figura* Elementi::getPrato()
{
	return Prato;
}

Figura* Elementi::getSole()
{
	return Sole;
}
Figura* Elementi::getGoccia()
{
	return Goccia;
}
Figura* Elementi::getSeme()
{
	return Seme;
}
Figura* Elementi::getStelo()
{
	return Stelo;
}
Figura* Elementi::getFiore()
{
	return Fiore;
}
Figura* Elementi::getFontana()
{
	return Fontana;
}
Figura* Elementi::getFungo()
{
	return Fungo;
}


