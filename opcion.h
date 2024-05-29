#ifndef OPCION_H
#define OPCION_H

#include "common.h"
#include "enemigo.h"

typedef struct {
    char texto_respuesta[TEXTO]; 
    char narracion_antes[TEXTO]; 
    Enemigo **enemigos; // Array de enemigos
    int num_enemigos; 
    char narracion_despues[TEXTO]; 
} Opcion;

void init_opcion(Opcion *opcion, char *texto_respuesta, char *narracion_antes, Enemigo *enemigos[], int num_enemigos, char *narracion_despues);

void print_opcion(Opcion *opcion);

void freeOpcion(Opcion *opcion);

#endif