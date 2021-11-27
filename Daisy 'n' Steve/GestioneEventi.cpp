#include "GestioneEventi.h"

bool changeLeg; //False -> dx avanti, True -> sx avanti
bool day = true;
bool destra = true;
bool rotazione = false;
extern bool moving;
extern float angolodx;
extern float angolosx;

extern Elementi* Scena;



void giorno_notte()
{
	if (day)
	{
		//Cielo
		modifica_cielo(Scena->getCielo(), notte_cielo_bottom, notte_cielo_top);
		crea_VAO_Vector(Scena->getCielo());
		//Prato
		modifica_prato(Scena->getPrato(), notte_prato_bottom, notte_prato_top);
		crea_VAO_Vector(Scena->getPrato());
		//Sole/Luna
		modifica_sole(Scena->getSole(), luna_bottom, luna_top, luna_radius, luna_center);
		crea_VAO_Vector(Scena->getSole());
		day = false;
	}
	else
	{
		//Cielo
		modifica_cielo(Scena->getCielo(), giorno_cielo_bottom, giorno_cielo_top);
		crea_VAO_Vector(Scena->getCielo());
		//Prato
		modifica_prato(Scena->getPrato(), giorno_prato_bottom, giorno_prato_top);
		crea_VAO_Vector(Scena->getPrato());
		//Sole/Luna
		modifica_sole(Scena->getSole(), sole_bottom, sole_top, sole_radius, sole_center);
		crea_VAO_Vector(Scena->getSole());
		day = true;
	}

	glutPostRedisplay();
	glutTimerFunc(24, update, 0);
}

void keyboardPressedEvent(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		moving = true;
		moveLeft();
		break;

	case 'd':
		moving = true;
		moveRight();
		break;

	case 'w':
		moving = true;
		jump();
		break;

	case 'n':
		giorno_notte();
		break;

	case 'p':
		exit(0);
		break;

	default:
		break;
	}
}

void update(int a)
{
	bool moving = false;
	//Movimento della palla in orizzontale


	// Se non mi sto muovendo con i tasti a e d decremento od incremento la velocita' iniziale fino a portarla
	// a zero e la palla continua a rimbalzare sul posto

	/*
	if (!moving) {  

		dx > 0 ? dx -= 1 : dx = 0;

		dx < 0 ? dx += 1 : dx = 0;
	}

	//Aggioramento della posizione in x della pallina, che regola il movimento orizzontale

	posx += dx;



	//Se la pallina assume una posizione in x minore di 0 o maggiore di width dello schermo
	//facciamo rimbalzare la pallina ai bordi dello schermo

	if (posx < 0) {
		posx = 0;
		dx = -dx * 0.8;
	}

	if (posx > width) {
		posx = width;
		dx = -dx * 0.8;
	}

	// Gestione del rimbalzo e quindi dell'altezza da terra

	//Rimbalzo
	dy-= delta;
	
	distacco_da_terra-= dy;
	
		
	if (distacco_da_terra > 30)
	{
		distacco_da_terra = 30;
		dy = 30;   //Una volta giunta a terra la pallina ottiene un impulso positivo che la ritornare su
	}
	*/
	glutPostRedisplay();
	glutTimerFunc(66, update, 0);

	
}

void moveRight()
{
	/*
	* confronto posizione
		if Scena->Steve[i]->posx == 8 ;
	*/

	if (!destra)
	{
		destra = true;
		ruota_omino(Scena->Steve, destra);
	}

	for (int i = 0; i < Scena->Steve.size(); i++) {
		Scena->Steve[i]->posx += 8;
		if (i == 3)
		{
			Scena->Steve[i]->rotatez = 1.0;
			rotazione == false ? angolodx = 45.0 : angolodx = 0.0;
			
		}
		if (i == 4)
		{
			Scena->Steve[i]->rotatez = 1.0;
			rotazione == false ? angolosx = -45.0 : angolosx = 0.0;
		}
	}
	rotazione = !rotazione;
}

void moveLeft()
{
	if (destra)
	{
		destra = false;
		ruota_omino(Scena->Steve, destra);
	}


	for (int i = 0; i < Scena->Steve.size(); i++) {
		Scena->Steve[i]->posx -= 8;
		if (i == 3)
		{
			Scena->Steve[i]->rotatez = 1.0;
			rotazione == true ? angolodx = -45.0 : angolodx = 0.0;
			
		}
		if (i == 4)
		{
			Scena->Steve[i]->rotatez = 1.0;
			rotazione == true ? angolosx = 45.0 : angolosx = 0.0;
		}
	}
	rotazione = !rotazione;

}

void jump()
{

		for (int i = 0; i < Scena->Steve.size(); i++) {
			Scena->Steve[i]->posy += 50;
		}

		/*
			if se la posx == fungo 
			allora ditruggi fungo()
			
		*/
}