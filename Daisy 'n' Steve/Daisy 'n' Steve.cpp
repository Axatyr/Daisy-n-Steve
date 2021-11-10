// Daisy 'n' Steve.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include "Lib.h"

static unsigned int programId;

void INIT_SHADER(void)
{
	GLenum ErrorCheckValue = glGetError();

	char* vertexShader = (char*)"vertexShader_M.glsl";
	char* fragmentShader = (char*)"fragmentShader_M.glsl";

	programId = ShaderMaker::createProgram(vertexShader, fragmentShader);
	glUseProgram(programId);
}

void INIT_VAO(void) 
{
    // Da vedere in base a ciò che andiamo a disegnare
}

void drawScene(void) 
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Da vedere come implementare
}

void resize(GLsizei w, GLsizei h) {

	float AspectRatio_mondo = (float)(width) / (float)(height);

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

void mykeyboard(unsigned char key, int x, int y))
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
	glutInitWindowSize(width, height);
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

