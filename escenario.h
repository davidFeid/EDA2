#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "common.h"
#include "decision.h"

typedef struct {
    char nombre[100]; // Nombre del escenario
    char descripcion[200]; // Descripción del escenario
    Decision *decisiones; // Lista de decisiones del escenario
    int num_decisiones; // Número de decisiones del escenario
} Escenario;

void init_escenario(Escenario *escenario, char *nombre, char *descripcion, Decision *decisiones, int num_decisiones);

void print_escenario(Escenario *escenario);

void free_escenario(Escenario *escenario);

#endif