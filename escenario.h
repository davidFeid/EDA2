#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "common.h"
#include "decision.h"
#include "combat.h"
#include "movimiento.h"

typedef struct {
    char nombre[NOMBRE]; // Nombre del escenario
    char descripcion[TEXTO]; // Descripción del escenario
    Decision **decisiones; // Lista de decisiones del escenario
    int num_decisiones; // Número de decisiones del escenario
} Escenario;

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decisiones[], int num_decisiones);

void print_escenario(Escenario *escenario);

void free_escenario(Escenario *escenario);

void jugar_escenario(Personaje* personaje, Escenario *escenario,Movimiento** historial);

#endif