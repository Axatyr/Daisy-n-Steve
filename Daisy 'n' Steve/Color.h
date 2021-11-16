#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Colori cielo
static vec4 giorno_cielo_top = { 0.6471, 0.3020,1.0,1.0 };
static vec4 giorno_cielo_bottom = { 0.0, 0.4980,1.0,1.0 };
static vec4 notte_cielo_top = { 0.0, 0.0, 0.0, 1.0 };
static vec4 notte_cielo_bottom = { 0.0, 0.0, 1.0, 1.0 };

//Colori prato
static vec4 giorno_prato_bottom = { 0.6784, 1.0,0.1843, 1.0000 };
static vec4 giorno_prato_top = { 0.1333, 0.5451, 0.1333, 1.0000 };
static vec4 notte_prato_bottom = { 0.6784, 1.0,0.1843, 1.0000 };
static vec4 notte_prato_top = { 0.0, 0.0, 0.1, 1.0 };

//Colori sole
static vec4 sole_top = { 1.0, 1.0, 0.0, 0.8 };
static vec4 sole_bottom = { 1.0, 215.0 / 255.0, 0.0, 1.0 };
static vec4 sole_center = { 1.0, 1.0, 0.0, 0.0 };
static vec4 sole_radius = { 1.0, 215.0 / 255.0, 0.0, 1.0 };

//Colori Luna
static vec4 luna_top = { 1.0, 248.0 / 255.0, 220.0 / 255.0, 0.8 };
static vec4 luna_bottom = { 1.0, 250.0 / 255.0, 205.0 / 255.0, 1.0 };
static vec4 luna_center = { 1.0, 248.0 / 255.0, 220.0 / 255.0, 0.0 };
static vec4 luna_radius = { 1.0, 250.0 / 255.0, 205.0 / 255.0, 1.0 };



#endif
