#ifndef TURNO_H
#define TURNO_H

#include "common.h"

// Tipo de turno: jugador o enemigo
typedef enum {
    JUGADOR,
    ENEMIGO
} TipoTurno;

// Estructura para representar un nodo en la cola
typedef struct Turno {
    TipoTurno tipo;
    struct Turno *siguiente;
} Turno;

// Estructura para representar la cola de turnos
typedef struct {
    Turno *frente;
    Turno *final;
    int size;
} ColaTurnos;

// Funciones para manejar la cola de turnos
void init_cola_turnos(ColaTurnos *cola);

bool is_empty(ColaTurnos *cola);

void encolar_turno(ColaTurnos *cola, TipoTurno tipo);

TipoTurno desencolar_turno(ColaTurnos *cola);

void liberar_cola_turnos(ColaTurnos *cola);

#endif
