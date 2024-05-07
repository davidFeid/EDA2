#include <stdio.h>
#include "common.h"

typedef struct{
    char nombre[50] ;
    int vida;
    int ataque;
    int defensa;
    char habilidades[4][50];
}Protagonista;

void init_prota(Protagonista *prota,  char *nombre, int vida, int ataque, int defensa,  char habilidades[4][50]);
void print_prota(Protagonista *prota);
void free_protagonista(Protagonista *prota);