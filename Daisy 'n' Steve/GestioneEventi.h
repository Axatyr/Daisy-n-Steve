#ifndef GESTIONEEVENTI_H
#define GESTIONEEVENTI_H

#include "Lib.h"
#include "Elementi.h"
#include "VAO.h"

void keyboardPressedEvent(unsigned char key, int x, int y);
void keyboardReleasedEvent(unsigned char key, int x, int y);
void mouseEvent(int button, int state, int x, int y);
void update(int a);
void colore_cielo();
void setScena(Elementi* scena);

#endif