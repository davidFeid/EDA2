#include <stdio.h>
#include "common.h"

typedef struct{
    char nombre[50];
    int vida;
    int ataque;
    int defensa;
}Enemigo;

void init_enemigo(Enemigo *enemy,  char *nombre, int vida, int ataque, int defensa) ;

void print_enemigo( Enemigo *enemy);

void free_enemigo(Enemigo *enemy);
