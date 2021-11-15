#ifndef COLOR_H
#define COLOR_H

#include "Lib.h"
#include "VAO.h"

vector<vec4> listacolori;

vec4 giorno_cielo_top = { , , , };
vec4 giorno_cielo_bottom = { , , , };

vec4 notte_cielo_top = { , , , };
vec4 notte_cielo_bottom = { , , , };

vec4 giorno_prato_top = { , , , };
vec4 giorno_prato_bottom = { , , , };

vec4 notte_prato_top = { , , , };
vec4 notte_prato_bottom = { , , , };

vec4 acqua = { , , , };
vec4 diserbante = { , , , };

vec4 giorno();

vec4 notte();


#endif
