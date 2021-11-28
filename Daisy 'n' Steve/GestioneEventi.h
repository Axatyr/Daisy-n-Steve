#ifndef GESTIONEEVENTI_H
#define GESTIONEEVENTI_H

#include "Lib.h"
#include "Elementi.h"
#include "VAO.h"
#include "Color.h"

// Gestione input tastiera
void keyboardPressedEvent(unsigned char key, int x, int y);
void update(int a);

// Gestione giorno/notte
void giorno_notte();

// Gestione omino
void moveRight();
void moveLeft();
void jump(int value);

// Gestione del fiore
void crea_stelo(); 
void crea_fiore();
void muore_fiore(); 

//Gestione secchio
void riempi(); 
void svuota();  
void updateGoccia(int value);

//Gestione fungo
void crea_fungo(); 
void distruggi_fungo(); 

#endif