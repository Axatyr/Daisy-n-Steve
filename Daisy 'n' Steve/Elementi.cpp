#include"Elementi.h"

Elementi::Elementi(){}

Figura* Cielo = new Figura();
Figura* Prato = new Figura();
Figura* Sole = new Figura();
Figura* Goccia = new Figura();
// Da valutare se avere solo figure e poi quando "levella il fiore" si aggiungono le altre parti oppure fare una classe solo per fiore
Figura* Seme = new Figura();
Figura* Stelo = new Figura();
Figura* Fontana = new Figura();
Figura* Fungo = new Figura();
Figura* Petalo = new Figura();
Figura* Pistillo = new Figura();

Figura* Testa = new Figura();
Figura* Occhio = new Figura();
Figura* Bocca = new Figura();
Figura* Corpo = new Figura();
Figura* Braccio = new Figura();
Figura* Manico = new Figura();
Figura* Secchio = new Figura();
Figura* Gambadx = new Figura();
Figura* Gambasx = new Figura();



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
Figura* Elementi::getFontana()
{
	return Fontana;
}
Figura* Elementi::getFungo()
{
	return Fungo;
}
Figura* Elementi::getPetalo()
{
	return Petalo;
}
Figura* Elementi::getTesta() 
{
	return Testa;
}
Figura* Elementi::getOcchio()
{
	return Occhio;
}
Figura* Elementi::getBocca()
{
	return Bocca;
}
Figura* Elementi::getCorpo()
{
	return Corpo;
}
Figura* Elementi::getBraccio()
{
	return Braccio;
}
Figura* Elementi::getManico()
{
	return Manico;
}
Figura* Elementi::getSecchio()
{
	return Secchio;
}
Figura* Elementi::getGambadx()
{
	return Gambadx;
}
Figura* Elementi::getGambasx()
{
	return Gambasx;
}
Figura* Elementi::getPistillo()
{
	return Pistillo;
}

void Elementi::setAngolo(float angolo)
{
	this->angolo = angolo;
}

float Elementi::getAngolo()
{
	return angolo;
}

