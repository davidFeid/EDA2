#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "common.h"
#include "habilidad.h"
typedef struct{
    char nombre[NOMBRE];
    int vida;
    int ataque;
    int defensa;
    Habilidad *habilidad; 
} Enemigo;

void init_enemigo(Enemigo *enemigo,  char *nombre, int vida, int ataque, int defensa,Habilidad *habilidad) ;

/* void aplicar_habilidad(Enemigo *enemigo, Habilidad *habilidad); */

void print_enemigo( Enemigo *enemigo);

void free_enemigo(Enemigo *enemigo);

#endif