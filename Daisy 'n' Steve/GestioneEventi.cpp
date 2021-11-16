#include "GestioneEventi.h"

/*
extern bool pressing_left, pressing_right, moving;
extern double dx;
extern double dy; //velocita verticale (pixel per frame)
extern double velocitaMassima; // velocita di movimento orizzontale massima
extern double delta;
extern float distacco_da_terra; //negativo, perchè lo misuro nel sistema di riferimento locale della palla
extern double accelerazione; // forza di accelerazione data dalla tastiera
extern double decelerazione; //decelerazione in assenza di input
extern float posx; //coordinate sul piano della posizione iniziale della palla
extern float posy;
extern int width;
extern float angolo;
*/


Elementi* ScenaCorrente = new Elementi();

void setScena(Elementi* scena) {
	ScenaCorrente = scena;
}

bool day = true;




void giorno_notte()
{
	if (day)
	{
		//Cielo
		costruisci_cielo(ScenaCorrente->getCielo(), notte_cielo_bottom, notte_cielo_top);
		crea_VAO_Vector(ScenaCorrente->getCielo());
		//Prato
		costruisci_prato(ScenaCorrente->getPrato(), notte_prato_bottom, notte_prato_top);
		crea_VAO_Vector(ScenaCorrente->getPrato());
		//Sole/Luna
		costruisci_sole(ScenaCorrente->getSole(), luna_bottom, luna_top, luna_radius, luna_center);
		crea_VAO_Vector(ScenaCorrente->getSole());
		day = false;
	}
	else
	{
		//Cielo
		costruisci_cielo(ScenaCorrente->getCielo(), giorno_cielo_bottom, giorno_cielo_top);
		crea_VAO_Vector(ScenaCorrente->getCielo());
		//Prato
		costruisci_prato(ScenaCorrente->getPrato(), giorno_prato_bottom, giorno_prato_top);
		crea_VAO_Vector(ScenaCorrente->getPrato());
		//Sole/Luna
		costruisci_sole(ScenaCorrente->getSole(), sole_bottom, sole_top, sole_radius, sole_center);
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
		//pressing_left = true;
		break;

	case 'd':
		//pressing_right = true;
		break;

	case 'p':
		exit(0);
		break;

	case 'n':
		giorno_notte();

	default:
		break;
	}
}

void keyboardReleasedEvent(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		//pressing_left = false;
		break;

	case 'd':
		//pressing_right = false;
		break;

	case 'p':
		exit(0);
		break;

	default:
		break;
	}
}

void mouseEvent(int button, int state, int x, int y)
{

}


void update(int a)
{
	bool moving = false;
	//Movimento della palla in orizzontale

	/*if (pressing_left)
	{
		dx -= accelerazione;
		moving = true;
	}

	if (pressing_right)
	{
		dx += accelerazione;
		moving = true;
	}

	// Se non mi sto muovendo con i tasti a e d decremento od incremento la velocita' iniziale fino a portarla
	// a zero e la palla continua a rimbalzare sul posto

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
	glutTimerFunc(24, update, 0);

	
}
