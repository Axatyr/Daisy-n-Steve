#ifndef VAO_H
#define VAO_H

#include "Figura.h"

void crea_VAO_Vector(Figura* fig);

void crea_VAO_CP(Figura* fig);

void costruisci_cielo(Figura* cielo, vec4 color_bot, vec4 color_top);

void costruisci_prato(Figura* prato, vec4 color_bot, vec4 color_top);

void costruisci_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone);
/*
void costruisci_goccia(Figura* goccia);

void costruisci_seme(Figura* seme);

void costruisci_fontana(Figura* fig);

void costruisci_erbaccia(Figura* fig);
*/
#endif