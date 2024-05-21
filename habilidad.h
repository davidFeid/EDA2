#ifndef HABILIDAD_H
#define HABILIDAD_H

#include "common.h"

typedef struct  {
    char nombre[NOMBRE];
    char descripcion[TEXTO];
    int modificadorAtaque;
    int modificadorDefensa;
    int modificadorHP;
} Habilidad;

//Funciones

void init_habilidad(Habilidad *habilidad){
                    char *nombre,
                    char *descripcion,
                    int modificadorAtaque,
                    int modificadorDefensa,
                    int modificadorHP,
}
void printHabilidad(Habilidad *habilidad);

void freeHabilidad(Habilidad *habilidad);

#endif