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

Elementi* Sscena = new Elementi();

void setScena(Elementi* scena) {
	Sscena = scena;
}

bool day = true;

vec4 giorno_cielo_top = { 0.6471, 0.3020,1.0,1.0 };
vec4 giorno_cielo_bottom = { 0.0, 0.4980,1.0,1.0 };

vec4 notte_cielo_top = { 0.0, 0.0, 1.0, 1.0 };
vec4 notte_cielo_bottom = { 0.0, 1.0, 0.0, 1.0 };



void colore_cielo()
{
	if (day)
	{
		/*
		for (int i = 0; i < 2; i++)
		{
			setColCielo(notte_cielo_bottom, i);
			
			//notte_cielo_bottom

		}
		for (int i = 2; i < 4; i++)
		{
			setColCielo(notte_cielo_top, i);
			//notte_cielo_bottom
			
		}
		*/

		costruisci_cielo(Sscena->getCielo(), notte_cielo_bottom, notte_cielo_top);
		crea_VAO_Vector(Sscena->getCielo());

		day = false;
	}
	else
	{
		/*
		for (int i = 0; i < 2; i++)
		{
			setColCielo(giorno_cielo_bottom, i);
			//giorno_cielo_bottom

		}
		for (int i = 2; i < 4; i++)
		{
			setColCielo(giorno_cielo_top, i);
			//giorno_cielo_top
		}
		*/
		costruisci_cielo(Sscena->getCielo(), giorno_cielo_bottom, giorno_cielo_top);
		crea_VAO_Vector(Sscena->getCielo());
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
		colore_cielo();

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
