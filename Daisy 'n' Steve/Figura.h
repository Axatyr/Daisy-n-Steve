#ifndef FIGURA_H
#define FIGURA_H

#include"Lib.h"

typedef struct {
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
	// Matrice di Modellazione: Traslazione*Rotazione*Scala
	mat4 Model;
	int sceltaVS;
	int sceltaFS;
	string name;
} Figura;

void crea_VAO_Vector(Figura* fig);

void crea_VAO_CP(Figura* fig);

void costruisci_cielo(Figura* cielo, vec4 color_bot, vec4 color_top);

void costruisci_prato(Figura* prato, vec4 color_bot, vec4 color_top);

void costruisci_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone);

void costruisci_luna(Figura* fig);

void costruisci_fontata(Figura* fig);

void costruisci_erbaccia(Figura* fig);




#endif FIGURA_H
