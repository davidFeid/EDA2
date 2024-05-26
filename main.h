// main.h
#ifndef MAIN_H
#define MAIN_H

#include "personaje.h"
#include "enemigo.h"
#include "opcion.h"
#include "decision.h"
#include "escenario.h"
#include "common.h"
#include "habilidad.h"
#include "turno.h"
#include "combat.h"

void inicializar_habilidades();
void inicializar_enemigos(Habilidad *habilidades[][4]);
void inicializar_opcion(Enemigo *enemigos[][2]);
void inicializar_decision(Opcion *opciones[][3]);
void inicializar_escenario(Decision *deciones[]);
void inicializar_turnos(ColaTurnos *cola);
void accion_jugador(Personaje* personaje, Enemigo* enemigo);

#endif // MAIN_H
