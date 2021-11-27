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

int score=0;
bool score_acqua = false;
bool fiore_morto = false;
bool stelo_presente = false;
bool fiore_presente = false;
bool secchio_pieno = false;


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

	case 'e':
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

//Gestione secchio
void riempi()
{
	float posxManico = Scena->getManico()->posx;
	float posyManico = Scena->getManico()->posy;
	float posxSecchio = Scena->getSecchio()->posx;
	float posySecchio = Scena->getSecchio()->posy;

	//Metto il secchio sotto la fontana
	Scena->getManico()->posx = float(WIDTH) * 0.13;
	Scena->getManico()->posy = float(HEIGHT) * 0.25;
	Scena->getSecchio()->posx = float(WIDTH) * 0.13;
	Scena->getSecchio()->posy = float(HEIGHT) * 0.25;

	//Goccia Acqua
	Scena->getGoccia()->posx = float(WIDTH) * 0.25;
	Scena->getGoccia()->posy = float(HEIGHT) * 0.3;
	Scena->getGoccia()->scalex = 5.0;
	Scena->getGoccia()->scaley = 5.0;
	Scena->getGoccia()->nTriangles = 40;
	costruisci_goccia(Scena->getGoccia(), acqua);
	crea_VAO_Vector(Scena->getGoccia());


	updateGoccia(0);

	
	/*//Riprendo il secchio 
	Scena->getManico()->posx = posxManico;
	Scena->getManico()->posy = posyManico;
	Scena->getSecchio()->posx = posxSecchio;
	Scena->getSecchio()->posy = posySecchio;*/

	score_acqua = true;
}

void updateGoccia(int value)
{
	Scena->getGoccia()->posy--;
	//L'animazione deve avvenire finch�  l'ordinata del proiettile raggiunge un certo valore fissato
	if (Scena->getGoccia()->posy >= (float(HEIGHT) * 0.30))
	{
		
		//Disegno Goccia
		glBindVertexArray(Scena->getGoccia()->VAO);
		Scena->getGoccia()->Model = mat4(1.0);
		Scena->getGoccia()->Model = translate(Scena->getGoccia()->Model, vec3(Scena->getGoccia()->posx, Scena->getGoccia()->posy, 0.0));
		Scena->getGoccia()->Model = scale(Scena->getGoccia()->Model, vec3(Scena->getGoccia()->scalex, Scena->getGoccia()->scaley, 1.0));
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getGoccia()->Model));
		glDrawArrays(GL_TRIANGLE_FAN, 0, (Scena->getGoccia()->nTriangles) + 2);
		glBindVertexArray(0);
		glutTimerFunc(5, updateGoccia, 0);
	}		
	else
	{
		//destroy(Scena->getGoccia());
	}

	glutPostRedisplay();
}