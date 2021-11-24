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
void keyboardReleasedEvent(unsigned char key, int x, int y);
void mouseEvent(int button, int state, int x, int y);
void update(int a);
void giorno_notte();
void setScena(Elementi* scena, GLuint matmodel);
Elementi* getScena();

void moveRight();
void moveLeft();
void jump();
#endif