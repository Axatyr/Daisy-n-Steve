// Daisy 'n' Steve.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

#include <iostream>
#include "Lib.h"
#include "ShaderMaker.h"
#include "GestioneEventi.h"
#include "Figura.h"
#include "Elementi.h"
#include "VAO.h"

static unsigned int programId;

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
	costruisci_cielo(Scena->getCielo(), giorno_cielo_bottom, giorno_cielo_top);
	crea_VAO_Vector(Scena->getCielo());
	
	//Prato
	costruisci_prato(Scena->getPrato(), giorno_prato_bottom, giorno_prato_top);
	crea_VAO_Vector(Scena->getPrato());
	
	//Sole
	Scena->getSole()->nTriangles = 40;
	costruisci_sole(Scena->getSole(), sole_bottom, sole_top, sole_radius, sole_center);
	crea_VAO_Vector(Scena->getSole());
	
	/*Da guardare perchè se la tieni tonda alla fine basta cambiare i colori al sole e siamo a posto quando si fa il giorno/notte
	se cambi forma invece mi basta cancellare il sole e mettere la luna e viceversa, scegli tu*/
	//Luna
	Scena->getLuna()->nTriangles = 40;
	col_top = vec4{ 1.0, 248.0/255.0, 220.0/255.0, 0.8 };
	col_bottom = vec4{ 1.0, 250.0 / 255.0, 205.0/255.0, 1.0 };
	col_center = vec4{ 1.0, 248.0/255.0, 220.0/255.0, 0.0 };
	col_radius = vec4{ 1.0, 250.0 / 255.0, 205.0 / 255.0, 1.0 };
	costruisci_sole(Scena->getSole(), col_bottom, col_top, col_radius, col_center);
	crea_VAO_Vector(Scena->getSole());
	/*
	//Goccia
	Goccia.nTriangles = 40;
	costruisci_goccia(&Goccia);
	crea_VAO_Vector(&Goccia);

	//Seme
	Seme.nTriangles = 40;
	costruisci_seme(&Seme);
	crea_VAO_Vector(&Seme);

	//Stelo
	Stelo.nTriangles = 40;
	costruisci_stelo(&Stelo);
	crea_VAO_Vector(&Stelo);

	//Fiore
	Fiore.nTriangles = 40;
	costruisci_fiore(&Fiore);
	crea_VAO_Vector(&Fiore);
	*/
	//Costruzione della matrice di Proiezione
	Projection = ortho(0.0f, float(WIDTH), 0.0f, float(HEIGHT));
	MatProj = glGetUniformLocation(programId, "Projection");
	MatModel = glGetUniformLocation(programId, "Model");
	// Da vedere in base a ciò che andiamo a disegnare
	
}

void drawScene(void) 
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glUniformMatrix4fv(MatProj, 1, GL_FALSE, value_ptr(Projection));

	//Disegno Cielo
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getCielo()->Model));
	glBindVertexArray(Scena->getCielo()->VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Scena->getCielo()->nv);
	glBindVertexArray(0);

	//Disegna Prato
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getPrato()->Model));
	glBindVertexArray(Scena->getPrato()->VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Scena->getPrato()->nv);
	glBindVertexArray(0);

	
	//Disegno Sole
	glBindVertexArray(Scena->getSole()->VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getSole()->Model));
	//Disegna Alone Luminoso
	glDrawArrays(GL_TRIANGLE_FAN, (Scena->getSole()->nTriangles) + 2, (Scena->getSole()->nTriangles) + 2);
	//Disegna Corpo centrale del sole	  
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Scena->getSole()->nTriangles) + 2);
	glBindVertexArray(0);

	/*Disegna Montagne
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Montagna.Model));
	glBindVertexArray(Montagna.VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Montagna.nv);
	glBindVertexArray(0); */


	/*Disegno Goccia
	glBindVertexArray(Goccia.VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Goccia.Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Goccia.nTriangles) + 2);
	glBindVertexArray(0);
	*/
	/*
	//Disegno Seme
	glBindVertexArray(Seme.VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Seme.Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Seme.nTriangles) + 2);
	glBindVertexArray(0);
	*/
	
	/*
	//Disegno Stelo
	glBindVertexArray(Stelo.VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Stelo.Model));
	glDrawArrays(GL_LINE_STRIP, 0, (Stelo.nTriangles) + 2);
	glBindVertexArray(0);*/
	/*
	//Disegna Fiore
	glBindVertexArray(Fiore.VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Fiore.Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Fiore.nTriangles) + 2);
	glBindVertexArray(0);

	/*Disegna Ombra
	glDrawArrays(GL_TRIANGLE_FAN, (Palla.nTriangles) + 2, (Palla.nTriangles) + 2);

	*/
	
	glBindVertexArray(0);
	glutSwapBuffers();

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
	setScena(Scena);

	// Da guardare le funzioni in quanto andranno spostate tutte nella gestione eventi
	// Sistemare gestione mouse
	//glutMotionFunc(mouseMotion);
	// Sistemare gestione tastiera 
	glutKeyboardFunc(keyboardPressedEvent);
	

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

