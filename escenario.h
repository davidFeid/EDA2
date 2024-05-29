#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "common.h"
#include "decision.h"

typedef struct {
    char nombre[NOMBRE]; // Nombre del escenario
    char descripcion[TEXTO]; // Descripción del escenario
    Decision *decision; // Lista de decisiones del escenario
     // Número de decisiones del escenario
} Escenario;

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decision);

void print_escenario(Escenario *escenario);

void free_escenario(Escenario *escenario);

#endif