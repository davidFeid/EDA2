#ifndef COMBATE_H
#define COMBATE_H

#include "personaje.h"
#include "enemigo.h"
#include "opcion.h"
#include "decision.h"
#include "escenario.h"
#include "common.h"
#include "habilidad.h"
#include "turno.h"
#include <time.h>
#include <stdlib.h>

void mostrar_habilidades(Habilidad* habilidades_ataque[2], Habilidad* habilidades_defensa[2]);

void ataque_normal_personaje(Personaje* atacante, Enemigo* objetivo);

void habilidad_ataque_personaje(Personaje* atacante, Enemigo* objetivo);

void habilidad_defensa_personaje(Personaje* atacante, Enemigo* objetivo, int i);

void playHumanTurn(Personaje* personaje, Enemigo* enemigo);

void randomHabilidad_enemigo(Personaje* personaje, Enemigo* enemigo);

void ataque_normal_enemigo(Personaje*atacante, Enemigo*objetivo);

//void habilidad_ataque_enemigo(Personaje* atacante, Enemigo* objetivo);

void playMachineTurn(Personaje* personaje, Enemigo* enemigo);

#endif