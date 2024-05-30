#ifndef DECISION_H
#define DECISION_H

#include "common.h"
#include "opcion.h"
#include "enemigo.h"

typedef struct {
    char texto_pregunta[TEXTO]; // Texto de la pregunta para el jugador
    Opcion **opciones; // Array de opciones
    int num_opciones; // Número de opciones
} Decision;

void init_decision(Decision *decision, char *texto_pregunta, Opcion *opciones[], int num_opciones);

void print_decision(Decision *decision);

void free_decision(Decision *decision);

#endif