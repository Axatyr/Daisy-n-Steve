#ifndef FIGURA_H
#define FIGURA_H

#include "Lib.h"
class Figura
{
public:

	GLuint VAO;
	GLuint VBO_G;
	GLuint VBO_C;
	GLuint EBO_indici;
	int nTriangles;
	// Vertici
	vector<vec3> vertici;
	// Vertici di controllo delle curve
	vector<vec3> CP;
	vector<vec4> colors;
	vector<vec4> colCP;
	vector<int> indici;
	// Numero vertici
	int nv;
	// Gestione posizione
	float posx;
	float posy;
	// Gestione scalatura
	float scalex;
	float scaley;
	// Gestione rotazione
	float rotatex = 0.0;
	float rotatey = 0.0;
	float rotatez = 0.0;
	// Attributo per linee
	bool line = false;
	// Matrice di Modellazione: Traslazione*Rotazione*Scala
	mat4 Model;
	int sceltaVS;
	int sceltaFS;
	string name;

protected:

private:
	
};

#endif
