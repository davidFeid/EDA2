#ifndef OPCION_H
#define OPCION_H

#include "common.h"
#include "enemigo.h"

typedef struct {
    char texto_respuesta[100]; // Texto de respuesta del jugador
    char narracion_antes[200]; // Texto de narración antes de enfrentarse a los enemigos
    Enemigo *enemigos; // Array de enemigos
    int num_enemigos; // Número de enemigos
    char narracion_despues[200]; // Texto de narración después de enfrentarse a los enemigos
} Opcion;

void init_opcion(Opcion *opcion, char *texto_respuesta, char *narracion_antes, Enemigo *enemigos, int num_enemigos, char *narracion_despues);

void print_opcion(Opcion *opcion);

void freeOpcion(Opcion *opcion);

#endif