#ifndef DECISION_H
#define DECISION_H

#include "common.h"
#include "opcion.h"
#include "enemigo.h"

typedef struct {
    char texto_pregunta[TEXTO]; 
    Opcion **opciones; // Array de opciones
    int num_opciones; 
} Decision;

void init_decision(Decision *decision, char *texto_pregunta, Opcion *opciones[], int num_opciones);

void print_decision(Decision *decision);

void free_decision(Decision *decision);

#endif