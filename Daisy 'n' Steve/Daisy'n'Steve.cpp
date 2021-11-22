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
	
	//Goccia Acqua
	Scena->getGoccia()->nTriangles = 40;
	costruisci_goccia(Scena->getGoccia(), acqua);
	crea_VAO_Vector(Scena->getGoccia());

	/*
	//Goccia Diserbante
	costruisci_goccia(Scena->getGoccia(), diserbante);
	crea_VAO_Vector(Scena->getGoccia());
	*/
	

	//Seme
	Scena->getSeme()->nTriangles = 40;
	costruisci_seme(Scena->getSeme(), seme);
	crea_VAO_Vector(Scena->getSeme());

	//Stelo
	Scena->getStelo()->nTriangles = 40;
	costruisci_stelo(Scena->getStelo(), stelo_top, stelo_bot);
	crea_VAO_Vector(Scena->getStelo());

	//Fontana
	costruisci_fontana(Scena->getFontana(), fontana_top, fontana_bot);
	crea_VAO_Vector(Scena->getFontana());

	//Fungo
	costruisci_fungo(Scena->getFungo(), fungo_top, fungo_bot);
	crea_VAO_Vector(Scena->getFungo());
	
	//Petalo
	costruisci_petalo(Scena->getPetalo(), fiore_top, fiore_bot);
	crea_VAO_Vector(Scena->getPetalo());
	

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
		Scena->getPetalo()->Model = mat4(1.0);
		Scena->getPetalo()->Model = translate(Scena->getPetalo()->Model, vec3(float(WIDTH) * 0.9, float(HEIGHT) * 0.35, 0.0));
		Scena->getPetalo()->Model = scale(Scena->getPetalo()->Model, vec3(8.0, 8.0, 1.0));
		Scena->getPetalo()->Model = rotate(Scena->getPetalo()->Model, radians((float)(45.0*i)), vec3(0.0, 0.0, 1.0));
		glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getPetalo()->Model));
		glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->getPetalo()->nv - 1);
	}
	

	//Disegna Fontana
	Scena->getFontana()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getFontana()->sceltaVS);
	glBindVertexArray(Scena->getFontana()->VAO);
	Scena->getFontana()->Model = mat4(1.0);
	Scena->getFontana()->Model = translate(Scena->getFontana()->Model, vec3(float(WIDTH) * 0.1, float(HEIGHT) * 0.2, 0.0));
	Scena->getFontana()->Model = scale(Scena->getFontana()->Model, vec3(20.0, 20.0, 1.0));
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getFontana()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->getFontana()->nv - 1);

	/*Disegna Ombra
	glDrawArrays(GL_TRIANGLE_FAN, (Palla.nTriangles) + 2, (Palla.nTriangles) + 2);

	*/

	//Disegna Fungo
	Scena->getFungo()->sceltaVS = 0;
	glUniform1i(lsceltavs, Scena->getFungo()->sceltaVS);
	glBindVertexArray(Scena->getFungo()->VAO);
	Scena->getFungo()->Model = mat4(1.0);
	Scena->getFungo()->Model = translate(Scena->getFungo()->Model, vec3(float(WIDTH) * 0.8, float(HEIGHT) * 0.2, 0.0));
	Scena->getFungo()->Model = scale(Scena->getFungo()->Model, vec3(8.0, 8.0, 1.0));
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Scena->getFungo()->Model));
	glDrawArrays(GL_TRIANGLE_FAN, 0, Scena->getFungo()->nv - 1);

	
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
	glutTimerFunc(66, update, 0);
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

