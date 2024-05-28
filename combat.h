#ifndef COMBATE_H
#define COMBATE_H

#include "enemigo.h"
#include "decision.h"
#include "escenario.h"
#include "habilidad.h"
#include "main.h"
#include "opcion.h"
#include "personaje.h"

void mostrar_habilidades(Habilidad* habilidades_ataque[2], Habilidad* habilidades_defensa[2]);

void ataque_normal_personaje(Personaje* atacante, Enemigo* objetivo);

void habilidad_ataque_personaje(Personaje* atacante, Enemigo* objetivo, int indicehabilidad);

void habilidad_defensa_personaje(Personaje* atacante, Enemigo* objetivo, int indicehabilidad);

void playHumanTurn(Personaje* personaje, Enemigo* enemigo);

void randomHabilidad_enemigo(Personaje* personaje, Enemigo* enemigo);

void ataque_normal_enemigo(Personaje*atacante, Enemigo*objetivo);

void habilidad_ataque_enemigo(Personaje* atacante, Enemigo* objetivo);

void playMachineTurn(Personaje* personaje, Enemigo* enemigo);

void accion_jugador(Personaje* personaje, Enemigo* enemigo);

void accion_enemigo(Enemigo* enemigo,Personaje* personaje);

#endif
