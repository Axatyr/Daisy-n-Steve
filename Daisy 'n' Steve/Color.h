#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Colori Cielo
static vec4 giorno_cielo_top = { 0.6471, 0.3020,1.0,1.0 };
static vec4 giorno_cielo_bottom = { 0.0, 0.4980,1.0,1.0 };
static vec4 notte_cielo_top = { 0.0, 0.0, 50.0/255.0, 1.0 };
static vec4 notte_cielo_bottom = { 0.0, 0.0, 128.0/255.0, 1.0 };

//Colori Prato
static vec4 giorno_prato_bottom = { 0.6784, 1.0,0.1843, 1.0000 };
static vec4 giorno_prato_top = { 0.1333, 0.5451, 0.1333, 1.0000 };
static vec4 notte_prato_bottom = { 0.0, 139.0 / 255.0, 0.0, 1.0 };
static vec4 notte_prato_top = { 0.0, 50.0/255.0, 0.0, 1.0 };

//Colori Sole
static vec4 sole_top = { 1.0, 1.0, 0.0, 0.8 };
static vec4 sole_bottom = { 1.0, 215.0 / 255.0, 0.0, 1.0 };
static vec4 sole_center = { 1.0, 1.0, 0.0, 0.0 };
static vec4 sole_radius = { 1.0, 215.0 / 255.0, 0.0, 1.0 };

//Colori Luna
static vec4 luna_top = { 1.0, 222.0/255.0, 173.0/255.0, 1.0 };
static vec4 luna_bottom = { 1.0, 250.0 / 255.0, 205 / 255.0, 1.0 };
static vec4 luna_center = { 1.0, 222.0 / 255.0, 173.0 / 255.0, 1.0 };
static vec4 luna_radius = { 1.0, 250.0 / 255.0, 205 / 255.0, 0.5 };

//Colori Seme
static vec4 seme = { 218.0 / 255.0, 165.0 / 255.0, 32.0 / 255.0, 1.0 };

//Colori stelo
static vec4 stelo_top = { 34.0 / 255.0, 139.0 / 255.0, 34.0 / 255.0, 1.0 };
static vec4 stelo_bot = { 0.0, 100.0 / 255.0, 0.0, 1.0 };

static vec4 color_stelo_morto = { 139.0 / 255.0, 69.0 / 255.0, 19.0 / 255.0, 1.0 };

//Colori Fontana
static vec4 fontana_top = { 139.0/255.0, 131.0/255.0, 134.0/255.0, 1.0 };
static vec4 fontana_bot = { 131.0/255.0, 139.0/255.0, 131.0/255.0, 1.0 };

//Colori Fungo
static vec4 fungo_top = { 139.0/255.0, 69.0/255.0, 19.0/255.0, 1.0 };
static vec4 fungo_bot = { 139.0 / 255.0, 69.0 / 255.0, 19.0 / 255.0, 1.0 };

//Colori Petalo
static vec4 fiore_top = {1.0, 1.0, 1.0, 1.0};
static vec4 fiore_bot = { 1.0, 187.0/255.0, 1.0, 1.0 };

static vec4 color_petalo_morto = { 139.0 / 255.0, 87.0 / 255.0, 66.0 / 255.0, 1.0 };

//Colori Pistillo
static vec4 colore_pistillo = { 218.0 / 255.0, 165.0 / 255.0, 32.0 / 255.0, 1.0 };

//Colori Goccia
static vec4 acqua = { 0.0, 191.0 / 255.0, 1.0, 1.0 };

//Colori Diserbante
static vec4 diserbante = { 238.0/255.0, 238.0/255.0, 0.0, 1.0 };

//Colori Testa Omino
static vec4 pelle_omino_giorno = { 1.0, 130.0/255.0, 171.0/255.0, 1.0 };
static vec4 occhio_omino_giorno = { 0.0, 0.0, 0.0, 1.0 };

//Colori Corpo Omino
static vec4 corpo_omino_giorno = { 0.0, 139.0/255.0, 139.0/255.0, 1.0 };

//Colori Gambe Omino 
static vec4 gambe_omino_giorno = { 0.0, 0.0, 0.0, 1.0 };

//Colori Secchio Omino
static vec4 secchio_omino_giorno = { 0.5, 0.5, 0.5, 1.0 };
static vec4 manico_secchio_giorno = { 0.0, 0.0, 0.0, 1.0 };

#endif