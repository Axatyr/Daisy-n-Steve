#include "GestioneEventi.h"



//extern int width;
bool changeLeg; //False -> dx avanti, True -> sx avanti
bool day = true;


Elementi* ScenaCorrente = new Elementi();
GLuint modelCorrente;

void setScena(Elementi* scena, GLuint matmodel) {
	ScenaCorrente = scena;
	modelCorrente = matmodel;
	
}




void giorno_notte()
{
	if (day)
	{
		//Cielo
		modifica_cielo(ScenaCorrente->getCielo(), notte_cielo_bottom, notte_cielo_top);
		crea_VAO_Vector(ScenaCorrente->getCielo());
		//Prato
		modifica_prato(ScenaCorrente->getPrato(), notte_prato_bottom, notte_prato_top);
		crea_VAO_Vector(ScenaCorrente->getPrato());
		//Sole/Luna
		modifica_sole(ScenaCorrente->getSole(), luna_bottom, luna_top, luna_radius, luna_center);
		crea_VAO_Vector(ScenaCorrente->getSole());
		day = false;
	}
	else
	{
		//Cielo
		modifica_cielo(ScenaCorrente->getCielo(), giorno_cielo_bottom, giorno_cielo_top);
		crea_VAO_Vector(ScenaCorrente->getCielo());
		//Prato
		modifica_prato(ScenaCorrente->getPrato(), giorno_prato_bottom, giorno_prato_top);
		crea_VAO_Vector(ScenaCorrente->getPrato());
		//Sole/Luna
		modifica_sole(ScenaCorrente->getSole(), sole_bottom, sole_top, sole_radius, sole_center);
		crea_VAO_Vector(ScenaCorrente->getSole());
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
	for (int i = 0; i < ScenaCorrente->Steve.size(); i++) {
		ScenaCorrente->Steve[i]->posx += 1;
		if (i == 4)
		{
			ScenaCorrente->setAngolo(45.0);
			ScenaCorrente->Steve[i]->rotatey = 1.0;

			/*imposto angolo della rotate, i parametri*/
			/*confronto fra gamba destra e gamba sinistra, uso di bool*/
		}
	}



}

void moveLeft()
{
	for (int i = 0; i < ScenaCorrente->Steve.size(); i++) {
		ScenaCorrente->Steve[i]->posx -= 1;
	}
}

void jump()
{

		for (int i = 0; i < ScenaCorrente->Steve.size(); i++) {
			ScenaCorrente->Steve[i]->posy += 50;
		}

}