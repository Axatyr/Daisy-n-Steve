// Daisy 'n' Steve.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include <iostream>
#include "Lib.h"
#include "ShaderMaker.h"
#include "GestioneEventi.h"
#include "Figura.h"
#include "VAO.h"

static unsigned int programId;

mat4 Projection;
GLuint MatProj, MatModel;
int nv_P;

Figura Cielo = {};
Figura Prato = {};
Figura Sole = {};
Figura Luna = {};


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

	//Cielo
	vec4 col_top = { 0.6471, 0.3020,1.0,1.0 };
	vec4 col_bottom = { 0.0, 0.4980,1.0,1.0 };
	costruisci_cielo(&Cielo, col_top, col_bottom);
	crea_VAO_Vector(&Cielo);

	//Prato
	col_top = vec4{ 0.1333, 0.5451, 0.1333, 1.0000 };
	col_bottom = vec4{ 0.6784, 1.0,0.1843, 1.0000 };
	costruisci_prato(&Prato, col_top, col_bottom);
	crea_VAO_Vector(&Prato);

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
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Cielo.Model));
	glBindVertexArray(Cielo.VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Cielo.nv);
	glBindVertexArray(0);


	//Disegno Sole
	glBindVertexArray(Sole.VAO);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Sole.Model));
	//Disegna Alone Luminoso
	glDrawArrays(GL_TRIANGLE_FAN, (Sole.nTriangles) + 2, (Sole.nTriangles) + 2);
	//Disegna Corpo centrale del sole	  
	glDrawArrays(GL_TRIANGLE_FAN, 0, (Sole.nTriangles) + 2);
	glBindVertexArray(0);

	/*Disegna Montagne
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Montagna.Model));
	glBindVertexArray(Montagna.VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Montagna.nv);
	glBindVertexArray(0); */

	//Disegna Prato
	glUniformMatrix4fv(MatModel, 1, GL_FALSE, value_ptr(Prato.Model));
	glBindVertexArray(Prato.VAO);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, Prato.nv);
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

void mouse(int button, int state, int x, int y)
{

}

void mykeyboard(unsigned char key, int x, int y)
{

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
	// Da guardare le funzioni in quanto andranno spostate tutte nella gestione eventi
	// Sistemare gestione mouse
	glutMouseFunc(mouse);
	//glutMotionFunc(mouseMotion);
	// Sistemare gestione tastiera 
	glutKeyboardFunc(mykeyboard);
	//glutKeyboardFunc(keyboardPressedEvent);

	// Da capire questo punto
	glewExperimental = GL_TRUE;
	glewInit();
	INIT_SHADER();
	INIT_VAO();
	// da vedere se ci vuole
	//createMenu();
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

