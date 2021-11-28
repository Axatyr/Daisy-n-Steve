#include "GestioneEventi.h"

bool changeLeg; //False -> dx avanti, True -> sx avanti
bool day = true;
bool destra = true;
bool rotazione = false;
extern bool moving;
extern float angolodx;
extern float angolosx;
extern GLuint MatModel;

extern Elementi* Scena;

float posy_jump = 0;


float dist; //usata per la funzione riempi e per distruzione fungo
float disty; // usata per la distruzione fungo
float posxManico;
float posyManico;
float posxSecchio;
float posySecchio;

int score=0;
bool score_acqua = false;
bool fiore_morto = false;
bool stelo_presente = false;
bool fiore_presente = false;
bool secchio_pieno = false;
bool fungo_presente = false;
bool gameover = false;


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

		if (score_acqua) {
			score++;
		}
		else
		{
			score--;
		}
		score_acqua = false;
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
	if (gameover)
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
			jump(0);
			break;
		
		case 'p':
			exit(0);
		break;

		default:
		break;
		}
	}
	else
	{
		switch (key)
		{
		case 'a':
			moving = true;
			moveLeft();
			break;

		case 'd':
			moving = true;
			if (fungo_presente && Scena->getGambadx()->posx == Scena->getFungo()->posx)
			{
				printf("Distruggi il fungo!");
				break;
			}
			moveRight();
			break;

		case 'w':
			dist = Scena->getGambadx()->posx - Scena->getFungo()->posx;
			jump(0);
			if (dist <= 50 && dist >= -50)
			{
				distruggi_fungo();
				printf("Distrutto!");
			}
			break;

		case 'e':
			dist = Scena->getFontana()->posx - Scena->Steve[0]->posx;
			if (dist <= 50 && dist >= -150)
				riempi();
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
}

void update(int a)
{
	bool moving = false;

	// Logica gioco
	if (score < 0)
	{
		if (!fiore_morto)
		{
			muore_fiore();
			printf("Game over!");
			gameover = true;
		}

	}
	else if (score == 1)
	{
		if (!stelo_presente)
		{
			crea_stelo();
			printf("Continua cosi'!");
		}
	}
	else if (score == 2)
	{
		if (!fiore_presente)
		{
			crea_fiore();
			printf("Hai vinto!, continua a curare il tuo fiore adesso");
		}
	}

	glutPostRedisplay();
	glutTimerFunc(24, update, 0);

	
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

void jump(int value)
{

	if (posy_jump <= 50)
	{
		for (int i = 0; i < Scena->Steve.size(); i++) {
			Scena->Steve[i]->posy++;
		}
		posy_jump++;
		glutTimerFunc(5, jump, 0);
		
	}
	else
	{
		
		for (int i = Scena->Steve.size() - 1; i >= 0; i--) {
			Scena->Steve[i]->posy -= posy_jump;
		}

		posy_jump = 0;
	}
	glutPostRedisplay();
}

//Gestiona Fiore

void crea_stelo()
{
	stelo_presente = true;
	Scena->getStelo()->posx = float(WIDTH) * 0.9;
	Scena->getStelo()->posy = float(HEIGHT) * 0.2;
	Scena->getStelo()->scalex = 4.0;
	Scena->getStelo()->scaley = 15.0;
	Scena->getStelo()->nTriangles = 40;
	costruisci_stelo(Scena->getStelo(), stelo_top);
	crea_VAO_Vector(Scena->getStelo());

}
void crea_fiore()
{
	fiore_presente = true;
	//Petalo
	Scena->getPetalo()->posx = float(WIDTH) * 0.9;
	Scena->getPetalo()->posy = float(HEIGHT) * 0.35;
	Scena->getPetalo()->scalex = 8.0;
	Scena->getPetalo()->scaley = 8.0;
	costruisci_petalo(Scena->getPetalo(), fiore_top, fiore_bot);
	crea_VAO_Vector(Scena->getPetalo());

	//Pistillo
	Scena->getPistillo()->posx = float(WIDTH) * 0.9;
	Scena->getPistillo()->posy = float(HEIGHT) * 0.35;
	Scena->getPistillo()->scalex = 10.0;
	Scena->getPistillo()->scaley = 10.0;
	Scena->getPistillo()->nTriangles = 40;
	costruisci_cerchio(Scena->getPistillo(), colore_pistillo);
	crea_VAO_Vector(Scena->getPistillo());
}
void muore_fiore()
{
	fiore_morto = true;
	modifica_fiore(Scena->getStelo(), Scena->getPetalo(), color_stelo_morto, color_petalo_morto);
	Scena->getStelo()->sceltaVS = 0;
	crea_VAO_Vector(Scena->getStelo());
	crea_VAO_Vector(Scena->getPetalo());
}

void crea_fungo() 
{
	Figura* fungo = new Figura();
	Scena->setFungo(fungo);
	//Fungo
	fungo_presente = true;
	Scena->getFungo()->posx = float(WIDTH) * 0.8;
	Scena->getFungo()->posy = float(HEIGHT) * 0.2;
	Scena->getFungo()->scalex = 8.0;
	Scena->getFungo()->scaley = 8.0;
	costruisci_fungo(Scena->getFungo(), fungo_top, fungo_bot);
	crea_VAO_Vector(Scena->getFungo());
}

void distruggi_fungo()
{
	fungo_presente = false;
	delete(Scena->getFungo());
}

//Gestione secchio
void riempi()
{
	posxManico = Scena->getManico()->posx;
	posyManico = Scena->getManico()->posy;
	posxSecchio = Scena->getSecchio()->posx;
	posySecchio = Scena->getSecchio()->posy;

	//Metto il secchio sotto la fontana
	
	Scena->getManico()->posx = float(WIDTH) * 0.13;
	Scena->getManico()->posy = float(HEIGHT) * 0.25;
	Scena->getSecchio()->posx = float(WIDTH) * 0.13;
	Scena->getSecchio()->posy = float(HEIGHT) * 0.25;

	//Goccia Acqua
	Figura* goccia = new Figura();
	Scena->setGoccia(goccia);
	Scena->getGoccia()->posx = float(WIDTH) * 0.149;
	Scena->getGoccia()->posy = float(HEIGHT) * 0.41;
	Scena->getGoccia()->scalex = 5.0;
	Scena->getGoccia()->scaley = 5.0;
	Scena->getGoccia()->nTriangles = 40;
	costruisci_goccia(Scena->getGoccia(), acqua);
	crea_VAO_Vector(Scena->getGoccia());

	updateGoccia(0);
	
	score_acqua = true;
	if (!fungo_presente)
	{
		crea_fungo();
	}
}

void updateGoccia(int value)
{
	Scena->getGoccia()->posy--;
	//L'animazione deve avvenire finchè  l'ordinata del proiettile raggiunge un certo valore fissato
	if (Scena->getGoccia()->posy >= (float(HEIGHT) * 0.21))
	{
		glutTimerFunc(5, updateGoccia, 0);
	}		
	else
	{
		//Riprendo il secchio 
		Scena->getManico()->posx = posxManico;
		Scena->getManico()->posy = posyManico;
		Scena->getSecchio()->posx = posxSecchio;
		Scena->getSecchio()->posy = posySecchio;

		delete(Scena->getGoccia());
	}

	glutPostRedisplay();
}

