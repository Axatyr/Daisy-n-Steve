#include "VAO.h"

#define  PI 3.14159265358979323846

void crea_VAO_Vector(Figura* fig)
{
	glGenVertexArrays(1, &fig->VAO);
	glBindVertexArray(fig->VAO);
	//Genero , rendo attivo, riempio il VBO della geometria dei vertici
	glGenBuffers(1, &fig->VBO_G);
	glBindBuffer(GL_ARRAY_BUFFER, fig->VBO_G);
	glBufferData(GL_ARRAY_BUFFER, fig->vertici.size() * sizeof(vec3), fig->vertici.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	//Genero , rendo attivo, riempio il VBO dei colori
	glGenBuffers(1, &fig->VBO_C);
	glBindBuffer(GL_ARRAY_BUFFER, fig->VBO_C);
	glBufferData(GL_ARRAY_BUFFER, fig->colors.size() * sizeof(vec4), fig->colors.data(), GL_STATIC_DRAW);
	//Adesso carico il VBO dei colori nel layer 2
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
}

void crea_VAO_CP(Figura* fig)
{
	glGenVertexArrays(1, &fig->VAO);
	glBindVertexArray(fig->VAO);
	//Genero , rendo attivo, riempio il VBO della geometria dei vertici di COntrollo
	glGenBuffers(1, &fig->VBO_G);
	glBindBuffer(GL_ARRAY_BUFFER, fig->VBO_G);
	glBufferData(GL_ARRAY_BUFFER, fig->CP.size() * sizeof(vec3), fig->CP.data(), GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	//Genero , rendo attivo, riempio il VBO dei colori nei vertici di controllo
	glGenBuffers(1, &fig->VBO_C);
	glBindBuffer(GL_ARRAY_BUFFER, fig->VBO_C);
	glBufferData(GL_ARRAY_BUFFER, fig->colCP.size() * sizeof(vec4), fig->colCP.data(), GL_DYNAMIC_DRAW);
	//Adesso carico il VBO dei colori nel layer 2
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);
}

void costruisci_cielo(Figura* cielo, vec4 color_bot, vec4 color_top)
{
	//Inserimento vertici e colori
	cielo->vertici.push_back(vec3(0.0, 0.0, 0.0));
	cielo->colors.push_back(color_bot);
	cielo->vertici.push_back(vec3(1.0, 0.0, 0.0));
	cielo->colors.push_back(color_bot);
	cielo->vertici.push_back(vec3(0.0, 1.0, 0.0));
	cielo->colors.push_back(color_top);
	cielo->vertici.push_back(vec3(1.0, 1.0, 0.0));
	cielo->colors.push_back(color_top);

	cielo->nv = cielo->vertici.size();

	//Costruzione matrice di modellazione
	cielo->Model = mat4(1.0);
	cielo->Model = translate(cielo->Model, vec3(0.0, float(720) / 2, 0.0));
	cielo->Model = scale(cielo->Model, vec3(float(WIDTH), float(HEIGHT) / 2, 1.0));
}

void modifica_cielo(Figura* cielo, vec4 color_bot, vec4 color_top)
{
	cielo->colors[0] = color_bot;
	cielo->colors[1] = color_bot;
	cielo->colors[2] = color_top;
	cielo->colors[3] = color_top;
}

void costruisci_prato(Figura* prato, vec4 color_bot, vec4 color_top)
{
	//Inserimento vertici e colori
	prato->vertici.push_back(vec3(0.0, 0.0, 0.0));
	prato->colors.push_back(color_top);
	prato->vertici.push_back(vec3(0.0, 1.0, 0.0));
	prato->colors.push_back(color_bot);
	prato->vertici.push_back(vec3(1.0, 0.0, 0.0));
	prato->colors.push_back(color_top);
	prato->vertici.push_back(vec3(1.0, 1.0, 0.0));
	prato->colors.push_back(color_bot);

	prato->nv = prato->vertici.size();

	//Costruzione matrice di Modellazione
	prato->Model = mat4(1.0);
	prato->Model = scale(prato->Model, vec3(float(WIDTH), float(HEIGHT) / 2, 1.0));
}

void modifica_prato(Figura* prato, vec4 color_bot, vec4 color_top)
{
	prato->colors[0] = color_top;
	prato->colors[1] = color_bot;
	prato->colors[2] = color_top;
	prato->colors[3] = color_bot;
}

void costruisci_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone)
{
	int i;
	float stepA = (2 * PI) / sole->nTriangles;
	float t;

	sole->vertici.push_back(vec3(0.0, 0.0, 0.0));
	sole->colors.push_back(color_center);

	for (i = 0; i <= sole->nTriangles; i++)
	{
		t = (float)i * stepA;

		sole->vertici.push_back(vec3(cos(t), sin(t), 0.0));
		sole->colors.push_back(color_radius);
	}

	//Costruzione Alone
	sole->vertici.push_back(vec3(0.0, 0.0, 0.0));
	sole->colors.push_back(color_center_alone);
	for (i = 0; i <= sole->nTriangles; i++)
	{
		t = (float)i * stepA;

		sole->vertici.push_back(vec3(2.0 * cos(t), 2.0 * sin(t), 0.0));
		sole->colors.push_back(color_radius_alone);

	}
	sole->nv = sole->vertici.size();

	//Costruzione matrice di Modellazione	
	sole->Model = mat4(1.0);
	sole->Model = translate(sole->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.8, 0.0));
	sole->Model = scale(sole->Model, vec3(30.0, 30.0, 1.0));
}

void modifica_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone)
{
	int i;
	float stepA = (2 * PI) / sole->nTriangles;
	float t;

	for (i = 0; i < sole->nv; i++)
	{
		t = (float)i * stepA;
		if (i == 0)
		{
			sole->colors[i] = color_center;
		}
		else if (i <= (sole->nTriangles + 1))
		{
			sole->colors[i] = color_radius;
		}
		else if (i == (sole->nTriangles + 2))
		{
			sole->colors[i] = color_center_alone;
		}
		else
		{
		sole->colors[i] = color_radius_alone;
		}
	}

	sole->nv = sole->vertici.size();

	//Costruzione matrice di Modellazione	
	sole->Model = mat4(1.0);
	sole->Model = translate(sole->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.8, 0.0));
	sole->Model = scale(sole->Model, vec3(30.0, 30.0, 1.0));
}


void costruisci_goccia(Figura* goccia, vec4 colore) {
	int i;
	float stepA = (2 * PI) / goccia->nTriangles;
	float t;

	goccia->vertici.push_back(vec3(0.0, 0.0, 0.0));
	goccia->colors.push_back(colore);

	for (i = 0; i <= goccia->nTriangles; i++) {

		t = (float)i * stepA;
		goccia->vertici.push_back(vec3(cos(t), sin(t), 0.0));
		goccia->colors.push_back(colore);
	}

	goccia->nv = goccia->vertici.size();

	//Costruzione matrice di Moellazione	
	goccia->Model = mat4(1.0);
	goccia->Model = translate(goccia->Model, vec3(float(WIDTH) * 0.5, float(HEIGHT) * 0.8, 0.0));
	goccia->Model = scale(goccia->Model, vec3(5.0, 5.0, 1.0));
}

void costruisci_seme(Figura* seme, vec4 colore) {
	int i;
	float stepA = (2 * PI) / seme->nTriangles;
	float t;
	for (i = 0; i <= seme->nTriangles; i++) {

		t = (float)i * stepA;
		seme->vertici.push_back(vec3(2.0 * cos(t), sin(t), 0.0));
		seme->colors.push_back(colore);
	}

	seme->nv = seme->vertici.size();

	//Costruzione matrice di Moellazione	
	seme->Model = mat4(1.0);
	seme->Model = translate(seme->Model, vec3(float(WIDTH) * 0.9, float(HEIGHT) * 0.2, 0.0));
	seme->Model = scale(seme->Model, vec3(5.0, 5.0, 1.0));
}

void costruisci_stelo(Figura* stelo, vec4 stelo_top, vec4 stelo_bot) {
	stelo->vertici.push_back(vec3(-0.5, 0.0, 0.0));
	stelo->colors.push_back(stelo_bot);
	stelo->vertici.push_back(vec3(0.0, 0.5, 0.0));
	stelo->colors.push_back(stelo_bot);
	stelo->vertici.push_back(vec3(0.0, 1.0, 0.0));
	stelo->colors.push_back(stelo_top);
	stelo->vertici.push_back(vec3(-0.5, 1.5, 0.0));
	stelo->colors.push_back(stelo_top);
	stelo->vertici.push_back(vec3(-0.5, 2.0, 0.0));
	stelo->colors.push_back(stelo_top);
	stelo->vertici.push_back(vec3(0.0, 2.0, 0.0));
	stelo->colors.push_back(stelo_top);
	stelo->vertici.push_back(vec3(0.0, 1.5, 0.0));
	stelo->colors.push_back(stelo_top);
	stelo->vertici.push_back(vec3(0.5, 1.0, 0.0));
	stelo->colors.push_back(stelo_top);
	stelo->vertici.push_back(vec3(0.5, 0.5, 0.0));
	stelo->colors.push_back(stelo_bot);
	stelo->vertici.push_back(vec3(0.0, 0.0, 0.0));
	stelo->colors.push_back(stelo_bot);
	stelo->vertici.push_back(vec3(-0.5, 0.0, 0.0));
	stelo->colors.push_back(stelo_bot);
	

	stelo->nv = stelo->vertici.size();

	stelo->Model = mat4(1.0);
	stelo->Model = translate(stelo->Model, vec3(float(WIDTH) * 0.9, float(HEIGHT) * 0.2, 0.0));
	stelo->Model = scale(stelo->Model, vec3(10.0, 100.0, 1.0));
}


void costruisci_fontana(Figura* fontana, vec4 fontana_top, vec4 fontana_bot)
{
	float* t;
	fontana->CP.push_back(vec3(0.0, 0.0, 0.0));
	fontana->CP.push_back(vec3(-1.0, 0.0, 0.0));
	fontana->CP.push_back(vec3(-1.0, 2.0, 0.0));
	fontana->CP.push_back(vec3(-1.0, 4.0, 0.0));
	fontana->CP.push_back(vec3(-1.0, 5.0, 0.0));
	fontana->CP.push_back(vec3(0.0, 5.0, 0.0));
	fontana->CP.push_back(vec3(1.0, 5.0, 0.0));
	fontana->CP.push_back(vec3(1.0, 4.0, 0.0));
	fontana->CP.push_back(vec3(2.0, 4.0, 0.0));
	fontana->CP.push_back(vec3(2.0, 3.5, 0.0));
	fontana->CP.push_back(vec3(1.0, 3.5, 0.0));
	fontana->CP.push_back(vec3(1.0, 2.0, 0.0));
	fontana->CP.push_back(vec3(1.0, 1.0, 0.0));
	fontana->CP.push_back(vec3(1.0, 0.0, 0.0));
	fontana->CP.push_back(vec3(0.0, 0.0, 0.0));
	fontana->CP.push_back(vec3(-1.0, 0.0, 0.0));
	fontana->vertici.push_back(vec3(0.0, 2.5, 0.0));

	t = new float[fontana->CP.size()];
	int i;
	float step = 1.0 / (float)(fontana->CP.size() - 1);

	for (i = 0; i < fontana->CP.size(); i++)
	{
		t[i] = i * step;
	}


	InterpolazioneHermite(t, fontana, fontana_top, fontana_bot);
	/*fontana->vertici.push_back(vec3(0.0, 14.0, 0.0));
	fontana->colors.push_back(vec4(1.0, 0.0, 0.0, 1.0));*/
	fontana->nv = fontana->vertici.size();

}

void costruisci_fungo(Figura* fungo, vec4 fungo_top, vec4 fungo_bot) {

	float* t;
	fungo->CP.push_back(vec3(0.0, 0.0, 0.0));
	fungo->CP.push_back(vec3(-1.0, 0.0, 0.0));
	fungo->CP.push_back(vec3(-1.0, 1.0, 0.0));
	fungo->CP.push_back(vec3(-1.0, 2.0, 0.0));
	fungo->CP.push_back(vec3(-2.0, 2.0, 0.0));
	fungo->CP.push_back(vec3(-3.0, 2.0, 0.0));
	fungo->CP.push_back(vec3(-2.0, 4.0, 0.0));
	fungo->CP.push_back(vec3(0.0, 5.0, 0.0));
	fungo->CP.push_back(vec3(2.0, 4.0, 0.0));
	fungo->CP.push_back(vec3(3.0, 2.0, 0.0));
	fungo->CP.push_back(vec3(2.0, 2.0, 0.0));
	fungo->CP.push_back(vec3(1.0, 2.0, 0.0));
	fungo->CP.push_back(vec3(1.0, 1.0, 0.0));
	fungo->CP.push_back(vec3(1.0, 0.0, 0.0));
	fungo->CP.push_back(vec3(0.0, 0.0, 0.0));
	fungo->vertici.push_back(vec3(0.0, 2.5, 0.0));



	t = new float[fungo->CP.size()];
	int i;
	float step = 1.0 / (float)(fungo->CP.size() - 1);

	for (i = 0; i < fungo->CP.size(); i++)
	{
		t[i] = (float)i * step;
	}


	InterpolazioneHermite(t, fungo, fungo_top, fungo_bot);
	/*fontana->vertici.push_back(vec3(0.0, 14.0, 0.0));
	fontana->colors.push_back(vec4(1.0, 0.0, 0.0, 1.0));*/
	fungo->nv = fungo->vertici.size();
}

void costruisci_petalo(Figura* petalo, vec4 petalo_top, vec4 petalo_bot) {
	float* t;
	petalo->CP.push_back(vec3(0.0, -0.5, 0.0));
	petalo->CP.push_back(vec3(-0.5, 0.0, 0.0));
	petalo->CP.push_back(vec3(-0.7, 0.5, 0.0));
	petalo->CP.push_back(vec3(-1.0, 1.0, 0.0));
	petalo->CP.push_back(vec3(-1.4, 2.0, 0.0));
	petalo->CP.push_back(vec3(-1.3, 2.7, 0.0));
	petalo->CP.push_back(vec3(-1.0, 3.5, 0.0));
	petalo->CP.push_back(vec3(-0.4, 3.8, 0.0));
	petalo->CP.push_back(vec3(0.0, 4.0, 0.0));
	petalo->CP.push_back(vec3(0.4, 3.8, 0.0));
	petalo->CP.push_back(vec3(1.0, 3.5, 0.0));
	petalo->CP.push_back(vec3(1.3, 2.7, 0.0));
	petalo->CP.push_back(vec3(1.4, 2.0, 0.0));
	petalo->CP.push_back(vec3(1.0, 1.0, 0.0));
	petalo->CP.push_back(vec3(0.7, 0.5, 0.0));
	petalo->CP.push_back(vec3(0.5, 0.0, 0.0));
	petalo->CP.push_back(vec3(0.0, -0.5, 0.0));
	petalo->vertici.push_back(vec3(0.0, 0.0, 0.0));

	t = new float[petalo->CP.size()];
	int i;
	float step = 1.0 / (float)(petalo->CP.size() - 1);

	for (i = 0; i < petalo->CP.size(); i++)
	{
		t[i] = (float)i * step;
	}


	InterpolazioneHermite(t, petalo, petalo_top, petalo_bot);
	petalo->nv = petalo->vertici.size();
}