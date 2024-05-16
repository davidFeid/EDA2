#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "common.h"

typedef struct{
    char nombre[NOMBRE];
    int vida;
    int ataque;
    int defensa;
} Enemigo;

void init_enemigo(Enemigo *enemigo,  char *nombre, int vida, int ataque, int defensa) ;

void print_enemigo( Enemigo *enemigo);

void free_enemigo(Enemigo *enemigo);

#endif