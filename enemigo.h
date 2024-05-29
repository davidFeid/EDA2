#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "common.h"
#include "habilidad.h"
typedef struct{
    char nombre[NOMBRE];
    int vida;
    int ataque;
    int defensa;
    Habilidad **habilidades; // Array de habilidades
    int num_habilidades;

} Enemigo;

void init_enemigo(Enemigo *enemigo,  char *nombre, int vida, int ataque, int defensa,Habilidad *habilidades[],int num_habilidades) ;


void print_enemigo( Enemigo *enemigo);

void free_enemigo(Enemigo *enemigo);

#endif