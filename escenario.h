#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "common.h"
#include "decision.h"

typedef struct {
    char nombre[NOMBRE]; 
    char descripcion[TEXTO]; 
    Decision *decision; // Decisión del escenario
     
} Escenario;

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decision);

void print_escenario(Escenario *escenario);

void free_escenario(Escenario *escenario);

#endif