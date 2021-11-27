#ifndef GESTIONEEVENTI_H
#define GESTIONEEVENTI_H

#include "Lib.h"
#include "Elementi.h"
#include "VAO.h"
#include "Color.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

void keyboardPressedEvent(unsigned char key, int x, int y);
void update(int a);

//Gestione scena
void giorno_notte();

// Gestione omino
void moveRight();
void moveLeft();
void jump(int value); //da sistemare

// Gestione del fiore
void crea_stelo(); // crea stelo
void crea_fiore(); // crea pistillo e petalo
void muore_fiore(); // cambia colori

//Gestione secchio
void riempi();  // appoggia il secchio a terra e lo riprende in automatico, l'omino non si sposta
void svuota();  // proviamo a ruotarlo, se non funziona niente
void updateGoccia(int value);

//Gestione fungo
void crea_fungo(); // dentro riempi
void distruggi_fungo(); // dentro jump


#endif