#include"Figura.h"

#define  PI   3.14159265358979323846


void costruisci_cielo(Figura* cielo, vec4 color_bot, vec4 color_top)
{
	//Inserimento vertici e colori
	cielo->vertici.push_back(vec3(0.0, 0.0, 0.0));
	cielo->colors.push_back(vec4(color_bot.r, color_bot.g, color_bot.b, color_bot.a));
	cielo->vertici.push_back(vec3(1.0, 0.0, 0.0));
	cielo->colors.push_back(vec4(color_bot.r, color_bot.g, color_bot.b, color_bot.a));
	cielo->vertici.push_back(vec3(0.0, 1.0, 0.0));
	cielo->colors.push_back(vec4(color_top.r, color_top.g, color_top.b, color_top.a));
	cielo->vertici.push_back(vec3(1.0, 1.0, 0.0));
	cielo->colors.push_back(vec4(color_top.r, color_top.g, color_top.b, color_top.a));

	cielo->nv = cielo->vertici.size();

	//Costruzione matrice di modellazione
	cielo->Model = mat4(1.0);
	cielo->Model = translate(cielo->Model, vec3(0.0, float(720) / 2, 0.0));
	cielo->Model = scale(cielo->Model, vec3(float(WIDTH), float(HEIGHT) / 2, 1.0));
}

void costruisci_prato(Figura* prato, vec4 color_bot, vec4 color_top)
{
	//Inserimento vertici e colori
	prato->vertici.push_back(vec3(0.0, 0.0, 0.0));
	prato->colors.push_back(vec4(color_top.r, color_top.g, color_top.b, color_top.a));
	prato->vertici.push_back(vec3(0.0, 1.0, 0.0));
	prato->colors.push_back(vec4(color_top.r, color_top.g, color_top.b, color_top.a));
	prato->vertici.push_back(vec3(1.0, 0.0, 0.0));
	prato->colors.push_back(vec4(color_top.r, color_top.g, color_top.b, color_top.a));
	prato->vertici.push_back(vec3(1.0, 1.0, 0.0));
	prato->colors.push_back(vec4(color_bot.r, color_bot.g, color_bot.b, color_bot.a));

	prato->nv = prato->vertici.size();

	//Costruzione matrice di Modellazione
	prato->Model = mat4(1.0);
	prato->Model = scale(prato->Model, vec3(float(WIDTH), float(HEIGHT) / 2, 1.0));
}

void costruisci_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone)
{
	int i;
	float stepA = (2 * PI) / sole->nTriangles;
	float t;


	sole->vertici.push_back(vec3(0.0, 0.0, 0.0));
	sole->colors.push_back(vec4(color_center.r, color_center.g, color_center.b, color_center.a));

	for (i = 0; i <= sole->nTriangles; i++)
	{
		t = (float)i * stepA;

		sole->vertici.push_back(vec3(cos(t), sin(t), 0.0));
		sole->colors.push_back(vec4(color_radius.r, color_radius.g, color_radius.b, color_radius.a));
	}

	//Costruzione Alone
	sole->vertici.push_back(vec3(0.0, 0.0, 0.0));
	sole->colors.push_back(vec4(color_center_alone.r, color_center_alone.g, color_center_alone.b, color_center_alone.a));
	for (i = 0; i <= sole->nTriangles; i++)
	{
		t = (float)i * stepA;

		sole->vertici.push_back(vec3(2.0 * cos(t), 2.0 * sin(t), 0.0));
		sole->colors.push_back(vec4(color_radius_alone.r, color_radius_alone.g, color_radius_alone.b, color_radius_alone.a));

	}


	sole->nv = sole->vertici.size();

	//Costruzione matrice di Moellazione	
	sole->Model = mat4(1.0);
	sole->Model = translate(sole->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.8, 0.0));
	sole->Model = scale(sole->Model, vec3(30.0, 30.0, 1.0));

}

void costruisci_goccia(Figura* goccia) {
	int i;
	float stepA = (2 * PI) / goccia->nTriangles;
	float t;

	goccia->vertici.push_back(vec3(0.0, 0.0, 0.0));
	goccia->colors.push_back(vec4(0.0, 128.0/255.0, 1.0, 1.0));

	for (i = 0; i <= goccia->nTriangles; i++) {

		t = (float)i * stepA;
		goccia->vertici.push_back(vec3(cos(t), sin(t), 0.0));
		goccia->colors.push_back(vec4(0.0, 128.0/255.0, 1.0, 1.0));
	}

	goccia->nv = goccia->vertici.size();

	//Costruzione matrice di Moellazione	
	goccia->Model = mat4(1.0);
	goccia->Model = translate(goccia->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.8, 0.0));
	goccia->Model = scale(goccia->Model, vec3(5.0, 5.0, 1.0));
}

void costruisci_seme(Figura* seme) {
	int i;
	float stepA = (2 * PI) / seme->nTriangles;
	float t;
	for (i = 0; i <= seme->nTriangles; i++) {

		t = (float)i * stepA;
		seme->vertici.push_back(vec3(2.0*cos(t), sin(t), 0.0));
		seme->colors.push_back(vec4(1.0, 1.0, 0.0, 1.0));
	}

	seme->nv = seme->vertici.size();

	//Costruzione matrice di Moellazione	
	seme->Model = mat4(1.0);
	seme->Model = translate(seme->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.2, 0.0));
	seme->Model = scale(seme->Model, vec3(5.0, 5.0, 1.0));
}

void costruisci_stelo(Figura* stelo) {
	int i;
	for (i = 0; i <= stelo->nTriangles; i++) {
		stelo->vertici.push_back(vec3((float)i, sin(i), 0.0));
		stelo->colors.push_back(vec4(1.0, 0.0, 0.0, 1.0));
	}

	stelo->nv = stelo->vertici.size();

	//Costruzione matrice di Moellazione	
	stelo->Model = mat4(1.0);
	stelo->Model = translate(stelo->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.2, 0.0));
	stelo->Model = scale(stelo->Model, vec3(5.0, 5.0, 1.0));
}

void costruisci_fiore(Figura* fiore)
{
	int i;
	float stepA = (2 * PI) / fiore->nTriangles;
	float t;


	fiore->vertici.push_back(vec3(0.0, 0.0, 0.0));
	fiore->colors.push_back(vec4(0.0,0.0,0.0,1.0));

	for (i = 0; i <= fiore->nTriangles; i++)
	{
		t = (float)i * stepA;
		if (i % 2 == 0) {
			fiore->vertici.push_back(vec3(cos(t) * 0.5, sin(t) * 0.5, 0.0));
		}
		else {
			fiore->vertici.push_back(vec3(cos(t) * 0.25, sin(t) * 0.25, 0.0));
			
		}
		fiore->colors.push_back(vec4(0.0, 0.0, 0.0, 1.0));
	}
		fiore->nv = fiore->vertici.size();
		fiore->Model = mat4(1.0);
		fiore->Model = translate(fiore->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.2, 0.0));
		fiore->Model = scale(fiore->Model, vec3(30.0, 30.0, 1.0));

}


void costruisci_fontata(Figura* fig);

void costruisci_erbaccia(Figura* fig);
