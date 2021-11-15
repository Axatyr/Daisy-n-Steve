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

void costruisci_fontata(Figura* fig);

void costruisci_erbaccia(Figura* fig);
