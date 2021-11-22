#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Colori Cielo
static vec4 giorno_cielo_top = { 0.6471, 0.3020,1.0,1.0 };
static vec4 giorno_cielo_bottom = { 0.0, 0.4980,1.0,1.0 };
static vec4 notte_cielo_top = { 0.0, 0.0, 0.0, 1.0 };
static vec4 notte_cielo_bottom = { 0.0, 0.0, 1.0, 1.0 };

//Colori Prato
static vec4 giorno_prato_bottom = { 0.6784, 1.0,0.1843, 1.0000 };
static vec4 giorno_prato_top = { 0.1333, 0.5451, 0.1333, 1.0000 };
static vec4 notte_prato_bottom = { 0.6784, 1.0,0.1843, 1.0000 };
static vec4 notte_prato_top = { 0.0, 0.0, 0.1, 1.0 };

//Colori Sole
static vec4 sole_top = { 1.0, 1.0, 0.0, 0.8 };
static vec4 sole_bottom = { 1.0, 215.0 / 255.0, 0.0, 1.0 };
static vec4 sole_center = { 1.0, 1.0, 0.0, 0.0 };
static vec4 sole_radius = { 1.0, 215.0 / 255.0, 0.0, 1.0 };

//Colori Luna
static vec4 luna_top = { 0.96,  0.96, 0.96, 0.8 };
static vec4 luna_bottom = { 0.94, 1.0, 1.0, 1.0 };
static vec4 luna_center = { 0.0,  0.96, 0.96, 0.0 };
static vec4 luna_radius = { 0.94, 0.0, 1.0, 1.0 };

//Colori Seme
static vec4 seme = { 218.0 / 255.0, 165.0 / 255.0, 32.0 / 255.0, 1.0 };

//Colori Erbaccia
static vec4 stelo_top = { 34.0 / 255.0, 139.0 / 255.0, 34.0 / 255.0, 1.0 };
static vec4 stelo_bot = { 0.0, 100.0 / 255.0, 0.0, 1.0 };

//Colori Erbaccia
static vec4 fiore_top = { 1.0, 1.0, 1.0, 1.0 };
static vec4 fiore_bot = { 1.0, 1.0, 1.0, 1.0 };

//Colori Fontana
static vec4 fontana_top = { 245.0 / 255.0,  245.0 / 255.0, 245.0 / 255.0, 1.0 };
static vec4 fontana_bot = { 240.0 / 255.0, 1.0, 1.0, 1.0 };

//Colori Fungo
static vec4 fungo_top = { 1.0, 0.0, 0.0, 1.0 };
static vec4 fungo_bot = { 1.0, 0.0, 0.0, 1.0 };

//Colori Goccia
static vec4 acqua = { 0.0, 128.0 / 255.0, 1.0, 1.0 };

//Colori Diserbante
static vec4 diserbante = { 1.0, 1.0, 0.0, 1.0 };

//Colori Testa Omino
static vec4 testa_omino_giorno = { 1.0, 0.0, 0.5, 1.0 };


#endif
