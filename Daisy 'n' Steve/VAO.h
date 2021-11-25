#ifndef VAO_H
#define VAO_H

#include "Figura.h"
#include "Hermite.h"

extern float angolodx;
extern float angolosx;
extern float angolo;

void crea_VAO_Vector(Figura* fig);

void crea_VAO_CP(Figura* fig);

void costruisci_cielo(Figura* cielo, vec4 color_bot, vec4 color_top);

void modifica_cielo(Figura* cielo, vec4 color_bot, vec4 color_top);

void costruisci_prato(Figura* prato, vec4 color_bot, vec4 color_top);

void modifica_prato(Figura* prato, vec4 color_bot, vec4 color_top);

void costruisci_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone);

void modifica_sole(Figura* sole, vec4 color_radius, vec4 color_center, vec4 color_radius_alone, vec4 color_center_alone);

void costruisci_goccia(Figura* goccia, vec4 colore);

void costruisci_seme(Figura* seme, vec4 colore);

void costruisci_stelo(Figura* stelo, vec4 stelo_top);

void costruisci_fontana(Figura* fontana, vec4 fontana_top, vec4 fontana_bot);

void costruisci_fungo(Figura* fungo, vec4 fungo_top, vec4 fungo_bot);

void costruisci_petalo(Figura* petalo, vec4 petalo_top, vec4 petalo_bot);

void costruisci_cerchio(Figura* testa, vec4 colore_testa);

void costruisci_rettangolo(Figura* rettangolo, vec4 color_rettangolo);

void costruisci_secchio(Figura* secchio, Figura* manico, vec4 color_secchio, vec4 color_manico);

void costruisci_gambe(Figura* gamba, vec4 color_gamba);

void ruota_omino(vector<Figura*> omino, bool destra);

#endif