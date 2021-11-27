// Daisy 'n' Steve.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

#include <iostream>
#include "Lib.h"
#include "ShaderMaker.h"
#include "GestioneEventi.h"
#include "Figura.h"
#include "Elementi.h"
#include "VAO.h"


unsigned int lsceltavs, loc_time, loc_res;
static unsigned int programId;

//gestione score
int score = 3;
bool stelo_presente = false;
bool fiore_presente = false;

//gestione rotate
bool moving = false;
float angolo = 0.0;
float angolodx = 0.0;
float angolosx = 0.0;

mat4 Projection;
GLuint MatProj, MatModel;
int nv_P;

Elementi* Scena = new Elementi();

void INIT_SHADER()
{
	GLenum ErrorCheckValue = glGetError();

	char* vertexShader = (char*)"vertexShader_M.glsl";
	char* fragmentShader = (char*)"fragmentShader_M.glsl";

	programId = ShaderMaker::createProgram(vertexShader, fragmentShader);
	glUseProgram(programId);
}

void INIT_VAO()
{
	vec4 col_top;
	vec4 col_bottom;
	vec4 col_center;
	vec4 col_radius;

	//Cielo
	Scena->getCielo()->posx = 0.0;
	Scena->getCielo()->posy = float(HEIGHT) / 2;
	Scena->getCielo()->scalex = float(WIDTH);
	Scena->getCielo()->scaley = float(HEIGHT) / 2;
	costruisci_cielo(Scena->getCielo(), giorno_cielo_bottom, giorno_cielo_top);
	crea_VAO_Vector(Scena->getCielo());
	
	//Prato
	Scena->getPrato()->posx = 0.0;
	Scena->getPrato()->posy = 0.0;
	Scena->getPrato()->scalex = float(WIDTH);
	Scena->getPrato()->scaley = float(HEIGHT) / 2;
	costruisci_prato(Scena->getPrato(), giorno_prato_bottom, giorno_prato_top);
	crea_VAO_Vector(Scena->getPrato());
	
	//Sole
	Scena->getSole()->posx = float(WIDTH) * 0.5;
	Scena->getSole()->posy = float(HEIGHT) * 0.8;
	Scena->getSole()->scalex = 30.0;
	Scena->getSole()->scaley =30.0;
	Scena->getSole()->nTriangles = 40;
	costruisci_sole(Scena->getSole(), sole_bottom, sole_top, sole_radius, sole_center);
	crea_VAO_Vector(Scena->getSole());
	
	//Goccia Acqua
	Scena->getGoccia()->posx = float(WIDTH) * 0.5;
	Scena->getGoccia()->posy = float(HEIGHT) * 0.8;
	Scena->getGoccia()->scalex = 5.0;
	Scena->getGoccia()->scaley = 5.0;
	Scena->getGoccia()->nTriangles = 40;
	costruisci_goccia(Scena->getGoccia(), acqua);
	crea_VAO_Vector(Scena->getGoccia());

	/*
	//Goccia Diserbante
	costruisci_goccia(Scena->getGoccia(), diserbante);
	crea_VAO_Vector(Scena->getGoccia());
	*/
	

	//Seme
	Scena->getSeme()->posx = float(WIDTH) * 0.902;
	Scena->getSeme()->posy = float(HEIGHT) * 0.2;
	Scena->getSeme()->scalex = 5.0;
	Scena->getSeme()->scaley = 5.0;
	Scena->getSeme()->nTriangles = 40;
	costruisci_seme(Scena->getSeme(), seme);
	crea_VAO_Vector(Scena->getSeme());

	//Fontana
	Scena->getFontana()->posx = float(WIDTH) * 0.1;
	Scena->getFontana()->posy = float(HEIGHT) * 0.2;
	Scena->getFontana()->scalex = 30.0;
	Scena->getFontana()->scaley = 40.0;
	costruisci_fontana(Scena->getFontana(), fontana_top, fontana_bot);
	crea_VAO_Vector(Scena->getFontana());

	//Fungo
	Scena->getFungo()->posx = float(WIDTH) * 0.8;
	Scena->getFungo()->posy = float(HEIGHT) * 0.2;
	Scena->getFungo()->scalex = 8.0;
	Scena->getFungo()->scaley = 8.0;
	costruisci_fungo(Scena->getFungo(), fungo_top, fungo_bot);
	crea_VAO_Vector(Scena->getFungo());
	
	//OMINO
	//Testa
	Scena->getTesta()->posx = float(WIDTH) * 0.5;
	Scena->getTesta()->posy = float(HEIGHT) * 0.5;
	Scena->getTesta()->scalex = 30.0;
	Scena->getTesta()->scaley = 30.0;
	Scena->getTesta()->nTriangles = 40;
	costruisci_cerchio(Scena->getTesta(), pelle_omino_giorno);
	crea_VAO_Vector(Scena->getTesta());
	Scena->Steve.push_back(Scena->getTesta());

	Scena->getOcchio()->posx = float(WIDTH) * 0.51;
	Scena->getOcchio()->posy = float(HEIGHT) * 0.51;
	Scena->getOcchio()->scalex = 5.0;
	Scena->getOcchio()->scaley = 5.0;
	Scena->getOcchio()->nTriangles = 40;
	costruisci_cerchio(Scena->getOcchio(), occhio_omino_giorno);
	crea_VAO_Vector(Scena->getOcchio());
	Scena->Steve.push_back(Scena->getOcchio());

	Scena->getBocca()->posx = float(WIDTH) * 0.51;
	Scena->getBocca()->posy = float(HEIGHT) * 0.48;
	Scena->getBocca()->scalex = 10.0;
	Scena->getBocca()->scaley = 3.0;
	costruisci_rettangolo(Scena->getBocca(), occhio_omino_giorno);
	crea_VAO_Vector(Scena->getBocca());
	Scena->Steve.push_back(Scena->getBocca());


	//Gambe
	Scena->getGambadx()->posx = float(WIDTH) * 0.50;
	Scena->getGambadx()->posy = float(HEIGHT) * 0.31;
	Scena->getGambadx()->scalex = 24.0;
	Scena->getGambadx()->scaley = 20.0;
	costruisci_gambe(Scena->getGambadx(), gambe_omino_giorno);
	crea_VAO_Vector(Scena->getGambadx());

	Scena->Steve.push_back(Scena->getGambadx());
	
	Scena->getGambasx()->posx = float(WIDTH) * 0.50;
	Scena->getGambasx()->posy = float(HEIGHT) * 0.31;
	Scena->getGambasx()->scalex = 24.0;
	Scena->getGambasx()->scaley = 20.0;
	costruisci_gambe(Scena->getGambasx(), gambe_omino_giorno);
	crea_VAO_Vector(Scena->getGambasx());
	Scena->Steve.push_back(Scena->getGambasx());
	
	//Corpo
	Scena->getCorpo()->posx = float(WIDTH) * 0.48;
	Scena->getCorpo()->posy = float(HEIGHT) * 0.295;
	Scena->getCorpo()->scalex = 50.0;
	Scena->getCorpo()->scaley = 120.0;
	costruisci_rettangolo(Scena->getCorpo(), corpo_omino_giorno);
	crea_VAO_Vector(Scena->getCorpo());
	Scena->Steve.push_back(Scena->getCorpo());

	//Secchio
	Scena->getSecchio()->posx = float(WIDTH) * 0.481;
	Scena->getSecchio()->posy = float(HEIGHT) * 0.32;
	Scena->getSecchio()->scalex = 15.0;
	Scena->getSecchio()->scaley = 20.0;
	Scena->getManico()->posx = float(WIDTH) * 0.481;
	Scena->getManico()->posy = float(HEIGHT) * 0.32;
	Scena->getManico()->scalex = 15.0;
	Scena->getManico()->scaley = 20.0;
	costruisci_secchio(Scena->getSecchio(), Scena->getManico(), secchio_omino_giorno, manico_secchio_giorno);
	crea_VAO_Vector(Scena->getSecchio());
	crea_VAO_Vector(Scena->getManico());
	Scena->Steve.push_back(Scena->getSecchio());
	Scena->Steve.push_back(Scena->getManico());

	//Braccio
	Scena->getBraccio()->posx = float(WIDTH) * 0.5;
	Scena->getBraccio()->posy = float(HEIGHT) * 0.39;
	Scena->getBraccio()->scalex = 11.0;
	Scena->getBraccio()->scaley = 40.0;
	Scena->getBraccio()->nTriangles = 40;
	costruisci_cerchio(Scena->getBraccio(), pelle_omino_giorno);
	crea_VAO_Vector(Scena->getBraccio());
	Scena->Steve.push_back(Scena->getBraccio());


	//Costruzione della matrice di Proiezione
	Projection = ortho(0.0f, float(WIDTH), 0.0f, float(HEIGHT));
	MatProj = glGetUniformLocation(programId, "Projection");
	MatModel = glGetUniformLocation(programId, "Model");
	// Da vedere in base a ciò che andiamo a disegnare

	lsceltavs = glGetUniformLocation(programId, "sceltaVS");
	
	loc_time = glGetUniformLocation(programId, "time");

	loc_res = glGetUniformLocation(programId, "res");
}

void drawScene(void) 
{

	float time = glutGet(GLUT_ELAPSED_TIME);
	glUniform1f(loc_time, time);
	/*glClearColor(0.0, 0.0, 0.0, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glUniformMatrix4fv(MatProj, 1, GL_FALSE, value_ptr(Projection));
	*/
	glUniform2f(loc_res, WIDTH, HEIGHT);


	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glUniformMatrix4fv(MatProj, 1, GL_FALSE, value_ptr(Projection));


	//Disegno Cielo
	Scena->getCielo()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getCielo()->sceltaVS);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getCielo()->Model));
	glBindVertexArray(Scena->getCielo()->VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Scena->getCielo()->nv);
	glBindVertexArray(0);

	//Disegna Prato
	Scena->getPrato()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getPrato()->sceltaVS);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getPrato()->Model));
	glBindVertexArray(Scena->getPrato()->VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Scena->getPrato()->nv);
	glBindVertexArray(0);

	
	//Disegno Sole
	Scena->getSole()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getSole()->sceltaVS);
	glBindVertexArray(Scena->getSole()->VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getSole()->Model));
	//Disegna Alone Luminoso
	glDrawArrays(GL_TRIANGLE_FAN, (Scena->getSole()->nTriangles) + 2, (Scena->getSole()->nTriangles) + 2);
	//Disegna Corpo centrale del sole	  
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Scena->getSole()->nTriangles) + 2);
	glBindVertexArray(0);


	/*Disegno Goccia
	glBindVertexArray(Goccia.VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getGoccia()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Scena->getGoccia()->nTriangles) + 2);
	glBindVertexArray(0);
	*/
	
	//Disegno Seme
	Scena->getSole()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getSeme()->sceltaVS);
	glBindVertexArray(Scena->getSeme()->VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getSeme()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Scena->getSeme()->nTriangles) + 2);
	glBindVertexArray(0);
	
	
	
	//Disegno Stelo
	Scena->getStelo()->sceltaVS = 1;
	glUniform1i(lsceltavs, Scena->getStelo()->sceltaVS);
	glBindVertexArray(Scena->getStelo()->VAO);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getStelo()->Model));
	//glDrawArrays(GL_LINE_STRIP, Scena->getStelo()->nv - 4, 4);
	glLineWidth(5.0);
	glDrawArrays(GL_LINE_STRIP,0, (Scena->getStelo()->nTriangles) + 1);

	
	//Disegna Fiore
	for (int i = 0; i < 8; i++) {
		Scena->getPetalo()->sceltaVS = 0;
		glUniform1i(lsceltavs, Scena->getPetalo()->sceltaVS);
		glBindVertexArray(Scena->getPetalo()->VAO);
		Scena->getPetalo()->Model = rotate(Scena->getPetalo()->Model, radians((float)(45.0*i)), vec3(0.0, 0.0, 1.0));
		glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getPetalo()->Model));
		glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->getPetalo()->nv - 1);
	}
	Scena->getPistillo()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getPistillo()->sceltaVS);
	glBindVertexArray(Scena->getPistillo()->VAO);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getPistillo()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Scena->getPistillo()->nTriangles) + 2);
	

	//Disegna Fontana
	Scena->getFontana()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getFontana()->sceltaVS);
	glBindVertexArray(Scena->getFontana()->VAO);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getFontana()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->getFontana()->nv - 1);

	/*Disegna Ombra
	glDrawArrays(GL_TRIANGLE_FAN, (Palla.nTriangles) + 2, (Palla.nTriangles) + 2);

	*/

	//Disegna Fungo
	Scena->getFungo()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getFungo()->sceltaVS);
	glBindVertexArray(Scena->getFungo()->VAO);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getFungo()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->getFungo()->nv - 1);

	//Disegna Omino
	for (int i = 0; i < Scena->Steve.size(); i++) {
		Scena->Steve[i]->sceltaVS = 0;
		//Scena->Steve[i]->Model = rotate(Scena->Steve[i]->Model, radians((float)(180.0)), vec3(0.0, 1.0, 0.0));
		glUniform1i(lsceltavs, Scena->Steve[i]->sceltaVS);
		glBindVertexArray(Scena->Steve[i]->VAO);
		Scena->Steve[i]->Model = mat4(1.0);
		Scena->Steve[i]->Model = translate(Scena->Steve[i]->Model, vec3(Scena->Steve[i]->posx, Scena->Steve[i]->posy, 0.0));
		Scena->Steve[i]->Model = scale(Scena->Steve[i]->Model, vec3(Scena->Steve[i]->scalex, Scena->Steve[i]->scaley, 1.0));
		if (i == 3 || i == 4)
		{
			Scena->Steve[i]->Model = rotate(Scena->Steve[i]->Model, radians((float)(angolo)), vec3(0.0, 1.0, 0.0));
		}
		if (i == 3 && moving)
		{
			Scena->Steve[i]->Model = rotate(Scena->Steve[i]->Model, radians((float)(angolodx)), vec3(Scena->Steve[i]->rotatex, Scena->Steve[i]->rotatey, Scena->Steve[i]->rotatez));
		}
		if (i == 4 && moving)
		{
			Scena->Steve[i]->Model = rotate(Scena->Steve[i]->Model, radians((float)(angolosx)), vec3(Scena->Steve[i]->rotatex, Scena->Steve[i]->rotatey, Scena->Steve[i]->rotatez));
		}

		glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->Steve[i]->Model));
		if (Scena->Steve[i]->line) {
			glLineWidth(5.0);
			glDrawArrays(GL_LINE_STRIP, 0, Scena->Steve[i]->nv);
		}
		else {
			glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->Steve[i]->nv - 1);
		}
	}
	glBindVertexArray(0);
	glutSwapBuffers();
	glutPostRedisplay();


}

void resize(GLsizei w, GLsizei h) {

	float AspectRatio_mondo = (float)(WIDTH) / (float)(HEIGHT);

	if (AspectRatio_mondo > w / h) //Se l'aspect ratio del mondo è diversa da quella della finestra devo mappare in modo diverso per evitare distorsioni del disegno
	{
		glViewport(0, 0, w, w / AspectRatio_mondo);
	}
	else {
		glViewport(0, 0, h * AspectRatio_mondo, h);
	}
	glutPostRedisplay();
}



int main(int argc, char* argv[])
{
	// Initial setting
	glutInit(&argc, argv);

	glutInitContextVersion(4, 0);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// Display setting
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Daisy 'n' Steve");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);




	// Inserimento periferiche esterne usate
	// Gestione tastiera 
	glutKeyboardFunc(keyboardPressedEvent);
	glutTimerFunc(66, update, 0);
	// Da capire questo punto
	glewExperimental = GL_TRUE;
	glewInit();
	INIT_SHADER();
	INIT_VAO();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutMainLoop();

	/* Da vedere se inserire o meno, probabilmente si
	//Inizializza il VAO per il testo
	INIT_VAO_Text();
	//Inizializza la libreria per la gestione del testo
	Init_Freetype();
	//Elimina le superfici nascoste
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Chiedo che mi venga restituito l'identificativo della variabile uniform mat4 Projection (in vertex shader).
	//QUesto identificativo sarà poi utilizzato per il trasferimento della matrice Projection al Vertex Shader
	MatrixProj = glGetUniformLocation(programId, "Projection");
	//Chiedo che mi venga restituito l'identificativo della variabile uniform mat4 Model (in vertex shader)
	//QUesto identificativo sarà poi utilizzato per il trasferimento della matrice Model al Vertex Shader
	MatModel = glGetUniformLocation(programId, "Model");
	//Chiedo che mi venga restituito l'identificativo della variabile uniform mat4 View (in vertex shader)
	//QUesto identificativo sarà poi utilizzato per il trasferimento della matrice View al Vertex Shader
	MatView = glGetUniformLocation(programId, "View");

	*/
}

