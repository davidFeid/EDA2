#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include "personaje.h"
#include "enemigo.h"
#include "common.h"
#include "habilidad.h"

typedef struct Movimiento {
    char nombre[50];
    struct Movimiento* siguiente;
} Movimiento;



void push(Movimiento** cima, char* nombre);
char* pop(Movimiento** cima);
char* obtener_movimiento_aleatorio(Movimiento* cima, int k);
int obtener_tamano_pila(Movimiento* cima);


void golpe_de_tiempo(Movimiento* historial, Personaje* atacante, Enemigo* objetivo);


#endif
