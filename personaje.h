#include <stdio.h>
#include "common.h"

typedef struct{
    char nombre[50] ;
    int vida;
    int ataque;
    int defensa;
    char habilidades[4][50];
}Personaje;

void init_personaje(Personaje *personaje);
void print_personaje(Personaje *personaje);
void free_personaje(Personaje *personaje);